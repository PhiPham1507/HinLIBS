#include "librarianwindow.h"
#include "ui_librarianwindow.h"
#include <QMessageBox>
void hideWhenDefault();
void refreshCatalogueContents();

LibrarianWindow::LibrarianWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LibrarianWindow)
{
    selectedItemIndex = -1;
    ui->setupUi(this);
    QObject::connect(ui->signoutButton,
                         &QPushButton::clicked,
                         this,
                         &LibrarianWindow::signOutRequest);
    ui->stackedWidget->hide();
    ui->chooseItem->setCurrentIndex(0);
    hideWhenDefault();
    QObject::connect(ui->addItemButton, &QPushButton::clicked, this, [this](){
        if(ui->stackedWidget->isHidden()) ui->stackedWidget->show();
        ui->stackedWidget->setCurrentIndex(0);
    });
    QObject::connect(ui->chooseItem, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &LibrarianWindow::chooseAccordingForm);

    QObject::connect(ui->removeItemButton, &QPushButton::clicked, this, [this](){
        if(ui->stackedWidget->isHidden()) ui->stackedWidget->show();
        ui->stackedWidget->setCurrentIndex(1);
        ui->removeItemButton_2->setEnabled(false);
        refreshCatalogueContents();

    });

    QObject::connect(ui->catalogueDisplay, &QListWidget::itemClicked, this, [this](QListWidgetItem* item){
        selectedItemIndex = item->data(Qt::UserRole).toInt();
        if(controller->getItemAvailability(selectedItemIndex)){
            ui->removeItemButton_2->setEnabled(true);
        }else{
            ui->removeItemButton_2->setEnabled(false);
        }
    });

    QObject::connect(ui->removeItemButton_2, &QPushButton::clicked, this, &LibrarianWindow::removeItem);

    QObject::connect(ui->pReturnButton, &QPushButton::clicked, this, &LibrarianWindow::showReturnForPatron);

}

LibrarianWindow::~LibrarianWindow()
{
    delete ui;
}

void LibrarianWindow::signOutRequest(){
    emit signOut();
}
void LibrarianWindow::clearInputs(){
    ui->authorInput->clear();
    ui->publicationInput->clear();
    ui->isbnInput->clear();
    ui->dayPubInput->clear();
    ui->monthPubInput->clear();
    ui->yearPubInput->clear();
    ui->genreInput->clear();
    ui->ratingInput->clear();
    ui->dewyInput->clear();
    ui->issueInput->clear();
}

void LibrarianWindow::chooseAccordingForm(int index){
    if(index == 0){
        hideWhenDefault();
        clearInputs();

    }else if(index == 1){
        hideWhenDefault();
        showWhenChosen();

    }else if(index == 2){
        hideWhenDefault();
        showWhenChosen();
        ui->itemFormsWidget->show();
        ui->itemFormsWidget->setCurrentIndex(2);

    }else if(index == 5){
        hideWhenDefault();
        showWhenChosen();
        ui->itemFormsWidget->show();
        ui->itemFormsWidget->setCurrentIndex(1);


    }else{
        hideWhenDefault();
        showWhenChosen();
        ui->itemFormsWidget->show();
        ui->itemFormsWidget->setCurrentIndex(0);
    }

}

void LibrarianWindow::setname(const QString &user){

    ui->userOutput->setText(user);
}
void LibrarianWindow::refreshCatalogueContents(){
    ui->catalogueDisplay->clear();  // Delete old entries automatically

    vector<Item*> items = controller->getItems();

    for (int i = 0; i < (int)items.size(); ++i)
    {
        Item* item = items[i];

        // Create a new QListWidgetItem
        QListWidgetItem* entry = new QListWidgetItem(
            QString::fromStdString(item->display()),
            ui->catalogueDisplay
        );

        // Store the index or ID inside the item
        entry->setData(Qt::UserRole, item->getId());
    }
}
void LibrarianWindow::removeItem(){
    controller->removeItem(selectedItemIndex);
    QMessageBox::information(this, "Success Checkout", "Successfully checked out the item");
    refreshCatalogueContents();
    selectedItemIndex = -1;
    ui->removeItemButton_2->setEnabled(false);
}
void LibrarianWindow::hideWhenDefault(){
    ui->itemFormsWidget->hide();
    ui->authorInput->hide();
    ui->authorLabel->hide();
    ui->isbnInput->hide();
    ui->isbnLabel->hide();
    ui->publicationInput->hide();
    ui->publicationLabel->hide();
    ui->addButton->hide();

}

void LibrarianWindow::showWhenChosen(){
    ui->authorInput->show();
    ui->authorLabel->show();
    ui->isbnInput->show();
    ui->isbnLabel->show();
    ui->publicationInput->show();
    ui->publicationLabel->show();
    ui->addButton->show();

}
void LibrarianWindow::setController(DataController *con){
    controller = con;
}

void LibrarianWindow::showReturnForPatron()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void LibrarianWindow::searchForPatronButtonClicked()
{
    QString input = ui->PatronSearchField->text();
    currentPatronTarget = controller->getPatronByName(input.toStdString());
    if (currentPatronTarget == nullptr) {
        return;
    }
    displayPatronTargetLoans();
}

void LibrarianWindow::displayPatronTargetLoans()
{
    ui->LoansList->clear();  // Delete old entries automatically

    if (currentPatronTarget == nullptr) return;

    vector<Loan> loans = currentPatronTarget->getLoans();

    for (int i = 0; i < (int)loans.size(); ++i)
    {
        Item* item = loans[i].getItem();

        // Create a new QListWidgetItem
        QListWidgetItem* entry = new QListWidgetItem(
            QString::fromStdString(item->display()),
            ui->LoansList
        );

        // Store the index or ID inside the item
        entry->setData(Qt::UserRole, item->getId());
    }
}

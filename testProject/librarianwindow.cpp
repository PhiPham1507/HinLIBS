#include "librarianwindow.h"
#include "ui_librarianwindow.h"
#include <QMessageBox>
#include <iostream>
#include <QDebug>
void hideWhenDefault();
void refreshCatalogueContents();

LibrarianWindow::LibrarianWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LibrarianWindow)
{
    selectedItemIndex = -1;
    selectedPatronReturnId = -1;
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
        if(controller->getItemAvailability(selectedItemIndex && controller->getItemById(selectedItemIndex)->noHolds())){
            ui->removeItemButton_2->setEnabled(true);
        }else{
            ui->removeItemButton_2->setEnabled(false);
        }
    });

    QObject::connect(ui->removeItemButton_2, &QPushButton::clicked, this, &LibrarianWindow::removeItem);
    QObject::connect(ui->addButton, &QPushButton::clicked, this, &LibrarianWindow::addItem);


    QObject::connect(ui->pReturnButton, &QPushButton::clicked, this, &LibrarianWindow::showReturnForPatron);
    QObject::connect(ui->SearchPatronButton, &QPushButton::clicked, this, &LibrarianWindow::searchForPatronButtonClicked);
    QObject::connect(ui->ReturnSelectedItem, &QPushButton::clicked, this, &LibrarianWindow::returnForPatronClicked);

    QObject::connect(ui->LoansList, &QListWidget::itemClicked, this, [this](QListWidgetItem* item){
        selectedPatronReturnId = item->data(Qt::UserRole).toInt();
    });

}

LibrarianWindow::~LibrarianWindow()
{
    delete ui;
}
void LibrarianWindow::addItem(){
    bool pass;
    const string& title = ui->titleInput->text().toStdString();
    const string& author = ui->authorInput->text().toStdString();
    long isbn = ui->isbnInput->text().toLong(&pass);
    if(!pass){
        isbn = 0;
    }
    int pub = ui->publicationInput->text().toInt(&pass);
    if(!pass){
        QMessageBox::information(this, "Invalid Input", "Failed on adding item");
        ui->chooseItem->setCurrentIndex(0);
        clearInputs();
        return;
    }
    if(title == "" || author == ""){
        QMessageBox::information(this, "Invalid Input", "Failed on adding item");
        ui->chooseItem->setCurrentIndex(0);
        clearInputs();
        return;
    }
    int index = ui->chooseItem->currentIndex();
    string type;
    string dewy;
    string genre;
    int rating = 0;
    int issueNumber = 0;
    string pubDate;


    switch (index){
    case 1:
        type = "fiction";
        break;
    case 2:
        type = "nonfiction";
        dewy = ui->dewyInput->text().toStdString();
        if(dewy == ""){
            QMessageBox::information(this, "Invalid Input", "Failed on adding item");
            ui->chooseItem->setCurrentIndex(0);
            clearInputs();
            return;
        }
        break;
    case 3:
        type = "videogame";
        genre = ui->genreInput->text().toStdString();
        if(genre == ""){
            QMessageBox::information(this, "Invalid Input", "Failed on adding item");
            ui->chooseItem->setCurrentIndex(0);
            clearInputs();
            return;
        }
        rating = ui->ratingInput->text().toInt(&pass);
        if(!pass) rating = -1;
        break;
    case 4:
        type = "movie";
        genre = ui->genreInput->text().toStdString();
        if(genre == ""){
            QMessageBox::information(this, "Invalid Input", "Failed on adding item");
            ui->chooseItem->setCurrentIndex(0);
            clearInputs();
            return;
        }
        rating = ui->ratingInput->text().toInt(&pass);
        if(!pass) rating = -1;
        break;
    case 5:
        bool day, month, year;
        type = "magazine";
        issueNumber = ui->issueInput->text().toInt(&pass);
        int dayI = ui->dayPubInput->text().toInt(&day);
        int monthI = ui->monthPubInput->text().toInt(&month);
        int yearI = ui->yearPubInput->text().toInt(&year);
        if(!pass || !day || !month || !year){
            QMessageBox::information(this, "Invalid Input", "Failed on adding item");
            ui->chooseItem->setCurrentIndex(0);
            clearInputs();
            return;
        }
        bool valid = controller->validateDate(yearI, monthI, dayI);
        if(!valid){
            QMessageBox::information(this, "Invalid Input", "Failed on adding item");
            ui->chooseItem->setCurrentIndex(0);
            clearInputs();
            return;
        }
        pubDate = (QString("%1-%2-%3")
                .arg(ui->yearPubInput->text())
                .arg(ui->monthPubInput->text())
                .arg(ui->dayPubInput->text())).toStdString();
        cout << pubDate << endl;
        break;
    }

    controller->addItem(title, author, pub, isbn, type, dewy, issueNumber, pubDate, genre, rating);
    QMessageBox::information(this, "Success Adding Item", "Successfully added the item");

    ui->chooseItem->setCurrentIndex(0);
    clearInputs();
}
void LibrarianWindow::signOutRequest(){
    emit signOut();
}
void LibrarianWindow::clearInputs(){
    ui->titleInput->clear();
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
    refreshCatalogueContents();
    controller->removeItem(selectedItemIndex);
    QMessageBox::information(this, "Success Removal", "Successfully removed the item");
    refreshCatalogueContents();
    selectedItemIndex = -1;
    ui->removeItemButton_2->setEnabled(false);
}
void LibrarianWindow::hideWhenDefault(){
    ui->itemFormsWidget->hide();
    ui->titleLabel->hide();
    ui->titleInput->hide();
    ui->authorInput->hide();
    ui->authorLabel->hide();
    ui->isbnInput->hide();
    ui->isbnLabel->hide();
    ui->publicationInput->hide();
    ui->publicationLabel->hide();
    ui->addButton->hide();

}

void LibrarianWindow::showWhenChosen(){
    ui->titleLabel->show();
    ui->titleInput->show();
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

    refreshPatronTargetLoans();
}

void LibrarianWindow::returnForPatronClicked()
{
    if (currentPatronTarget == nullptr)
    {
        QMessageBox::information(this, "Error", "Unknown target patron");
        return;
    }
    else if (selectedPatronReturnId == -1)
    {
        QMessageBox::information(this, "Error", "No selected item");
        return;
    }

    controller->setPatron(currentPatronTarget);
    controller->checkIn(selectedPatronReturnId);
    controller->setPatron(nullptr);

    QMessageBox::information(this, "Success Returned", "Successfully return the item");
    refreshPatronTargetLoans();
}

void LibrarianWindow::refreshPatronTargetLoans()
{

    ui->LoansList->clear();  // Delete old entries automatically
    
    if (currentPatronTarget == nullptr) {
        QMessageBox::information(this, "Error", "Unknown target patron");
        ui->ReturnSelectedItem->setEnabled(false);
        return;
    }

    selectedPatronReturnId = -1;

    

    vector<Loan> loans = currentPatronTarget->getLoans();

    qDebug() << loans.size();

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

    ui->ReturnSelectedItem->setEnabled(true);
}

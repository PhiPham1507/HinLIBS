#include "patronwindow.h"
#include "ui_patronwindow.h"

#include "QString"
#include <QMessageBox>


PatronWindow::PatronWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PatronWindow)
{

    selectedIndex = -1;

    ui->setupUi(this);
    QObject::connect(ui->signoutButton,
                         &QPushButton::clicked,
                         this,
                         &PatronWindow::signOutRequest);
                         
    QObject::connect(ui->viewAccButton,
                         &QPushButton::clicked,
                         this,
                         &PatronWindow::viewAccountButtonSelected
    );
    
    QObject::connect(ui->catalogButton,
                         &QPushButton::clicked,
                         this,
                         &PatronWindow::catalogueButtonSelected

    );
    QObject::connect(ui->checkoutButton,
                         &QPushButton::clicked,
                         this,
                         &PatronWindow::checkOut

    );
    QObject::connect(ui->choldButton,
                         &QPushButton::clicked,
                         this,
                         &PatronWindow::placeHold

    );

    QObject::connect(ui->infoButton,
                         &QPushButton::clicked,
                         this,
                     [&](){
        ui->smallWidget->setCurrentIndex(0);

    });

    QObject::connect(ui->loanButton,
                         &QPushButton::clicked,
                         this,
                     [&](){
        ui->smallWidget->setCurrentIndex(1);

    });

    QObject::connect(ui->holdButton,
                         &QPushButton::clicked,
                         this,
                     [&](){
        ui->smallWidget->setCurrentIndex(2);

    });

    QObject::connect(ui->checkoutButton, &QPushButton::clicked, this, &PatronWindow::checkOut);

}

PatronWindow::~PatronWindow()
{
    delete ui;
}
void PatronWindow::setname(const QString &user){
    ui->userOutput->setText(user);
}


void PatronWindow::setController(DataController *dc){
    controller = dc;
}


void PatronWindow::signOutRequest(){
    emit signOut();
}

void PatronWindow::checkOut(){

    int id = catalogueEntryIds[selectedIndex];
    if (id == -1) return;

    bool success = controller->checkOut(id);

    if(success){
        QMessageBox::information(this, "Success Checkout", "Successfully check out the item");
    }else{
        QMessageBox::information(this, "Failed Checkout", "Failed to check out the item");
    }
}




void PatronWindow::viewAccountButtonSelected()

{

    ui->bigWidget->setCurrentIndex(1);

    // refresh the account status page
    PatronDetails patDetails = controller->getPatronDetails();

    ui->usernameLabel->setText(QString::fromStdString(patDetails.username));
    ui->accountTypeLabel->setText("PATRON"); // should always display patron

    QString loansText;
    QString holdsText;

    int size = patDetails.loans.size();
    for (int i = 0; i < size; ++i)
    {
        loansText.append(QString::fromStdString(patDetails.loans[i].display()) + "\n");
    }

    size = patDetails.holds.size();
    for (int i = 0; i < size; ++i)
    {
        holdsText.append(QString::fromStdString(patDetails.holds[i]->display()) + "\n");
    }

    ui->loansLabel->setText(loansText);
    ui->holdsLabel->setText(holdsText);

}



void PatronWindow::catalogueButtonSelected()
{
    ui->bigWidget->setCurrentIndex(2);
    refreshCatalogueContents();
}

QPushButton* PatronWindow::addEntryToCatalogue(const QString& text)
{
    QPushButton* newButton = new QPushButton(text, this);
//    newButton->setText(text);
    ui->scrollAreaWidgetContents->layout()->addWidget(newButton);
    return newButton;
}


void PatronWindow::refreshCatalogueContents()
{
    for (int i = 0; i < (int)catalogueEntries.size(); ++i)
    {
        delete catalogueEntries[i];
    }
    catalogueEntries.clear();
    catalogueEntryIds.clear();

    vector<Item*> items = controller->getItems();
    for (int i = 0; i < (int)items.size(); ++i)
    {
        QPushButton* newButton = addEntryToCatalogue(QString::fromStdString(items[i]->display()));
        catalogueEntries.push_back(newButton);
        catalogueEntryIds.push_back(items[i]->getId());

        // surely this causes a memory leak, right?
        connect(catalogueEntries[i],  &QPushButton::clicked, this, [&]() {
            selectedIndex = i;
        });
    }
}

void PatronWindow::placeHold(){

    int id = catalogueEntryIds[selectedIndex];
    if (id == -1) return;

    bool success = false;
    int index = controller->placeHold(id, &success);
    if(success){
        QString display = QString("Successfully placed hold on the item. Your queue position is: %1").arg(index);
        QMessageBox::information(this, "Place Hold Succeed", display);
    }else{
        QMessageBox::information(this, "Place Hold Failed", "Failed to place hold on the item");
    }
}

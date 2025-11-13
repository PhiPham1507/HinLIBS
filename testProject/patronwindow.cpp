#include "patronwindow.h"
#include "ui_patronwindow.h"
#include "QMessageBox"
#include "QString"
#include <QMessageBox>
PatronWindow::PatronWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PatronWindow)
{
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



//    addEntryToCatalogue("1");
//    addEntryToCatalogue("2");
//    addEntryToCatalogue("3");
//    addEntryToCatalogue("4");
//    addEntryToCatalogue("5");
//    addEntryToCatalogue("6");
//    addEntryToCatalogue("7");
//    addEntryToCatalogue("8");
//    addEntryToCatalogue("9");
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
    const string item;
    // Retrieve string from GUI. such that: item = ...

    bool success = controller->checkOut(item);

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

    ui->accountTypeLabel->setText("PATRON");

}



void PatronWindow::catalogueButtonSelected()
{
    ui->bigWidget->setCurrentIndex(2);
    refreshCatalogueContents();
}

void PatronWindow::addEntryToCatalogue(const QString& name)
{
    QPushButton *newButton = new QPushButton(name, this);
    ui->scrollAreaWidgetContents->layout()->addWidget(newButton);

}


void PatronWindow::refreshCatalogueContents()
{

}

void PatronWindow::placeHold(){
    const string item;
    //Retrieve string from GUI. such that: item = ...
    bool success = false;
    int index = controller->placeHold(item, &success);
    if(success){
        QString display = QString("Successfully placed hold on the item. Your queue position is: %1").arg(index);
        QMessageBox::information(this, "Place Hold Succeed", display);
    }else{
        QMessageBox::information(this, "Place Hold Failed", "Failed to place hold on the item");
    }
}

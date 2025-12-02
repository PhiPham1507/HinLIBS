#include "patronwindow.h"
#include "ui_patronwindow.h"
#include <iostream>

#include "QString"
#include <QMessageBox>


PatronWindow::PatronWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PatronWindow)
{

    selectedItemIndex = -1;
    selectedLoanIndex = -1;
    selectedHoldIndex = -1;

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

    QObject::connect(ui->pholdButton,
                         &QPushButton::clicked,
                         this,
                         &PatronWindow::placeHold

    );




    QObject::connect(ui->checkoutButton, &QPushButton::clicked, this, &PatronWindow::checkOut);
    QObject::connect(ui->returnButton, &QPushButton::clicked, this, &PatronWindow::checkIn);
    QObject::connect(ui->choldButton, &QPushButton::clicked, this, &PatronWindow::cancelHold);


    QObject::connect(ui->catalogueList, &QListWidget::itemClicked, this, [this](QListWidgetItem* item){
        selectedItemIndex = item->data(Qt::UserRole).toInt();
    });
    QObject::connect(ui->holdList, &QListWidget::itemClicked, this, [this](QListWidgetItem* item){
        selectedHoldIndex = item->data(Qt::UserRole).toInt();
    });
    QObject::connect(ui->loanList, &QListWidget::itemClicked, this, [this](QListWidgetItem* item){
        selectedLoanIndex = item->data(Qt::UserRole).toInt();
    });
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

    if(selectedItemIndex == -1){
        QMessageBox::information(this, "No Item Selected", "Choose an item to checkout");
        return;
    }

    bool success = controller->checkOut(selectedItemIndex);

    if(success){
        QMessageBox::information(this, "Success Checkout", "Successfully checked out the item");
    }else{
        QMessageBox::information(this, "Failed Checkout", "Failed to check out the item");
    }
    refreshCatalogueContents();
    selectedItemIndex = -1;

}


void PatronWindow::catalogueButtonSelected()
{
    ui->bigWidget->setCurrentIndex(2);
    refreshCatalogueContents();
}



void PatronWindow::refreshCatalogueContents()
{
    ui->catalogueList->clear();  // Delete old entries automatically

    vector<Item*> items = controller->getItems();

    for (int i = 0; i < (int)items.size(); ++i)
    {
        Item* item = items[i];

        // Create a new QListWidgetItem
        QListWidgetItem* entry = new QListWidgetItem(
            QString::fromStdString(item->display()),
            ui->catalogueList
        );

        // Store the index or ID inside the item
        entry->setData(Qt::UserRole, item->getId());
    }
}

void PatronWindow::placeHold(){

    if (selectedItemIndex == -1){
        QMessageBox::information(this, "No Item Selected", "Choose an item to place hold on");
        return;
    }
    bool success = true;
    int index = controller->placeHold(selectedItemIndex);
    if(success){
        QString display = QString("Successfully placed hold on the item. Your queue position is: %1").arg(index);
        QMessageBox::information(this, "Place Hold Succeed", display);
    }else{
        QMessageBox::information(this, "Place Hold Failed", "Failed to place hold on the item");
    }
    ui->catalogueList->clearSelection();
}

void PatronWindow::viewAccountButtonSelected(){
    ui->bigWidget->setCurrentIndex(1);
    refreshAccountContents();

}
void PatronWindow::refreshAccountContents(){
    ui->loanList->clear();
    ui->holdList->clear();
    vector<Loan> loans = controller->getCurrentAccount()->getLoans();
    vector<Item*> holds = controller->getCurrentAccount()->getHolds();

    for(int i = 0; i < (int)loans.size(); i++){
        Loan &l = loans[i];
        QListWidgetItem* entry = new QListWidgetItem(QString::fromStdString(l.display()), ui->loanList);
        entry->setData(Qt::UserRole, l.getItem()->getId());

    }

    for(int i = 0; i < (int)holds.size(); i++){
        Item* item = holds[i];

        QListWidgetItem* entry;
        if(item->getAvailability())
            entry = new QListWidgetItem(QString::fromStdString(item->getTitle() + "    Queue Position # " + std::to_string(item->findIndex(controller->getCurrentAccount()) -1)+ " - Available!"), ui->holdList);
        else
            entry = new QListWidgetItem(QString::fromStdString(item->getTitle() + "    Queue Position # " + std::to_string(item->findIndex(controller->getCurrentAccount()))), ui->holdList);
        entry->setData(Qt::UserRole, item->getId());
    }
}

void PatronWindow::checkIn(){
    if(selectedLoanIndex == -1){
        QMessageBox::information(this, "No Item Selected", "Choose an item in the list below to return");
        return;
    }
    controller->checkIn(selectedLoanIndex);
    QMessageBox::information(this, "Item Returned", "The item was successfully returned");
    refreshAccountContents();
    selectedLoanIndex = -1;

}

void PatronWindow::cancelHold(){
    if(selectedHoldIndex == -1){
        QMessageBox::information(this, "No Item Selected", "Choose an item in the list below to cancel it's hold");
        return;
    }
    controller->cancelHold(selectedHoldIndex);
    refreshAccountContents();
    selectedHoldIndex = -1;
}


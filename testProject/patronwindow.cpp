#include "patronwindow.h"
#include "ui_patronwindow.h"

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
                     [&](){
        ui->bigWidget->setCurrentIndex(1);

    });
    
    QObject::connect(ui->catalogButton,
                         &QPushButton::clicked,
                         this,
                     [&](){
        ui->bigWidget->setCurrentIndex(2);

    });

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

    addEntryToCatalogue("1");
    addEntryToCatalogue("2");
    addEntryToCatalogue("3");
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

void PatronWindow::signOutRequest(){
    emit signOut();
}


void PatronWindow::addEntryToCatalogue(const QString& name)
{
    QPushButton *newButton = new QPushButton(name, this);
    ui->scrollAreaWidgetContents->layout()->addWidget(newButton);

}








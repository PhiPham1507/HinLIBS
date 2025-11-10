#include "adminwindow.h"
#include "ui_adminwindow.h"

AdminWindow::AdminWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->signoutButton_2,
                         &QPushButton::clicked,
                         this,
                         &AdminWindow::signOutRequest);
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::signOutRequest(){
    emit signOut();
}
void AdminWindow::setname(const QString &user){
    ui->nameDisplay_2->setText(user);

}

#include "librarianwindow.h"
#include "ui_librarianwindow.h"

LibrarianWindow::LibrarianWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LibrarianWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->signoutButton,
                         &QPushButton::clicked,
                         this,
                         &LibrarianWindow::signOutRequest);

}

LibrarianWindow::~LibrarianWindow()
{
    delete ui;
}

void LibrarianWindow::signOutRequest(){
    emit signOut();
}
void LibrarianWindow::setname(const QString &user){

    ui->nameDisplay->setText(user);
}

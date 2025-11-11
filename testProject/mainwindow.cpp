#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton,
                         &QPushButton::clicked,
                         this,
                         &MainWindow::obtainData);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::obtainData(){
    const QString username = this->ui->usernameEdit->text();
    this->ui->usernameEdit->clear();
    const QString password = this->ui->passwordEdit->text();
    this->ui->passwordEdit->clear();

    emit dataReady(username, password);


}

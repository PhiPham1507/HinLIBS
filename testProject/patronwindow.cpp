#include "patronwindow.h"
#include "ui_patronwindow.h"

PatronWindow::PatronWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PatronWindow)
{
    ui->setupUi(this);
}

PatronWindow::~PatronWindow()
{
    delete ui;
}

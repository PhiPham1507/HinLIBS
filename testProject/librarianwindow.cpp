#include "librarianwindow.h"
#include "ui_librarianwindow.h"
void hideWhenDefault();
LibrarianWindow::LibrarianWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LibrarianWindow)
{
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



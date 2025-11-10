#include "AuthenticateWindow.h"
#include "ui_AuthenticateWindow.h"

#include "QString"

#include "QDebug"

AuthenticateWindow::AuthenticateWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    authenticator = new Authenticator();

    // Bind the login button
    connect(ui->loginButton, &QPushButton::clicked, this, &AuthenticateWindow::handleLoginClick);
}

AuthenticateWindow::~AuthenticateWindow()
{
    delete ui;
    delete authenticator;
}

void AuthenticateWindow::handleLoginClick()
{

    qDebug() << "Log in clicked!";

    ui->statusLabel->setText("Status: loading...");

    Account* account = authenticator->requestSignIn(ui->usernameField->text().toStdString(), ui->passwordField->text().toStdString());

    if (account == nullptr)
    {
        ui->statusLabel->setText("Status: no matching credentials.");
    } else  {
        string accountName = account->getAccountName();
        int accountType = account->getAccountType();
        QString credentialMsg = QString::fromStdString("Status: Signed in as:\nUsername: " + accountName + "\nAccount type: " + to_string(accountType));
        ui->statusLabel->setText(credentialMsg);
    }

}

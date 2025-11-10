#include "AuthenticateWindow.h"
#include "ui_AuthenticateWindow.h"

#include "QString"

#include "QDebug"

AuthenticateWindow::AuthenticateWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Bind the login button
    connect(ui->loginButton, &QPushButton::clicked, this, &AuthenticateWindow::handleLoginClick);
}

AuthenticateWindow::~AuthenticateWindow()
{
    delete ui;
}

// Fired when the log in butto is clicked
void AuthenticateWindow::handleLoginClick()
{

    ui->statusLabel->setText("Status: loading...");

    Account* account = Authenticator::requestSignIn(ui->usernameField->text().toStdString(), ui->passwordField->text().toStdString());

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

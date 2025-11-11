#include "mainwindow.h"
#include "librarianwindow.h"
#include "adminwindow.h"
#include "patronwindow.h"
#include <QDebug>

#include <QApplication>
#include "Authenticator.h"

int main(int argc, char *argv[])
{

    Authenticator authenticator;

    QApplication a(argc, argv);
    MainWindow window;
    LibrarianWindow lw;
    AdminWindow aw;
    PatronWindow pw;

    QObject::connect(&window, &MainWindow::dataReady, [&](const QString& user, const QString& pass){

//       qDebug() << user;
//       qDebug() << pass;

       bool signInSuccess = authenticator.requestSignIn(user.toStdString(), pass.toStdString());
       if (!signInSuccess) return;

       Account* account = authenticator.getCurrentAccount();
       if (account == nullptr) return;

       //qDebug() << "Welcome, " << account->getAccountName() << ".";

       window.close();
        if(account->getAccountType() == LIBRARIAN){
           lw.setname(user);
           lw.show();
        }else if (account->getAccountType() == ADMIN){
            aw.setname(user);
            aw.show();
        }else{
            pw.setname(user);
            pw.show();
        }
    });

    QObject::connect(&lw, &LibrarianWindow::signOut,[&](){
        authenticator.signOut();
        lw.close();
        window.show();
    });
    QObject::connect(&aw, &AdminWindow::signOut,[&](){
        authenticator.signOut();
        aw.close();
        window.show();
    });

    QObject::connect(&pw, &PatronWindow::signOut,[&](){
        authenticator.signOut();
        pw.close();
        window.show();
    });
    window.show();

    return a.exec();
}


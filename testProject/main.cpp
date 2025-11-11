#include "mainwindow.h"
#include "librarianwindow.h"
#include "adminwindow.h"
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


    QObject::connect(&window, &MainWindow::dataReady, [&](const QString& user, const QString& pass){

       qDebug() << user;
       qDebug() << pass;

       bool signInSuccess = authenticator.requestSignIn(user.toStdString(), pass.toStdString());
       if (!signInSuccess) return;

       Account* account = authenticator.getCurrentAccount();
       if (account == nullptr) return;

        window.close();
        if(account->getAccountType() == LIBRARIAN){
           lw.setname(user);
           lw.show();
        }else if (account->getAccountType() == ADMIN){
            aw.setname(user);
            aw.show();
        }
    });

    QObject::connect(&lw, &LibrarianWindow::signOut,[&](){
        lw.close();
        window.show();
    });
    QObject::connect(&aw, &AdminWindow::signOut,[&](){
        aw.close();
        window.show();
    });


    window.show();

    return a.exec();
}


#include "mainwindow.h"
#include "librarianwindow.h"
#include "adminwindow.h"
#include "patronwindow.h"
#include <QDebug>

#include <QApplication>
#include "datacontroller.h"

int main(int argc, char *argv[])
{

    DataController controller;



    QApplication a(argc, argv);
    MainWindow window;
    LibrarianWindow lw;
    AdminWindow aw;
    PatronWindow pw;

    QObject::connect(&window, &MainWindow::dataReady, [&](const QString& user, const QString& pass){


       controller.authenticate(user.toStdString(), pass.toStdString());
       if (controller.getAccount() == nullptr){


           return;
       }
       window.close();
        if(controller.getAccount()->getAccountType() == LIBRARIAN){
           lw.setname(user);
           lw.show();
        }else if (controller.getAccount()->getAccountType() == ADMIN){
            aw.setname(user);
            aw.show();
        }else{
            pw.setController(&controller);
            pw.setname(user);
            pw.show();
        }
    });

    QObject::connect(&lw, &LibrarianWindow::signOut,[&](){
        lw.close();
        window.show();
        controller.accLoggedOut();
    });
    QObject::connect(&aw, &AdminWindow::signOut,[&](){
        aw.close();
        window.show();
        controller.accLoggedOut();
    });

    QObject::connect(&pw, &PatronWindow::signOut,[&](){
        pw.close();
        window.show();
        controller.accLoggedOut();
    });

    window.show();

    return a.exec();

}


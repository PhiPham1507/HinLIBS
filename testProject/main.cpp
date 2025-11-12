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


       Account* login = controller.authenticate(user.toStdString(), pass.toStdString());
       if (login == nullptr){


           return;
       }
       window.close();
        if(login->getAccountType() == LIBRARIAN){
           lw.setname(user);
           lw.show();
        }else if (login->getAccountType() == PATRON){
            Patron* patron = static_cast<Patron*>(login);
            controller.setPatron(patron);
            pw.setController(&controller);
            pw.setname(user);
            pw.show();
        }else{
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

    QObject::connect(&pw, &PatronWindow::signOut,[&](){

        pw.close();
        window.show();
        controller.accLoggedOut();
    });

    window.show();

    return a.exec();

}


#include "mainwindow.h"
#include "librarianwindow.h"
#include "adminwindow.h"
#include "patronwindow.h"
#include <QDebug>

#include <QApplication>
#include "datacontroller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DataController controller;
    controller.getDatabase().printDatabase();  // ← Add this (you may need getDatabase())

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
           Librarian* lib = static_cast<Librarian*>(login);
           controller.setLibrarian(lib);
           lw.setController(&controller);
           lw.show();


        }else if (login->getAccountType() == PATRON){
            Patron* patron = static_cast<Patron*>(login);
            controller.setPatron(patron);
            pw.setController(&controller);
            pw.setname(user);
            pw.show();
            pw.viewAccountButtonSelected(); // show account status by defaults
        }else{
            aw.setname(user);
            aw.show();
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
    });

    QObject::connect(&pw, &PatronWindow::signOut,[&](){

        pw.close();
        window.show();
        controller.accLoggedOut();
    });

    window.show();


    return a.exec();

}


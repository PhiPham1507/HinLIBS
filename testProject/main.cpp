#include "mainwindow.h"
#include "librarianwindow.h"
#include "adminwindow.h"
#include "patronwindow.h"
#include <QDebug>

#include <QApplication>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow window;
    LibrarianWindow lw;
    AdminWindow aw;
    PatronWindow pw;
    int i = 0;


    QObject::connect(&window, &MainWindow::dataReady, [&](const QString& user, const QString& pass){
        qDebug() << user;
        qDebug() << pass;


        window.close();
        if(i == 0){
           lw.setname(user);
           lw.show();
        }else if(i == 1){
            aw.setname(user);
            aw.show();
        }else{
            pw.setname(user);
            pw.show();
        }
    });

    QObject::connect(&lw, &LibrarianWindow::signOut,[&](){
        lw.close();
        i = (i + 1) % 3;
        window.show();
    });
    QObject::connect(&aw, &AdminWindow::signOut,[&](){
        aw.close();
        i = (i + 1) % 3;
        window.show();
    });

    QObject::connect(&pw, &PatronWindow::signOut,[&](){
        pw.close();
        i = (i + 1) % 3;
        window.show();
    });
    window.show();


    return a.exec();
}


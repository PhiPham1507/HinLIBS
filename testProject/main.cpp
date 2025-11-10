#include "mainwindow.h"
#include "librarianwindow.h"
#include "adminwindow.h"
#include <QDebug>

#include <QApplication>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow window;
    LibrarianWindow lw;
    AdminWindow aw;
    int i = 0;


    QObject::connect(&window, &MainWindow::dataReady, [&](const QString& user, const QString& pass){
        qDebug() << user;
        qDebug() << pass;


        window.close();
        if(i == 0){
           lw.setname(user);
           lw.show();
        }else{
            aw.setname(user);
            aw.show();
        }
    });

    QObject::connect(&lw, &LibrarianWindow::signOut,[&](){
        lw.close();
        i = (i + 1) % 2;
        window.show();
    });
    QObject::connect(&aw, &AdminWindow::signOut,[&](){
        aw.close();
        i = (i + 1) % 2;
        window.show();
    });


    window.show();


    return a.exec();
}


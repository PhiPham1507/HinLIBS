#include "mainwindow.h"
#include <QDebug>

#include <QApplication>
void authenticate(const QString& user, const QString& pass){

}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow window;
    window.show();

    QObject::connect(&window, &MainWindow::dataReady, [&](const QString& user, const QString& pass){
        qDebug() << user;
        qDebug() << pass;
    });



    return a.exec();
}


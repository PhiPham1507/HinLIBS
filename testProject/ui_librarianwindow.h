/********************************************************************************
** Form generated from reading UI file 'librarianwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIBRARIANWINDOW_H
#define UI_LIBRARIANWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LibrarianWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QPushButton *catalogueButton;
    QLabel *name;
    QLabel *nameDisplay;
    QPushButton *signoutButton;
    QPushButton *accountsButton;
    QPushButton *loanButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LibrarianWindow)
    {
        if (LibrarianWindow->objectName().isEmpty())
            LibrarianWindow->setObjectName(QString::fromUtf8("LibrarianWindow"));
        LibrarianWindow->resize(800, 600);
        centralwidget = new QWidget(LibrarianWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 781, 301));
        catalogueButton = new QPushButton(groupBox);
        catalogueButton->setObjectName(QString::fromUtf8("catalogueButton"));
        catalogueButton->setGeometry(QRect(20, 70, 141, 51));
        name = new QLabel(groupBox);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(460, 0, 62, 17));
        nameDisplay = new QLabel(groupBox);
        nameDisplay->setObjectName(QString::fromUtf8("nameDisplay"));
        nameDisplay->setGeometry(QRect(530, 0, 241, 17));
        signoutButton = new QPushButton(groupBox);
        signoutButton->setObjectName(QString::fromUtf8("signoutButton"));
        signoutButton->setGeometry(QRect(690, 270, 83, 25));
        accountsButton = new QPushButton(groupBox);
        accountsButton->setObjectName(QString::fromUtf8("accountsButton"));
        accountsButton->setGeometry(QRect(290, 70, 141, 51));
        loanButton = new QPushButton(groupBox);
        loanButton->setObjectName(QString::fromUtf8("loanButton"));
        loanButton->setGeometry(QRect(570, 70, 141, 51));
        LibrarianWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LibrarianWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        LibrarianWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LibrarianWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LibrarianWindow->setStatusBar(statusbar);

        retranslateUi(LibrarianWindow);

        QMetaObject::connectSlotsByName(LibrarianWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LibrarianWindow)
    {
        LibrarianWindow->setWindowTitle(QCoreApplication::translate("LibrarianWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("LibrarianWindow", "Role: Librarian", nullptr));
        catalogueButton->setText(QCoreApplication::translate("LibrarianWindow", "Manage Catalogue", nullptr));
        name->setText(QCoreApplication::translate("LibrarianWindow", "Name:", nullptr));
        nameDisplay->setText(QString());
        signoutButton->setText(QCoreApplication::translate("LibrarianWindow", "Sign out", nullptr));
        accountsButton->setText(QCoreApplication::translate("LibrarianWindow", "Manage Account", nullptr));
        loanButton->setText(QCoreApplication::translate("LibrarianWindow", "Manage Loans", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LibrarianWindow: public Ui_LibrarianWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIBRARIANWINDOW_H

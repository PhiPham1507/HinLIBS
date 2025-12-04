/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

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

class Ui_AdminWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QPushButton *catalogueButton_2;
    QLabel *name_2;
    QLabel *nameDisplay_2;
    QPushButton *signoutButton_2;
    QPushButton *accountsButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName("AdminWindow");
        AdminWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AdminWindow->sizePolicy().hasHeightForWidth());
        AdminWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(AdminWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 10, 781, 301));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        catalogueButton_2 = new QPushButton(groupBox);
        catalogueButton_2->setObjectName("catalogueButton_2");
        catalogueButton_2->setGeometry(QRect(20, 70, 271, 101));
        name_2 = new QLabel(groupBox);
        name_2->setObjectName("name_2");
        name_2->setGeometry(QRect(460, 0, 62, 17));
        nameDisplay_2 = new QLabel(groupBox);
        nameDisplay_2->setObjectName("nameDisplay_2");
        nameDisplay_2->setGeometry(QRect(530, 0, 241, 17));
        signoutButton_2 = new QPushButton(groupBox);
        signoutButton_2->setObjectName("signoutButton_2");
        signoutButton_2->setGeometry(QRect(690, 270, 83, 25));
        accountsButton_2 = new QPushButton(groupBox);
        accountsButton_2->setObjectName("accountsButton_2");
        accountsButton_2->setGeometry(QRect(470, 70, 271, 101));
        AdminWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AdminWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        AdminWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AdminWindow);
        statusbar->setObjectName("statusbar");
        AdminWindow->setStatusBar(statusbar);

        retranslateUi(AdminWindow);

        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdminWindow)
    {
        AdminWindow->setWindowTitle(QCoreApplication::translate("AdminWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("AdminWindow", "Role: System Administrator", nullptr));
        catalogueButton_2->setText(QCoreApplication::translate("AdminWindow", "Manage Library System", nullptr));
        name_2->setText(QCoreApplication::translate("AdminWindow", "Name:", nullptr));
        nameDisplay_2->setText(QString());
        signoutButton_2->setText(QCoreApplication::translate("AdminWindow", "Sign out", nullptr));
        accountsButton_2->setText(QCoreApplication::translate("AdminWindow", "Manage Account", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H

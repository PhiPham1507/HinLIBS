/********************************************************************************
** Form generated from reading UI file 'patronwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATRONWINDOW_H
#define UI_PATRONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatronWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *viewAccButton;
    QPushButton *catalogButton;
    QLabel *userDisplay;
    QLabel *roleDisplay;
    QLabel *userOutput;
    QStackedWidget *bigWidget;
    QWidget *page;
    QWidget *accountPage;
    QListWidget *loanList;
    QListWidget *holdList;
    QLabel *loanLabel;
    QLabel *holdLabel;
    QPushButton *returnButton;
    QPushButton *choldButton;
    QWidget *cataloguePage;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *catalogueLayout;
    QPushButton *checkoutButton;
    QPushButton *pholdButton;
    QListWidget *catalogueList;
    QPushButton *signoutButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PatronWindow)
    {
        if (PatronWindow->objectName().isEmpty())
            PatronWindow->setObjectName(QString::fromUtf8("PatronWindow"));
        PatronWindow->resize(826, 606);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PatronWindow->sizePolicy().hasHeightForWidth());
        PatronWindow->setSizePolicy(sizePolicy);
        PatronWindow->setAnimated(true);
        centralwidget = new QWidget(PatronWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 40, 821, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        viewAccButton = new QPushButton(horizontalLayoutWidget);
        viewAccButton->setObjectName(QString::fromUtf8("viewAccButton"));

        horizontalLayout->addWidget(viewAccButton);

        catalogButton = new QPushButton(horizontalLayoutWidget);
        catalogButton->setObjectName(QString::fromUtf8("catalogButton"));

        horizontalLayout->addWidget(catalogButton);

        userDisplay = new QLabel(centralwidget);
        userDisplay->setObjectName(QString::fromUtf8("userDisplay"));
        userDisplay->setGeometry(QRect(230, 0, 121, 31));
        roleDisplay = new QLabel(centralwidget);
        roleDisplay->setObjectName(QString::fromUtf8("roleDisplay"));
        roleDisplay->setGeometry(QRect(10, 0, 171, 31));
        userOutput = new QLabel(centralwidget);
        userOutput->setObjectName(QString::fromUtf8("userOutput"));
        userOutput->setGeometry(QRect(340, 0, 461, 31));
        bigWidget = new QStackedWidget(centralwidget);
        bigWidget->setObjectName(QString::fromUtf8("bigWidget"));
        bigWidget->setGeometry(QRect(0, 100, 831, 421));
        bigWidget->setMouseTracking(false);
        bigWidget->setFrameShape(QFrame::Box);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        bigWidget->addWidget(page);
        accountPage = new QWidget();
        accountPage->setObjectName(QString::fromUtf8("accountPage"));
        loanList = new QListWidget(accountPage);
        loanList->setObjectName(QString::fromUtf8("loanList"));
        loanList->setGeometry(QRect(0, 50, 401, 221));
        holdList = new QListWidget(accountPage);
        holdList->setObjectName(QString::fromUtf8("holdList"));
        holdList->setGeometry(QRect(410, 50, 411, 221));
        loanLabel = new QLabel(accountPage);
        loanLabel->setObjectName(QString::fromUtf8("loanLabel"));
        loanLabel->setGeometry(QRect(160, 20, 81, 21));
        holdLabel = new QLabel(accountPage);
        holdLabel->setObjectName(QString::fromUtf8("holdLabel"));
        holdLabel->setGeometry(QRect(600, 20, 81, 21));
        returnButton = new QPushButton(accountPage);
        returnButton->setObjectName(QString::fromUtf8("returnButton"));
        returnButton->setGeometry(QRect(110, 310, 131, 51));
        choldButton = new QPushButton(accountPage);
        choldButton->setObjectName(QString::fromUtf8("choldButton"));
        choldButton->setGeometry(QRect(560, 310, 131, 51));
        bigWidget->addWidget(accountPage);
        cataloguePage = new QWidget();
        cataloguePage->setObjectName(QString::fromUtf8("cataloguePage"));
        horizontalLayoutWidget_4 = new QWidget(cataloguePage);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(10, 20, 801, 27));
        catalogueLayout = new QHBoxLayout(horizontalLayoutWidget_4);
        catalogueLayout->setObjectName(QString::fromUtf8("catalogueLayout"));
        catalogueLayout->setContentsMargins(0, 0, 0, 0);
        checkoutButton = new QPushButton(horizontalLayoutWidget_4);
        checkoutButton->setObjectName(QString::fromUtf8("checkoutButton"));

        catalogueLayout->addWidget(checkoutButton);

        pholdButton = new QPushButton(horizontalLayoutWidget_4);
        pholdButton->setObjectName(QString::fromUtf8("pholdButton"));

        catalogueLayout->addWidget(pholdButton);

        catalogueList = new QListWidget(cataloguePage);
        catalogueList->setObjectName(QString::fromUtf8("catalogueList"));
        catalogueList->setGeometry(QRect(10, 60, 811, 351));
        bigWidget->addWidget(cataloguePage);
        signoutButton = new QPushButton(centralwidget);
        signoutButton->setObjectName(QString::fromUtf8("signoutButton"));
        signoutButton->setGeometry(QRect(740, 520, 83, 25));
        PatronWindow->setCentralWidget(centralwidget);
        bigWidget->raise();
        horizontalLayoutWidget->raise();
        userDisplay->raise();
        roleDisplay->raise();
        userOutput->raise();
        signoutButton->raise();
        menubar = new QMenuBar(PatronWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 826, 22));
        PatronWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(PatronWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        PatronWindow->setStatusBar(statusbar);

        retranslateUi(PatronWindow);

        bigWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(PatronWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PatronWindow)
    {
        PatronWindow->setWindowTitle(QCoreApplication::translate("PatronWindow", "Patron Window", nullptr));
        viewAccButton->setText(QCoreApplication::translate("PatronWindow", "View Account Information", nullptr));
        catalogButton->setText(QCoreApplication::translate("PatronWindow", "View Catalogue", nullptr));
        userDisplay->setText(QCoreApplication::translate("PatronWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Username:</span></p></body></html>", nullptr));
        roleDisplay->setText(QCoreApplication::translate("PatronWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Role: Patron</span></p></body></html>", nullptr));
        userOutput->setText(QCoreApplication::translate("PatronWindow", "<html><head/><body><p><span style=\" font-size:12pt;\"><br/></span></p></body></html>", nullptr));
        loanLabel->setText(QCoreApplication::translate("PatronWindow", "Loans", nullptr));
        holdLabel->setText(QCoreApplication::translate("PatronWindow", "Holds", nullptr));
        returnButton->setText(QCoreApplication::translate("PatronWindow", "Return Item", nullptr));
        choldButton->setText(QCoreApplication::translate("PatronWindow", "Cancel Hold", nullptr));
        checkoutButton->setText(QCoreApplication::translate("PatronWindow", "Check out", nullptr));
        pholdButton->setText(QCoreApplication::translate("PatronWindow", "Place hold", nullptr));
        signoutButton->setText(QCoreApplication::translate("PatronWindow", "Sign out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatronWindow: public Ui_PatronWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATRONWINDOW_H

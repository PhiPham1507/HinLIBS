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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
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
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *accountLayout;
    QPushButton *infoButton;
    QPushButton *loanButton;
    QPushButton *holdButton;
    QStackedWidget *smallWidget;
    QWidget *infoPage;
    QLabel *label;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *usernameLabel;
    QLabel *passwordLabel;
    QLabel *accountTypeLabel;
    QLabel *label_3;
    QWidget *loanPage;
    QTableWidget *tableWidget;
    QLabel *swL;
    QWidget *holdPage;
    QTableWidget *tableWidget_3;
    QLabel *swH;
    QWidget *cataloguePage;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *catalogueLayout;
    QPushButton *checkoutButton;
    QPushButton *pholdButton;
    QPushButton *choldButton;
    QScrollArea *catalogueScrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QPushButton *signoutButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PatronWindow)
    {
        if (PatronWindow->objectName().isEmpty())
            PatronWindow->setObjectName(QString::fromUtf8("PatronWindow"));
        PatronWindow->resize(821, 606);
        PatronWindow->setAnimated(true);
        centralwidget = new QWidget(PatronWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 40, 801, 51));
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
        bigWidget->setGeometry(QRect(0, 100, 811, 421));
        bigWidget->setMouseTracking(false);
        bigWidget->setFrameShape(QFrame::Box);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        bigWidget->addWidget(page);
        accountPage = new QWidget();
        accountPage->setObjectName(QString::fromUtf8("accountPage"));
        horizontalLayoutWidget_2 = new QWidget(accountPage);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 20, 791, 27));
        accountLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        accountLayout->setObjectName(QString::fromUtf8("accountLayout"));
        accountLayout->setContentsMargins(0, 0, 0, 0);
        infoButton = new QPushButton(horizontalLayoutWidget_2);
        infoButton->setObjectName(QString::fromUtf8("infoButton"));

        accountLayout->addWidget(infoButton);

        loanButton = new QPushButton(horizontalLayoutWidget_2);
        loanButton->setObjectName(QString::fromUtf8("loanButton"));

        accountLayout->addWidget(loanButton);

        holdButton = new QPushButton(horizontalLayoutWidget_2);
        holdButton->setObjectName(QString::fromUtf8("holdButton"));

        accountLayout->addWidget(holdButton);

        smallWidget = new QStackedWidget(accountPage);
        smallWidget->setObjectName(QString::fromUtf8("smallWidget"));
        smallWidget->setGeometry(QRect(0, 60, 801, 351));
        smallWidget->setFrameShape(QFrame::Box);
        infoPage = new QWidget();
        infoPage->setObjectName(QString::fromUtf8("infoPage"));
        label = new QLabel(infoPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 40, 81, 21));
        label_1 = new QLabel(infoPage);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(60, 70, 81, 21));
        label_2 = new QLabel(infoPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 100, 111, 21));
        usernameLabel = new QLabel(infoPage);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));
        usernameLabel->setGeometry(QRect(170, 40, 241, 21));
        passwordLabel = new QLabel(infoPage);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        passwordLabel->setGeometry(QRect(170, 70, 241, 21));
        accountTypeLabel = new QLabel(infoPage);
        accountTypeLabel->setObjectName(QString::fromUtf8("accountTypeLabel"));
        accountTypeLabel->setGeometry(QRect(170, 100, 241, 21));
        label_3 = new QLabel(infoPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 170, 111, 21));
        smallWidget->addWidget(infoPage);
        loanPage = new QWidget();
        loanPage->setObjectName(QString::fromUtf8("loanPage"));
        tableWidget = new QTableWidget(loanPage);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 20, 781, 321));
        swL = new QLabel(loanPage);
        swL->setObjectName(QString::fromUtf8("swL"));
        swL->setGeometry(QRect(280, 80, 271, 91));
        smallWidget->addWidget(loanPage);
        holdPage = new QWidget();
        holdPage->setObjectName(QString::fromUtf8("holdPage"));
        tableWidget_3 = new QTableWidget(holdPage);
        tableWidget_3->setObjectName(QString::fromUtf8("tableWidget_3"));
        tableWidget_3->setGeometry(QRect(10, 20, 781, 321));
        swH = new QLabel(holdPage);
        swH->setObjectName(QString::fromUtf8("swH"));
        swH->setGeometry(QRect(190, 70, 271, 91));
        smallWidget->addWidget(holdPage);
        bigWidget->addWidget(accountPage);
        cataloguePage = new QWidget();
        cataloguePage->setObjectName(QString::fromUtf8("cataloguePage"));
        horizontalLayoutWidget_4 = new QWidget(cataloguePage);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(10, 20, 791, 27));
        catalogueLayout = new QHBoxLayout(horizontalLayoutWidget_4);
        catalogueLayout->setObjectName(QString::fromUtf8("catalogueLayout"));
        catalogueLayout->setContentsMargins(0, 0, 0, 0);
        checkoutButton = new QPushButton(horizontalLayoutWidget_4);
        checkoutButton->setObjectName(QString::fromUtf8("checkoutButton"));

        catalogueLayout->addWidget(checkoutButton);

        pholdButton = new QPushButton(horizontalLayoutWidget_4);
        pholdButton->setObjectName(QString::fromUtf8("pholdButton"));

        catalogueLayout->addWidget(pholdButton);

        choldButton = new QPushButton(horizontalLayoutWidget_4);
        choldButton->setObjectName(QString::fromUtf8("choldButton"));

        catalogueLayout->addWidget(choldButton);

        catalogueScrollArea = new QScrollArea(cataloguePage);
        catalogueScrollArea->setObjectName(QString::fromUtf8("catalogueScrollArea"));
        catalogueScrollArea->setGeometry(QRect(20, 60, 770, 330));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(catalogueScrollArea->sizePolicy().hasHeightForWidth());
        catalogueScrollArea->setSizePolicy(sizePolicy);
        catalogueScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        catalogueScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        catalogueScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 754, 328));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableView = new QTableView(scrollAreaWidgetContents);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setAlternatingRowColors(true);
        tableView->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);

        verticalLayout->addWidget(tableView);

        catalogueScrollArea->setWidget(scrollAreaWidgetContents);
        bigWidget->addWidget(cataloguePage);
        signoutButton = new QPushButton(centralwidget);
        signoutButton->setObjectName(QString::fromUtf8("signoutButton"));
        signoutButton->setGeometry(QRect(730, 530, 83, 25));
        PatronWindow->setCentralWidget(centralwidget);
        bigWidget->raise();
        horizontalLayoutWidget->raise();
        userDisplay->raise();
        roleDisplay->raise();
        userOutput->raise();
        signoutButton->raise();
        menubar = new QMenuBar(PatronWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 821, 22));
        PatronWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(PatronWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        PatronWindow->setStatusBar(statusbar);

        retranslateUi(PatronWindow);

        bigWidget->setCurrentIndex(2);
        smallWidget->setCurrentIndex(0);


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
        infoButton->setText(QCoreApplication::translate("PatronWindow", "View Info", nullptr));
        loanButton->setText(QCoreApplication::translate("PatronWindow", "View Loans", nullptr));
        holdButton->setText(QCoreApplication::translate("PatronWindow", "View Holds", nullptr));
        label->setText(QCoreApplication::translate("PatronWindow", "Username:", nullptr));
        label_1->setText(QCoreApplication::translate("PatronWindow", "Password: ", nullptr));
        label_2->setText(QCoreApplication::translate("PatronWindow", "Account type: ", nullptr));
        usernameLabel->setText(QCoreApplication::translate("PatronWindow", "USERNAME_HERE", nullptr));
        passwordLabel->setText(QCoreApplication::translate("PatronWindow", "PASSWORD_HERE", nullptr));
        accountTypeLabel->setText(QCoreApplication::translate("PatronWindow", "ACCOUNT_TYPE_HERE", nullptr));
        label_3->setText(QCoreApplication::translate("PatronWindow", "Active loans: ", nullptr));
        swL->setText(QCoreApplication::translate("PatronWindow", "LOAN PAGE HERE", nullptr));
        swH->setText(QCoreApplication::translate("PatronWindow", "HOLDS PAGE HERE", nullptr));
        checkoutButton->setText(QCoreApplication::translate("PatronWindow", "Check out", nullptr));
        pholdButton->setText(QCoreApplication::translate("PatronWindow", "Place hold", nullptr));
        choldButton->setText(QCoreApplication::translate("PatronWindow", "Cancel hold", nullptr));
        signoutButton->setText(QCoreApplication::translate("PatronWindow", "Sign out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatronWindow: public Ui_PatronWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATRONWINDOW_H

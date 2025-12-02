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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LibrarianWindow
{
public:
    QWidget *centralwidget;
    QLabel *roleDisplay;
    QLabel *userDisplay;
    QLabel *userOutput;
    QStackedWidget *stackedWidget;
    QWidget *addItemPage;
    QComboBox *chooseItem;
    QLabel *itemLabel;
    QLineEdit *authorInput;
    QLabel *authorLabel;
    QLabel *publicationLabel;
    QLabel *isbnLabel;
    QLineEdit *publicationInput;
    QLineEdit *isbnInput;
    QStackedWidget *itemFormsWidget;
    QWidget *mAndGPage;
    QLabel *genreLabel;
    QLineEdit *genreInput;
    QLabel *ratingLabel;
    QLineEdit *ratingInput;
    QWidget *gameMoviePage;
    QLabel *issueLabel;
    QLineEdit *issueInput;
    QLabel *pubLabel;
    QLabel *pubDayLabel;
    QLabel *pubMonthLabel;
    QLabel *pubYearLabel;
    QLineEdit *yearPubInput;
    QLineEdit *monthPubInput;
    QLineEdit *dayPubInput;
    QWidget *nFPage;
    QLabel *dewyLabel;
    QLineEdit *dewyInput;
    QPushButton *addButton;
    QWidget *removeItemPage;
    QListWidget *catalogueDisplay;
    QPushButton *removeItemButton_2;
    QWidget *pReturnPage;
    QListWidget *listWidget;
    QPushButton *SearchPatronButton;
    QPushButton *ReturnSelectedItems;
    QLineEdit *PatronSearchField;
    QPushButton *signoutButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *addItemButton;
    QPushButton *removeItemButton;
    QPushButton *pReturnButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LibrarianWindow)
    {
        if (LibrarianWindow->objectName().isEmpty())
            LibrarianWindow->setObjectName(QString::fromUtf8("LibrarianWindow"));
        LibrarianWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LibrarianWindow->sizePolicy().hasHeightForWidth());
        LibrarianWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(LibrarianWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        roleDisplay = new QLabel(centralwidget);
        roleDisplay->setObjectName(QString::fromUtf8("roleDisplay"));
        roleDisplay->setGeometry(QRect(10, 10, 171, 31));
        userDisplay = new QLabel(centralwidget);
        userDisplay->setObjectName(QString::fromUtf8("userDisplay"));
        userDisplay->setGeometry(QRect(210, 10, 121, 31));
        userOutput = new QLabel(centralwidget);
        userOutput->setObjectName(QString::fromUtf8("userOutput"));
        userOutput->setGeometry(QRect(320, 10, 461, 31));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 90, 781, 401));
        stackedWidget->setFrameShape(QFrame::Box);
        addItemPage = new QWidget();
        addItemPage->setObjectName(QString::fromUtf8("addItemPage"));
        chooseItem = new QComboBox(addItemPage);
        chooseItem->addItem(QString());
        chooseItem->addItem(QString());
        chooseItem->addItem(QString());
        chooseItem->addItem(QString());
        chooseItem->addItem(QString());
        chooseItem->addItem(QString());
        chooseItem->setObjectName(QString::fromUtf8("chooseItem"));
        chooseItem->setGeometry(QRect(10, 40, 171, 25));
        itemLabel = new QLabel(addItemPage);
        itemLabel->setObjectName(QString::fromUtf8("itemLabel"));
        itemLabel->setGeometry(QRect(10, 10, 181, 20));
        authorInput = new QLineEdit(addItemPage);
        authorInput->setObjectName(QString::fromUtf8("authorInput"));
        authorInput->setGeometry(QRect(430, 40, 113, 25));
        authorLabel = new QLabel(addItemPage);
        authorLabel->setObjectName(QString::fromUtf8("authorLabel"));
        authorLabel->setGeometry(QRect(260, 40, 131, 21));
        publicationLabel = new QLabel(addItemPage);
        publicationLabel->setObjectName(QString::fromUtf8("publicationLabel"));
        publicationLabel->setGeometry(QRect(260, 90, 131, 21));
        isbnLabel = new QLabel(addItemPage);
        isbnLabel->setObjectName(QString::fromUtf8("isbnLabel"));
        isbnLabel->setGeometry(QRect(260, 140, 131, 21));
        publicationInput = new QLineEdit(addItemPage);
        publicationInput->setObjectName(QString::fromUtf8("publicationInput"));
        publicationInput->setGeometry(QRect(430, 90, 113, 25));
        isbnInput = new QLineEdit(addItemPage);
        isbnInput->setObjectName(QString::fromUtf8("isbnInput"));
        isbnInput->setGeometry(QRect(430, 140, 113, 25));
        itemFormsWidget = new QStackedWidget(addItemPage);
        itemFormsWidget->setObjectName(QString::fromUtf8("itemFormsWidget"));
        itemFormsWidget->setGeometry(QRect(260, 170, 371, 191));
        mAndGPage = new QWidget();
        mAndGPage->setObjectName(QString::fromUtf8("mAndGPage"));
        genreLabel = new QLabel(mAndGPage);
        genreLabel->setObjectName(QString::fromUtf8("genreLabel"));
        genreLabel->setGeometry(QRect(0, 20, 131, 21));
        genreInput = new QLineEdit(mAndGPage);
        genreInput->setObjectName(QString::fromUtf8("genreInput"));
        genreInput->setGeometry(QRect(170, 20, 113, 25));
        ratingLabel = new QLabel(mAndGPage);
        ratingLabel->setObjectName(QString::fromUtf8("ratingLabel"));
        ratingLabel->setGeometry(QRect(0, 70, 131, 21));
        ratingInput = new QLineEdit(mAndGPage);
        ratingInput->setObjectName(QString::fromUtf8("ratingInput"));
        ratingInput->setGeometry(QRect(170, 70, 113, 25));
        itemFormsWidget->addWidget(mAndGPage);
        gameMoviePage = new QWidget();
        gameMoviePage->setObjectName(QString::fromUtf8("gameMoviePage"));
        issueLabel = new QLabel(gameMoviePage);
        issueLabel->setObjectName(QString::fromUtf8("issueLabel"));
        issueLabel->setGeometry(QRect(0, 20, 131, 21));
        issueInput = new QLineEdit(gameMoviePage);
        issueInput->setObjectName(QString::fromUtf8("issueInput"));
        issueInput->setGeometry(QRect(170, 20, 113, 25));
        pubLabel = new QLabel(gameMoviePage);
        pubLabel->setObjectName(QString::fromUtf8("pubLabel"));
        pubLabel->setGeometry(QRect(0, 70, 131, 21));
        pubDayLabel = new QLabel(gameMoviePage);
        pubDayLabel->setObjectName(QString::fromUtf8("pubDayLabel"));
        pubDayLabel->setGeometry(QRect(140, 70, 31, 21));
        pubMonthLabel = new QLabel(gameMoviePage);
        pubMonthLabel->setObjectName(QString::fromUtf8("pubMonthLabel"));
        pubMonthLabel->setGeometry(QRect(210, 70, 51, 21));
        pubYearLabel = new QLabel(gameMoviePage);
        pubYearLabel->setObjectName(QString::fromUtf8("pubYearLabel"));
        pubYearLabel->setGeometry(QRect(290, 70, 41, 21));
        yearPubInput = new QLineEdit(gameMoviePage);
        yearPubInput->setObjectName(QString::fromUtf8("yearPubInput"));
        yearPubInput->setGeometry(QRect(280, 100, 61, 25));
        monthPubInput = new QLineEdit(gameMoviePage);
        monthPubInput->setObjectName(QString::fromUtf8("monthPubInput"));
        monthPubInput->setGeometry(QRect(200, 100, 61, 25));
        dayPubInput = new QLineEdit(gameMoviePage);
        dayPubInput->setObjectName(QString::fromUtf8("dayPubInput"));
        dayPubInput->setGeometry(QRect(120, 100, 61, 25));
        itemFormsWidget->addWidget(gameMoviePage);
        nFPage = new QWidget();
        nFPage->setObjectName(QString::fromUtf8("nFPage"));
        dewyLabel = new QLabel(nFPage);
        dewyLabel->setObjectName(QString::fromUtf8("dewyLabel"));
        dewyLabel->setGeometry(QRect(0, 20, 131, 21));
        dewyInput = new QLineEdit(nFPage);
        dewyInput->setObjectName(QString::fromUtf8("dewyInput"));
        dewyInput->setGeometry(QRect(170, 20, 113, 25));
        itemFormsWidget->addWidget(nFPage);
        addButton = new QPushButton(addItemPage);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(690, 370, 83, 25));
        stackedWidget->addWidget(addItemPage);
        removeItemPage = new QWidget();
        removeItemPage->setObjectName(QString::fromUtf8("removeItemPage"));
        catalogueDisplay = new QListWidget(removeItemPage);
        catalogueDisplay->setObjectName(QString::fromUtf8("catalogueDisplay"));
        catalogueDisplay->setGeometry(QRect(0, 0, 621, 401));
        removeItemButton_2 = new QPushButton(removeItemPage);
        removeItemButton_2->setObjectName(QString::fromUtf8("removeItemButton_2"));
        removeItemButton_2->setGeometry(QRect(660, 190, 83, 25));
        stackedWidget->addWidget(removeItemPage);
        pReturnPage = new QWidget();
        pReturnPage->setObjectName(QString::fromUtf8("pReturnPage"));
        listWidget = new QListWidget(pReturnPage);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(0, 60, 781, 341));
        SearchPatronButton = new QPushButton(pReturnPage);
        SearchPatronButton->setObjectName(QString::fromUtf8("SearchPatronButton"));
        SearchPatronButton->setGeometry(QRect(440, 20, 171, 25));
        ReturnSelectedItems = new QPushButton(pReturnPage);
        ReturnSelectedItems->setObjectName(QString::fromUtf8("ReturnSelectedItems"));
        ReturnSelectedItems->setGeometry(QRect(632, 20, 121, 25));
        PatronSearchField = new QLineEdit(pReturnPage);
        PatronSearchField->setObjectName(QString::fromUtf8("PatronSearchField"));
        PatronSearchField->setGeometry(QRect(130, 20, 291, 25));
        stackedWidget->addWidget(pReturnPage);
        signoutButton = new QPushButton(centralwidget);
        signoutButton->setObjectName(QString::fromUtf8("signoutButton"));
        signoutButton->setGeometry(QRect(710, 520, 83, 25));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(140, 50, 471, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        addItemButton = new QPushButton(horizontalLayoutWidget);
        addItemButton->setObjectName(QString::fromUtf8("addItemButton"));

        horizontalLayout->addWidget(addItemButton);

        removeItemButton = new QPushButton(horizontalLayoutWidget);
        removeItemButton->setObjectName(QString::fromUtf8("removeItemButton"));

        horizontalLayout->addWidget(removeItemButton);

        pReturnButton = new QPushButton(horizontalLayoutWidget);
        pReturnButton->setObjectName(QString::fromUtf8("pReturnButton"));

        horizontalLayout->addWidget(pReturnButton);

        LibrarianWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LibrarianWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        LibrarianWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LibrarianWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LibrarianWindow->setStatusBar(statusbar);

        retranslateUi(LibrarianWindow);

        stackedWidget->setCurrentIndex(2);
        itemFormsWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(LibrarianWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LibrarianWindow)
    {
        LibrarianWindow->setWindowTitle(QCoreApplication::translate("LibrarianWindow", "MainWindow", nullptr));
        roleDisplay->setText(QCoreApplication::translate("LibrarianWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Role: Librarian</span></p></body></html>", nullptr));
        userDisplay->setText(QCoreApplication::translate("LibrarianWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Username:</span></p></body></html>", nullptr));
        userOutput->setText(QCoreApplication::translate("LibrarianWindow", "<html><head/><body><p><span style=\" font-size:12pt;\"><br/></span></p></body></html>", nullptr));
        chooseItem->setItemText(0, QString());
        chooseItem->setItemText(1, QCoreApplication::translate("LibrarianWindow", "Fiction Book", nullptr));
        chooseItem->setItemText(2, QCoreApplication::translate("LibrarianWindow", "Non-fiction Book", nullptr));
        chooseItem->setItemText(3, QCoreApplication::translate("LibrarianWindow", "Video Game", nullptr));
        chooseItem->setItemText(4, QCoreApplication::translate("LibrarianWindow", "Movie", nullptr));
        chooseItem->setItemText(5, QCoreApplication::translate("LibrarianWindow", "Magazine", nullptr));

        itemLabel->setText(QCoreApplication::translate("LibrarianWindow", "Choose which item to add", nullptr));
        authorLabel->setText(QCoreApplication::translate("LibrarianWindow", "Author:", nullptr));
        publicationLabel->setText(QCoreApplication::translate("LibrarianWindow", "Publiation Year:", nullptr));
        isbnLabel->setText(QCoreApplication::translate("LibrarianWindow", "ISBN:", nullptr));
        genreLabel->setText(QCoreApplication::translate("LibrarianWindow", "Genre:", nullptr));
        ratingLabel->setText(QCoreApplication::translate("LibrarianWindow", "Rating:", nullptr));
        issueLabel->setText(QCoreApplication::translate("LibrarianWindow", "Issue Number:", nullptr));
        pubLabel->setText(QCoreApplication::translate("LibrarianWindow", "Publication Date:", nullptr));
        pubDayLabel->setText(QCoreApplication::translate("LibrarianWindow", "Day:", nullptr));
        pubMonthLabel->setText(QCoreApplication::translate("LibrarianWindow", "Month:", nullptr));
        pubYearLabel->setText(QCoreApplication::translate("LibrarianWindow", "Year:", nullptr));
        dewyLabel->setText(QCoreApplication::translate("LibrarianWindow", "Dewy Decimal:", nullptr));
        addButton->setText(QCoreApplication::translate("LibrarianWindow", "Add", nullptr));
        removeItemButton_2->setText(QCoreApplication::translate("LibrarianWindow", "Remove", nullptr));
        SearchPatronButton->setText(QCoreApplication::translate("LibrarianWindow", "Search Patron name", nullptr));
        ReturnSelectedItems->setText(QCoreApplication::translate("LibrarianWindow", "Return selected", nullptr));
        signoutButton->setText(QCoreApplication::translate("LibrarianWindow", "Sign out", nullptr));
        addItemButton->setText(QCoreApplication::translate("LibrarianWindow", "Add item", nullptr));
        removeItemButton->setText(QCoreApplication::translate("LibrarianWindow", "Remove Item", nullptr));
        pReturnButton->setText(QCoreApplication::translate("LibrarianWindow", "Return for Patron", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LibrarianWindow: public Ui_LibrarianWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIBRARIANWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'librarianwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
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
    QLabel *titleLabel;
    QLineEdit *titleInput;
    QWidget *removeItemPage;
    QListWidget *catalogueDisplay;
    QPushButton *removeItemButton_2;
    QWidget *pReturnPage;
    QListWidget *LoansList;
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
            LibrarianWindow->setObjectName("LibrarianWindow");
        LibrarianWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LibrarianWindow->sizePolicy().hasHeightForWidth());
        LibrarianWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(LibrarianWindow);
        centralwidget->setObjectName("centralwidget");
        roleDisplay = new QLabel(centralwidget);
        roleDisplay->setObjectName("roleDisplay");
        roleDisplay->setGeometry(QRect(10, 10, 171, 31));
        userDisplay = new QLabel(centralwidget);
        userDisplay->setObjectName("userDisplay");
        userDisplay->setGeometry(QRect(210, 10, 121, 31));
        userOutput = new QLabel(centralwidget);
        userOutput->setObjectName("userOutput");
        userOutput->setGeometry(QRect(320, 10, 461, 31));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(10, 100, 781, 401));
        stackedWidget->setFrameShape(QFrame::Box);
        addItemPage = new QWidget();
        addItemPage->setObjectName("addItemPage");
        chooseItem = new QComboBox(addItemPage);
        chooseItem->addItem(QString());
        chooseItem->addItem(QString());
        chooseItem->addItem(QString());
        chooseItem->addItem(QString());
        chooseItem->addItem(QString());
        chooseItem->addItem(QString());
        chooseItem->setObjectName("chooseItem");
        chooseItem->setGeometry(QRect(10, 40, 171, 25));
        itemLabel = new QLabel(addItemPage);
        itemLabel->setObjectName("itemLabel");
        itemLabel->setGeometry(QRect(10, 10, 181, 20));
        authorInput = new QLineEdit(addItemPage);
        authorInput->setObjectName("authorInput");
        authorInput->setGeometry(QRect(430, 110, 113, 25));
        authorLabel = new QLabel(addItemPage);
        authorLabel->setObjectName("authorLabel");
        authorLabel->setGeometry(QRect(260, 110, 131, 21));
        publicationLabel = new QLabel(addItemPage);
        publicationLabel->setObjectName("publicationLabel");
        publicationLabel->setGeometry(QRect(260, 160, 131, 21));
        isbnLabel = new QLabel(addItemPage);
        isbnLabel->setObjectName("isbnLabel");
        isbnLabel->setGeometry(QRect(260, 210, 131, 21));
        publicationInput = new QLineEdit(addItemPage);
        publicationInput->setObjectName("publicationInput");
        publicationInput->setGeometry(QRect(430, 160, 113, 25));
        isbnInput = new QLineEdit(addItemPage);
        isbnInput->setObjectName("isbnInput");
        isbnInput->setGeometry(QRect(430, 210, 113, 25));
        itemFormsWidget = new QStackedWidget(addItemPage);
        itemFormsWidget->setObjectName("itemFormsWidget");
        itemFormsWidget->setGeometry(QRect(260, 240, 371, 131));
        mAndGPage = new QWidget();
        mAndGPage->setObjectName("mAndGPage");
        genreLabel = new QLabel(mAndGPage);
        genreLabel->setObjectName("genreLabel");
        genreLabel->setGeometry(QRect(0, 20, 131, 21));
        genreInput = new QLineEdit(mAndGPage);
        genreInput->setObjectName("genreInput");
        genreInput->setGeometry(QRect(170, 20, 113, 25));
        ratingLabel = new QLabel(mAndGPage);
        ratingLabel->setObjectName("ratingLabel");
        ratingLabel->setGeometry(QRect(0, 70, 131, 21));
        ratingInput = new QLineEdit(mAndGPage);
        ratingInput->setObjectName("ratingInput");
        ratingInput->setGeometry(QRect(170, 70, 113, 25));
        itemFormsWidget->addWidget(mAndGPage);
        gameMoviePage = new QWidget();
        gameMoviePage->setObjectName("gameMoviePage");
        issueLabel = new QLabel(gameMoviePage);
        issueLabel->setObjectName("issueLabel");
        issueLabel->setGeometry(QRect(0, 20, 131, 21));
        issueInput = new QLineEdit(gameMoviePage);
        issueInput->setObjectName("issueInput");
        issueInput->setGeometry(QRect(170, 20, 113, 25));
        pubLabel = new QLabel(gameMoviePage);
        pubLabel->setObjectName("pubLabel");
        pubLabel->setGeometry(QRect(0, 70, 131, 21));
        pubDayLabel = new QLabel(gameMoviePage);
        pubDayLabel->setObjectName("pubDayLabel");
        pubDayLabel->setGeometry(QRect(140, 70, 31, 21));
        pubMonthLabel = new QLabel(gameMoviePage);
        pubMonthLabel->setObjectName("pubMonthLabel");
        pubMonthLabel->setGeometry(QRect(210, 70, 51, 21));
        pubYearLabel = new QLabel(gameMoviePage);
        pubYearLabel->setObjectName("pubYearLabel");
        pubYearLabel->setGeometry(QRect(290, 70, 41, 21));
        yearPubInput = new QLineEdit(gameMoviePage);
        yearPubInput->setObjectName("yearPubInput");
        yearPubInput->setGeometry(QRect(280, 100, 61, 25));
        monthPubInput = new QLineEdit(gameMoviePage);
        monthPubInput->setObjectName("monthPubInput");
        monthPubInput->setGeometry(QRect(200, 100, 61, 25));
        dayPubInput = new QLineEdit(gameMoviePage);
        dayPubInput->setObjectName("dayPubInput");
        dayPubInput->setGeometry(QRect(120, 100, 61, 25));
        itemFormsWidget->addWidget(gameMoviePage);
        nFPage = new QWidget();
        nFPage->setObjectName("nFPage");
        dewyLabel = new QLabel(nFPage);
        dewyLabel->setObjectName("dewyLabel");
        dewyLabel->setGeometry(QRect(0, 20, 131, 21));
        dewyInput = new QLineEdit(nFPage);
        dewyInput->setObjectName("dewyInput");
        dewyInput->setGeometry(QRect(170, 20, 113, 25));
        itemFormsWidget->addWidget(nFPage);
        addButton = new QPushButton(addItemPage);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(690, 370, 83, 25));
        titleLabel = new QLabel(addItemPage);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setGeometry(QRect(260, 60, 131, 21));
        titleInput = new QLineEdit(addItemPage);
        titleInput->setObjectName("titleInput");
        titleInput->setGeometry(QRect(430, 60, 113, 25));
        stackedWidget->addWidget(addItemPage);
        removeItemPage = new QWidget();
        removeItemPage->setObjectName("removeItemPage");
        catalogueDisplay = new QListWidget(removeItemPage);
        catalogueDisplay->setObjectName("catalogueDisplay");
        catalogueDisplay->setGeometry(QRect(0, 0, 621, 401));
        removeItemButton_2 = new QPushButton(removeItemPage);
        removeItemButton_2->setObjectName("removeItemButton_2");
        removeItemButton_2->setGeometry(QRect(660, 190, 83, 25));
        stackedWidget->addWidget(removeItemPage);
        pReturnPage = new QWidget();
        pReturnPage->setObjectName("pReturnPage");
        LoansList = new QListWidget(pReturnPage);
        LoansList->setObjectName("LoansList");
        LoansList->setGeometry(QRect(0, 60, 781, 341));
        SearchPatronButton = new QPushButton(pReturnPage);
        SearchPatronButton->setObjectName("SearchPatronButton");
        SearchPatronButton->setGeometry(QRect(440, 20, 171, 25));
        ReturnSelectedItems = new QPushButton(pReturnPage);
        ReturnSelectedItems->setObjectName("ReturnSelectedItems");
        ReturnSelectedItems->setGeometry(QRect(632, 20, 121, 25));
        PatronSearchField = new QLineEdit(pReturnPage);
        PatronSearchField->setObjectName("PatronSearchField");
        PatronSearchField->setGeometry(QRect(130, 20, 291, 25));
        stackedWidget->addWidget(pReturnPage);
        signoutButton = new QPushButton(centralwidget);
        signoutButton->setObjectName("signoutButton");
        signoutButton->setGeometry(QRect(710, 520, 83, 25));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(140, 50, 471, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        addItemButton = new QPushButton(horizontalLayoutWidget);
        addItemButton->setObjectName("addItemButton");

        horizontalLayout->addWidget(addItemButton);

        removeItemButton = new QPushButton(horizontalLayoutWidget);
        removeItemButton->setObjectName("removeItemButton");

        horizontalLayout->addWidget(removeItemButton);

        pReturnButton = new QPushButton(horizontalLayoutWidget);
        pReturnButton->setObjectName("pReturnButton");

        horizontalLayout->addWidget(pReturnButton);

        LibrarianWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LibrarianWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        LibrarianWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LibrarianWindow);
        statusbar->setObjectName("statusbar");
        LibrarianWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(titleInput, authorInput);
        QWidget::setTabOrder(authorInput, publicationInput);
        QWidget::setTabOrder(publicationInput, isbnInput);
        QWidget::setTabOrder(isbnInput, genreInput);
        QWidget::setTabOrder(genreInput, ratingInput);
        QWidget::setTabOrder(ratingInput, dewyInput);
        QWidget::setTabOrder(dewyInput, chooseItem);
        QWidget::setTabOrder(chooseItem, catalogueDisplay);
        QWidget::setTabOrder(catalogueDisplay, removeItemButton_2);
        QWidget::setTabOrder(removeItemButton_2, signoutButton);
        QWidget::setTabOrder(signoutButton, addItemButton);
        QWidget::setTabOrder(addItemButton, removeItemButton);
        QWidget::setTabOrder(removeItemButton, pReturnButton);
        QWidget::setTabOrder(pReturnButton, addButton);
        QWidget::setTabOrder(addButton, yearPubInput);
        QWidget::setTabOrder(yearPubInput, issueInput);
        QWidget::setTabOrder(issueInput, dayPubInput);
        QWidget::setTabOrder(dayPubInput, monthPubInput);

        retranslateUi(LibrarianWindow);

        stackedWidget->setCurrentIndex(0);
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
        titleLabel->setText(QCoreApplication::translate("LibrarianWindow", "Title:", nullptr));
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

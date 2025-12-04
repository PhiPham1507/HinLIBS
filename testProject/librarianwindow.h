#ifndef LIBRARIANWINDOW_H
#define LIBRARIANWINDOW_H

#include <QMainWindow>
#include "datacontroller.h"
namespace Ui {
class LibrarianWindow;
}

class LibrarianWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LibrarianWindow(QWidget *parent = nullptr);
    ~LibrarianWindow();
    void setname(const QString& user);
    void setController(DataController* con);
    void hideWhenDefault();
    void showWhenChosen();
    void clearInputs();
    void refreshCatalogueContents();
    void showReturnForPatron();
    void returnForPatronClicked();

    void searchForPatronButtonClicked();
    void refreshPatronTargetLoans();

private:
    Ui::LibrarianWindow *ui;
    DataController* controller;
    int selectedItemIndex, selectedPatronReturnId;
    Patron* currentPatronTarget;

signals:
    void signOut();

private slots:
    void signOutRequest();
    void chooseAccordingForm(int index);
    void removeItem();
    void addItem();
};

#endif // LIBRARIANWINDOW_H

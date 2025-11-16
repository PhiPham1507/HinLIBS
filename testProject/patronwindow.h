#ifndef PATRONWINDOW_H
#define PATRONWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include "datacontroller.h"

namespace Ui {
class PatronWindow;
}

class PatronWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PatronWindow(QWidget *parent = nullptr);
    ~PatronWindow();
    void setname(const QString& user);
    void setController(DataController* dc);

    void viewAccountButtonSelected();
    void catalogueButtonSelected();
    void refreshCatalogueContents();
    void refreshAccountContents();

private:
    Ui::PatronWindow *ui;
    DataController* controller;
    int selectedItemIndex;
    int selectedLoanIndex;
    int selectedHoldIndex;


signals:
    void signOut();

private slots:
    void signOutRequest();
    void checkOut();
    void placeHold();
    void checkIn();
    void cancelHold();

};

#endif // PATRONWINDOW_H

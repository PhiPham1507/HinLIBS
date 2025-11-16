#ifndef PATRONWINDOW_H
#define PATRONWINDOW_H

#include <QMainWindow>
#include <QPushButton>
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
    QPushButton* addEntryToCatalogue(const QString& text);

private:
    Ui::PatronWindow *ui;
    DataController* controller;
    vector<QPushButton*> catalogueEntries;
    vector<int> catalogueEntryIds;
    int selectedIndex;


signals:
    void signOut();

private slots:
    void signOutRequest();
    void checkOut();
    void placeHold();
    //void checkIn();

    //void cancelHold();

};

#endif // PATRONWINDOW_H

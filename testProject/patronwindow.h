#ifndef PATRONWINDOW_H
#define PATRONWINDOW_H

#include <QMainWindow>
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
    void addEntryToCatalogue(const QString& name);

private:
    Ui::PatronWindow *ui;
    DataController* controller;


signals:
    void signOut();

private slots:
    void signOutRequest();
    void checkOut();
    //void checkIn();
    //void placeHold();
    //void cancelHold();

};

#endif // PATRONWINDOW_H

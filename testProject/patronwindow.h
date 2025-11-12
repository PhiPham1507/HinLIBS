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

    void viewAccountButtonSelected();
    void catalogueButtonSelected();
    void refreshCatalogueContents();
    void addEntryToCatalogue(const QString& name);

private:
    Ui::PatronWindow *ui;
    DataController* dataController; // TODO: assign this

signals:
    void signOut();

private slots:
    void signOutRequest();

};

#endif // PATRONWINDOW_H

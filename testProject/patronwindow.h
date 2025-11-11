#ifndef PATRONWINDOW_H
#define PATRONWINDOW_H

#include <QMainWindow>

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

private:
    Ui::PatronWindow *ui;

signals:
    void signOut();

private slots:
    void signOutRequest();

};

#endif // PATRONWINDOW_H

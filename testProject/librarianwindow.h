#ifndef LIBRARIANWINDOW_H
#define LIBRARIANWINDOW_H

#include <QMainWindow>

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

private:
    Ui::LibrarianWindow *ui;

signals:
    void signOut();

private slots:
    void signOutRequest();

};

#endif // LIBRARIANWINDOW_H

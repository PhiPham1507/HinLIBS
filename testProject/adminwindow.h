#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();
    void setname(const QString& user);

private:
    Ui::AdminWindow *ui;

signals:
    void signOut();

private slots:
    void signOutRequest();
};

#endif // ADMINWINDOW_H

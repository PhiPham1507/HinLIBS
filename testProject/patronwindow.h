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

private:
    Ui::PatronWindow *ui;
};

#endif // PATRONWINDOW_H

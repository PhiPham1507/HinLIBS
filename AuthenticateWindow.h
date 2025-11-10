#ifndef AUTHENTICATEWINDOW_H
#define AUTHENTICATEWINDOW_H

#include <QMainWindow>

#include "Authenticator.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class AuthenticateWindow : public QMainWindow
{
    Q_OBJECT

public:
    AuthenticateWindow(QWidget *parent = nullptr);
    ~AuthenticateWindow();

    void handleLoginClick();

private:
    Ui::MainWindow* ui;
};
#endif // AUTHENTICATEWINDOW_H

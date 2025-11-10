#include "AuthenticateWindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

// This is called before program exit to clean up class memory
void cleanupClassDebris()
{
    Authenticator::cleanup();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "MyProject_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    AuthenticateWindow w;
    w.show();

    int authenticateWindowLoop = a.exec();

    cleanupClassDebris();
    return authenticateWindowLoop;
}

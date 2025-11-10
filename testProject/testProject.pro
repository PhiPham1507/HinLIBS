QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Account.cpp \
    AccountDatabase.cpp \
    Authenticator.cpp \
    book.cpp \
    fictionBook.cpp \
    item.cpp \
    magazine.cpp \
    main.cpp \
    mainwindow.cpp \
    movie.cpp \
    nonFictionBook.cpp \
    videoGame.cpp

HEADERS += \
    Account.h \
    AccountDatabase.h \
    Authenticator.h \
    book.h \
    fictionBook.h \
    item.h \
    magazine.h \
    mainwindow.h \
    movie.h \
    nonFictionBook.h \
    videoGame.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

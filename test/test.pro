#-------------------------------------------------
#
# Project created by QtCreator 2018-04-10T09:20:44
#
#-------------------------------------------------

include(/home/pi/QT_Project/Widgetkeyboard/src/WidgetKeyboard.pri)

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    readerdialog.cpp \
    controlmesin.cpp \
    socketconnectelm.cpp \
    dialogcardreader.cpp \
    pendaftaranwindow.cpp \
    tapcard_window.cpp \
    loginwindow.cpp

HEADERS += \
        mainwindow.h \
    readerdialog.h \
    controlmesin.h \
    socketconnectelm.h \
    dialogcardreader.h \
    pendaftaranwindow.h \
    tapcard_window.h \
    loginwindow.h

FORMS += \
        mainwindow.ui \
    readerdialog.ui \
    controlmesin.ui \
    dialogcardreader.ui \
    pendaftaranwindow.ui \
    tapcard_window.ui \
    loginwindow.ui

RESOURCES += \
    resouces.qrc

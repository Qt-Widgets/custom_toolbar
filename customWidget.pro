#-------------------------------------------------
#
# Project created by QtCreator 2015-02-19T17:32:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = customWidget
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    customtoolbar.cpp \
    ribbontoolbar.cpp \
    custommainwindow.cpp

HEADERS  += widget.h \
    customtoolbar.h \
    ribbontoolbar.h \
    custommainwindow.h

FORMS    +=

RESOURCES += \
    icons.qrc
CONFIG += c++11

DISTFILES +=

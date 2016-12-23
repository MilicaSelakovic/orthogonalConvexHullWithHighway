QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HighwayConvexHullL1
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
        cluster.cpp \
        segment.cpp \
        timehull.cpp \
    drawarea.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
            cluster.h \
            segment.h \
            timehull.h \
    drawarea.h \
    dialog.h

FORMS    += mainwindow.ui \
    dialog.ui

RESOURCES += \
    recources.qrc

DISTFILES += \
    pointInputExample.txt

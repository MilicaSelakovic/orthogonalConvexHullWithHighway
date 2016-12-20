#-------------------------------------------------
#
# Project created by QtCreator 2016-12-19T21:38:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HighwayConvexHullL1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        cluster.cpp \
        segment.cpp \
        timehull.cpp \
    drawarea.cpp

HEADERS  += mainwindow.h \
            cluster.h \
            segment.h \
            timehull.h \
    drawarea.h

FORMS    += mainwindow.ui

RESOURCES += \
    recources.qrc

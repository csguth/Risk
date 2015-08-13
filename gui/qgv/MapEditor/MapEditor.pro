#-------------------------------------------------
#
# Project created by QtCreator 2013-04-17T09:06:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MapEditor
TEMPLATE = app
CONFIG += c++11

DESTDIR = ../bin

#QGVCore librairie
LIBS += -L$$OUT_PWD/../lib -lQGVCore
INCLUDEPATH += $$PWD/../QGVCore
DEPENDPATH += $$PWD/../QGVCore

#GraphViz librairie
!include(../QGVCore/GraphViz.pri) {
     error("fail open GraphViz.pri")
 }

SOURCES += main.cpp\
        MainWindow.cpp \
    QGraphicsViewEc.cpp

HEADERS  += MainWindow.h \
    QGraphicsViewEc.h

FORMS    += MainWindow.ui

unix: LIBS += -L$$PWD/../../../src/map/ -lriskmap

INCLUDEPATH += $$PWD/../../../src
DEPENDPATH += $$PWD/../../../src

unix: PRE_TARGETDEPS += $$PWD/../../../src/map/libriskmap.a

DISTFILES += \
    CMakeLists.txt

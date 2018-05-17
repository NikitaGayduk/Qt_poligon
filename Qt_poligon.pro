QT += core
QT -= gui
QT += widgets
QT += sql

CONFIG += c++11

TARGET = Qt_poligon
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    firstwidget.cpp

HEADERS += \
    firstwidget.h

FORMS += \
    firstwidget.ui

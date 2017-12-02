#-------------------------------------------------
#
# Project created by QtCreator 2015-11-13T13:00:43
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QT_OpenGL
TEMPLATE = app

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    owidget.cpp \
    fwidget.cpp

HEADERS  += mainwindow.h \
    owidget.h \
    fwidget.h \
    ovector.h

FORMS    += mainwindow.ui

LIBS += -lglut -lGLU

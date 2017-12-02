#-------------------------------------------------
#
# Project created by QtCreator 2017-10-14T14:33:25
#
#-------------------------------------------------

QT       += core gui opengl



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MatrizTransformada
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp

HEADERS  += mainwindow.h \
    glwidget.h

FORMS    += mainwindow.ui

LIBS += -lglut

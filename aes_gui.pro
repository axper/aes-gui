#-------------------------------------------------
#
# Project created by QtCreator 2013-05-06T17:00:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = aes_gui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
		aes.cpp \
		aes_lookup_tables.cpp

HEADERS  += mainwindow.h \
		aes.h

FORMS    += mainwindow.ui

#-------------------------------------------------
#
# Project created by QtCreator 2013-11-01T16:59:00
#
#-------------------------------------------------

QT       += core gui phonon network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TTSPlayer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    lineedit.cpp \
    tts.cpp

HEADERS  += mainwindow.h \
    lineedit.h \
    tts.h

FORMS    += mainwindow.ui

RESOURCES += \
    dic.qrc

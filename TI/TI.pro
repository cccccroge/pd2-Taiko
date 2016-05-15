#-------------------------------------------------
#
# Project created by QtCreator 2016-05-10T21:15:54
#
#-------------------------------------------------

QT       += core gui\
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TI
TEMPLATE = app


SOURCES += main.cpp\
        start.cpp \
    drum.cpp \
    scores.cpp

HEADERS  += start.h \
    drum.h \
    scores.h

FORMS    += start.ui \
    dialog.ui

RESOURCES += \
    rsc.qrc

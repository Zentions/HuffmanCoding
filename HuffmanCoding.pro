#-------------------------------------------------
#
# Project created by QtCreator 2017-07-07T07:59:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HuffmanCoding
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    huffmantree.cpp \
    minheap.cpp \
    encodermachine.cpp \
    decodemachine.cpp \
    mydrawing.cpp

HEADERS  += mainwindow.h \
    huffmantree.h \
    minheap.h \
    encodermachine.h \
    decodemachine.h \
    mydrawing.h

FORMS    += mainwindow.ui \
    mydrawing.ui

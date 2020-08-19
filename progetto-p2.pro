#-------------------------------------------------
#
# Project created by QtCreator 2020-06-30T11:32:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = progetto-p2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        insertionwidget.cpp \
        Modello/modello.cpp \
        Modello/Gerarchia/prodotto.cpp \
        Modello/Gerarchia/cosmetico.cpp \
        Modello/Gerarchia/alimentare.cpp \
        Modello/Gerarchia/integratore.cpp \
        Modello/Gerarchia/vivanda.cpp \
        Modello/Gerarchia/olioEssenziale.cpp \
    mainwindow.cpp \
    listview.cpp \
    listmodeladapter.cpp \
    qfilterproxymodel.cpp

HEADERS += \
        insertionwidget.h \
        Modello/modello.h \
        Modello/container.h \
        Modello/smartp.h \
        Modello/Gerarchia/prodotto.h \
        Modello/Gerarchia/cosmetico.h \
        Modello/Gerarchia/alimentare.h \
        Modello/Gerarchia/integratore.h \
        Modello/Gerarchia/vivanda.h \
        Modello/Gerarchia/olioEssenziale.h \
    mainwindow.h \
    listview.h \
    listmodeladapter.h \
    qtypeconversion.h \
    qfilterproxymodel.h

FORMS += \
        widget.ui

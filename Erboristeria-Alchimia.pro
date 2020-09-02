#-------------------------------------------------
#
# Project created by QtCreator 2020-08-27T17:34:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Erboristeria-Alchimia
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
    mainwindow.cpp \
    qfilterproxymodel.cpp \
    insertwidget.cpp \
    Modello/Gerarchia/alimentare.cpp \
    Modello/Gerarchia/cosmetico.cpp \
    Modello/Gerarchia/integratore.cpp \
    Modello/Gerarchia/olioEssenziale.cpp \
    Modello/Gerarchia/prodotto.cpp \
    Modello/Gerarchia/vivanda.cpp \
    Modello/modello.cpp \
    tableview.cpp \
    tablemodeladapter.cpp \
    combobox_items.cpp \
    combobox_target.cpp \
    combobox_sn.cpp \
    fileio.cpp

HEADERS += \
    mainwindow.h \
    qfilterproxymodel.h \
    insertwidget.h \
    Modello/Gerarchia/alimentare.h \
    Modello/Gerarchia/cosmetico.h \
    Modello/Gerarchia/integratore.h \
    Modello/Gerarchia/olioEssenziale.h \
    Modello/Gerarchia/prodotto.h \
    Modello/Gerarchia/vivanda.h \
    Modello/container.h \
    Modello/modello.h \
    Modello/smartp.h \
    tableview.h \
    tablemodeladapter.h \
    combobox_items.h \
    combobox_target.h \
    combobox_sn.h \
    fileio.h

RESOURCES += \
    resources.qrc

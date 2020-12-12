TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        disp_defensive.cpp \
        disp_ofensivo.cpp \
        main.cpp

HEADERS += \
    Imprimir+estructura.h \
    disp_defensive.h \
    disp_ofensivo.h

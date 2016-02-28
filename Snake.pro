TEMPLATE = app
CONFIG += console c++11 opengl
CONFIG -= app_bundle
CONFIG -= qt


QT += opengl

LIBS += -lglut
LIBS += -L/usr/local/lib -lGLU

INCLUDEPATH += -L/usr/lib/


SOURCES += main.cpp \
    Block.cpp \
    Food.cpp \
    Snake.cpp

HEADERS += \
    Settings.h \
    Food.h \
    Block.h \
    Snake.h

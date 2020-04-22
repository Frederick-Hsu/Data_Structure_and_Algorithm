TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Main.cpp \
    ThreadRAII.cpp \
    WorkerThread.cpp

HEADERS += \
    ThreadRAII.h \
    WorkerThread.h

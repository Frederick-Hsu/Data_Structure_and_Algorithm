TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += /home/frederique_hsu/boost_1_72_0

SOURCES += \
    join_detach_thread.cpp \
    program.cpp \
    thread_creation.cpp

HEADERS += \
    join_detach_thread.h \
    thread_creation.h

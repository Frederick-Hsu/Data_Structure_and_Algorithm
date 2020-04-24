TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Fraction.cpp \
        Shared_Ptr.cpp \
        main.cpp \
        testing.cpp

HEADERS += \
    Fraction.h \
    Shared_Ptr.h \
    functors.h \
    list_iterator.h \
    template_functor.h \
    testing.h \
    unary_binary_functions.h

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Screen.cpp \
        bit_field/File.cpp \
        main.cpp \
        nested_type/Outer.cpp \
        testing.cpp \
        types.cpp \
        union_type/TokenValue.cpp

HEADERS += \
    Screen.h \
    bit_field/File.h \
    nested_type/Outer.h \
    nested_type/Queue.h \
    testing.h \
    types.h \
    union_type/TokenValue.h

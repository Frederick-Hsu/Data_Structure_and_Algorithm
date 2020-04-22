#-------------------------------------------------
#
# Project created by QtCreator 2019-10-06T03:43:37
#
#-------------------------------------------------

QT       -= core
#gui

TARGET = Handle
TEMPLATE = lib

DEFINES += HANDLE_LIBRARY

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
        Basket.cpp \
        Bulk_item.cpp \
        Disc_item.cpp \
        Handle.cpp \
        Item_base.cpp \
        Sales_item.cpp

HEADERS += \
        Basket.h \
        Bulk_item.h \
        Disc_item.h \
        Handle.h \
        Item_base.h \
        Sales_item.h \
        handle_global.h 

unix {
    target.path = /usr/lib
    INSTALLS += target
}

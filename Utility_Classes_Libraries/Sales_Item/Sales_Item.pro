#-------------------------------------------------
#
# Project created by QtCreator 2019-09-08T03:27:26
#
#-------------------------------------------------

QT       -= core gui

TARGET = Sales_Item
TEMPLATE = lib
CONFIG += staticlib

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
        Folder.cpp \
        GT_calculations.cpp \
        Message.cpp \
        Sales_item.cpp \
        Screen.cpp \
        ScreenPtr.cpp \
        SmallInt.cpp \
        Window_Mgr.cpp \
        exceptions.cpp \
        misc.cpp

HEADERS += \
        Folder.h \
        GT_calculations.h \
        Message.h \
        Sales_item.h \
        Screen.h \
        ScreenPtr.h \
        SmallInt.h \
        Window_Mgr.h \
        exceptions.h \
        misc.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

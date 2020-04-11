TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ../Pointers_in_Class/HasPtr.cpp \
        ../Sales_Item/GT_calculations.cpp \
        ../Sales_Item/Sales_item.cpp \
        ../Sales_Item/Screen.cpp \
        ../Sales_Item/ScreenPtr.cpp \
        ../Sales_Item/SmallInt.cpp \
        main.cpp \
        testing_pointers_in_class.cpp \
        unit_testing.cpp

HEADERS += \
    ../Pointers_in_Class/HasPtr.h \
    ../Sales_Item/GT_calculations.h \
    ../Sales_Item/Sales_item.h \
    ../Sales_Item/Screen.h \
    ../Sales_Item/ScreenPtr.h \
    ../Sales_Item/SmallInt.h \
    testing_pointers_in_class.h \
    unit_testing.h

TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lgtest -lpthread

SOURCES += \
        Sorting.cpp \
        heap_sort/test_heap_sort.c++ \
        insertion_sort/test_insertion_sort.c++ \
        main.cpp \
        quick_sort/test_quick_sort.c++ \
        shell_sort/test_shell_sort.cpp

HEADERS += \
    Sorting.hpp \
    heap_sort/heap_sort.hpp \
    heap_sort/test_heap_sort.h++ \
    insertion_sort/insertion_sort.hpp \
    insertion_sort/test_insertion_sort.h++ \
    quick_sort/quick_sort.hpp \
    quick_sort/test_quick_sort.h++ \
    shell_sort/shell_sort.hpp \
    shell_sort/test_shell_sort.hpp

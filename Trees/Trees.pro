TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lgtest

SOURCES += \
        Adelson_Velskii_Landis_Tree/test_AVL_Tree.c++ \
        binary_search_tree/test_binary_search_tree.c++ \
        binary_search_tree/tree.c \
        binary_search_tree/utest_binary_search_tree.cxx \
        main.cpp

HEADERS += \
    Adelson_Velskii_Landis_Tree/AVL_Tree.hpp \
    Adelson_Velskii_Landis_Tree/AVL_Tree_impl.hpp \
    Adelson_Velskii_Landis_Tree/test_AVL_Tree.h++ \
    binary_search_tree/binary_serach_tree.hpp \
    binary_search_tree/binary_serach_tree_impl.hpp \
    binary_search_tree/element.h \
    binary_search_tree/test_binary_search_tree.h++ \
    binary_search_tree/tree.h \
    binary_search_tree/utest_binary_search_tree.hxx

DISTFILES += \
    Adelson_Velskii_Landis_Tree/AVL_Tree.py

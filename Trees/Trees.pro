TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lgtest

SOURCES += \
        Adelson_Velskii_Landis_Tree/test_AVL_Tree.c++ \
        BTree/btree_node.c \
        binary_search_tree/test_binary_search_tree.c++ \
        binary_search_tree/tree.c \
        binary_search_tree/utest_binary_search_tree.cxx \
        main.cpp \
        map/test_map.c++ \
        map/utilize_map.cpp \
        set/test_set.c++

HEADERS += \
    Adelson_Velskii_Landis_Tree/AVL_Tree.hpp \
    Adelson_Velskii_Landis_Tree/AVL_Tree_impl.hpp \
    Adelson_Velskii_Landis_Tree/test_AVL_Tree.h++ \
    BTree/btree_node.h \
    binary_search_tree/binary_serach_tree.hpp \
    binary_search_tree/binary_serach_tree_impl.hpp \
    binary_search_tree/element.h \
    binary_search_tree/test_binary_search_tree.h++ \
    binary_search_tree/tree.h \
    binary_search_tree/utest_binary_search_tree.hxx \
    map/utilize_map.hpp

DISTFILES += \
    Adelson_Velskii_Landis_Tree/AVL_Tree.py

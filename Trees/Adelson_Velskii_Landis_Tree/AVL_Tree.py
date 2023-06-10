# File name     : AVL_Tree.py
# Description   : Define the structure of AVL tree in Python.
# Author        : Frederique Hsu
# Date          : Sun.  23 Apr. 2023
#

from typing import Optional

class AVLTreeNode:
    def __init__(self, element):
        self.__element = element
        self.__height : int = 0
        self.__left : Optional[AVLTreeNode] = None
        self.__right : Optional[AVLTreeNode] = None

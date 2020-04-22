/**************************************************************************************************
 * File name    : genListStack.h
 * Description  : generic stack defined as a doubly linked list.
 * Creator      : Frederick Hsu
 * Creation date: Fri.  11 Oct. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/

#ifndef GEN_LIST_STACK_H
#define GEN_LIST_STACK_H

    #include <list>
    using namespace std;

    template<class Type>
    class LLStack
    {
    public:
        LLStack();
        void clear();
        bool isEmpty() const;
        Type& topElement();
        Type pop();
        void push(const Type& element);
        size_t countOfElements();
    private:
        list<Type> lst;
    };

    /*============================================================================================*/

    template<class Type> LLStack<Type>::LLStack()
    {
    }

    template<class Type> void LLStack<Type>::clear()
    {
        lst.clear();
    }

    template<class Type> bool LLStack<Type>::isEmpty() const
    {
        return lst.empty();
    }

    template<class Type> Type& LLStack<Type>::topElement()
    {
        return lst.back();
    }

    template<class Type> Type LLStack<Type>::pop()
    {
        Type element = topElement();
        lst.pop_back();
        return element;
    }

    template<class Type> void LLStack<Type>::push(const Type& element)
    {
        lst.push_back(element);
    }

    template<class Type> size_t LLStack<Type>::countOfElements()
    {
        return lst.size();
    }
#endif  /* GEN_LIST_STACK_H */

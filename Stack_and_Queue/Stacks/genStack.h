/**************************************************************************************************
 * File name	: genStack.h
 * Description	: generic class for vector implementation of stack.
 * Creator		: Frederick Hsu
 * Creation date: Mon.	05 Aug.	2019
 * Copyright(C)	2019	All rights reserved.
 *
 **************************************************************************************************/

#ifndef GENSTACK_H
#define GENSTACK_H

	#include <vector>
	using namespace std;

	template<class T, int capacity = 30>
	class Stack
	{
	public:
        Stack();
		void clear();
        bool isEmpty() const;
        T& topElement();
        T pop();
        void push(const T& element);
	private:
		vector<T> pool;
	};

	/*===============================================================================================*/

    template<class T, int capacity> Stack<T, capacity>::Stack()
    {
        pool.reserve(capacity);
    }

    template<class T, int capacity> void Stack<T, capacity>::clear()
    {
        pool.clear();
    }

    template<class T, int capacity> bool Stack<T, capacity>::isEmpty() const
    {
        return pool.empty();
    }

    template<class T, int capacity> T& Stack<T, capacity>::topElement()
    {
        return pool.back();
    }

    template<class T, int capacity> T Stack<T, capacity>::pop()
    {
        T element = topElement();
        pool.pop_back();
        return element;
    }

    template<class T, int capacity> void Stack<T, capacity>::push(const T& element)
    {
        pool.push_back(element);
    }

#endif	/* GENSTACK_H */

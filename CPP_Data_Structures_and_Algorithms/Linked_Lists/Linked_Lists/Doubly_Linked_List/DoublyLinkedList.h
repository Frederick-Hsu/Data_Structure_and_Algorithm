/*************************************************************************************************
 * File name    : DoublyLinkedList.h
 * Description  : Define the Doubly_Linked_List data structure and its template class.
 * Creator      : Frederick Hsu
 * Creation date: Mon.	4 July, 2016
 * Copyright(C) 2016    All rights reserved.
 *
 *************************************************************************************************/

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

	#include <cstdlib>
	#include <cstdio>
	#include <string.h>
	#include <iostream>

	using namespace std;

	template<class T> class DoublyLinkedListNode;
	template<class T> class DoubblyLinkedList;

	template<class T>
	class DoublyLinkedListNode
	{
	private:
	public:
		T info;
		DoublyLinkedListNode *prev;
		DoublyLinkedListNode *next;

		DoublyLinkedListNode(void);
		DoublyLinkedListNode(const T& elem,
                             DoublyLinkedListNode *successor = NULL,
                             DoublyLinkedListNode *predecessor = NULL);
		~DoublyLinkedListNode(void);

		void setNodeInfo(T& elem);
		T& getNodeInfo(void);
		void printNodesChain(void);
	protected:
	};

	template<> DoublyLinkedListNode<const char*>::DoublyLinkedListNode(const char* const &elem,
																	   DoublyLinkedListNode<const char*> *successor,
																	   DoublyLinkedListNode<const char*> *predecessor);
	template<> DoublyLinkedListNode<const char*>::~DoublyLinkedListNode(void);
	template<> void DoublyLinkedListNode<const char*>::setNodeInfo(const char* &elem);

	// template<class T> void operator=(DoublyLinkedList<T> &assignedList, const DoublyLinkedList<T> &originList);

	template<class T>
	class DoublyLinkedList
	{
	private:
	public:
		DoublyLinkedList(void);
		DoublyLinkedList(T& elem);
		DoublyLinkedList(const DoublyLinkedList<T>& list);
		DoublyLinkedList<T>& operator=(const DoublyLinkedList<T> &originList);
        // friend void operator=(DoublyLinkedList<T> &assignedList, const DoublyLinkedList<T> &originList);
		~DoublyLinkedList(void);

        void addToDoublyLinkedListHead(T& elem);
		void addToDoublyLinkedListTail(T& elem);
		T deleteFromDoublyLinkedListTail(void);
		T deleteFromDoublyLinkedListHead(void);
		int numberOfNodes(void);
		void insertNewNodeBeforePositionN(T& elem, int n);
		void insertNewNodeAfterPositionN(T& elem, int n);
		T deleteNodeOfPositionN(int n);
		T getElementOfPositionN(int n);
		DoublyLinkedListNode<T>* getNodeOfPositionN(int N);
		void setElementOfPositionN(T& elem, int n);
		int getPositionOfSpecificElem(T& specificElem);
		void exchangeHeadWithAnotherNode(int posN2);
		void exchangeTailWithAnotherNode(int posN1);
		void exchangeHeadWithTail(void);
		void exchangePositionBetween2Nodes(int posN1, int posN2);
		int doStatCountsForSpecificElem(T& specificElem);

        void printDoublyLinkedList(void);
	protected:
		DoublyLinkedListNode<T> *head;
		DoublyLinkedListNode<T> *tail;
	};

	/*********************************************************************************************/

	template<class T>
	DoublyLinkedListNode<T>::DoublyLinkedListNode(void)
	{
		prev = NULL;
		next = NULL;
	}

	template<class T>
	DoublyLinkedListNode<T>::DoublyLinkedListNode(const T& elem,
	                                              DoublyLinkedListNode *successor,
	                                              DoublyLinkedListNode *predecessor)
	{
		info = elem;
		prev = predecessor;
		next = successor;
	}

	template<class T>
	DoublyLinkedListNode<T>::~DoublyLinkedListNode(void)
	{
		prev = NULL;
		next = NULL;
	}

	template<class T>
	void DoublyLinkedListNode<T>::setNodeInfo(T& elem)
	{
		info = elem;
	}

	template<>
	void DoublyLinkedListNode<const char*>::setNodeInfo(const char* &elem)
	{
		if (strlen(elem) != 0)
		{
			info = new char[strlen(elem) + 1];
            memcpy(&info, &elem, strlen(elem)+1);
		}
	}

	template<class T>
	T& DoublyLinkedListNode<T>::getNodeInfo(void)
	{
		return info;
	}

	template<>
	DoublyLinkedListNode<const char*>::DoublyLinkedListNode(const char* const &elem,
															DoublyLinkedListNode<const char*> *successor,
															DoublyLinkedListNode<const char*> *predecessor)
	{
		int len = strlen(elem);
		if (len != 0)
		{
			info = new char[len+1];
			memcpy(&info, elem, len+1);
		}
		next = successor;
		prev = predecessor;
	}

	template<>
	DoublyLinkedListNode<const char*>::~DoublyLinkedListNode(void)
	{
		int len = strlen(info);
		if (len != 0)
		{
			delete info;
		}
		prev = NULL;
		next = NULL;
	}

	template<class T>
	DoublyLinkedList<T>::DoublyLinkedList(void)
	{
	    head = NULL;
	    tail = NULL;
	}

	template<class T>
	DoublyLinkedList<T>::DoublyLinkedList(T& elem)
	{
		head = new DoublyLinkedListNode<T>(elem);
		tail = head;
	}

	template<class T>
	DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& list)
	{
		DoublyLinkedListNode<T> *pExternalListNode = list.head;
		DoublyLinkedListNode<T> *pSelfListNode = new DoublyLinkedListNode<T>(pExternalListNode->info);
		head = pSelfListNode;
        
		pExternalListNode = pExternalListNode->next;
        while (pExternalListNode != NULL)
        {
        	pSelfListNode->next = new DoublyLinkedListNode<T>(pExternalListNode->info, NULL, pSelfListNode);
        	pSelfListNode = pSelfListNode->next;
        	pExternalListNode = pExternalListNode->next;
        }
        tail = pSelfListNode;
	}

	template<class T>
	DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T> &originList)
	{
		this->head = originList.head;
		this->tail = originList.tail;
		return *this;
	}

	template<class T>
	DoublyLinkedList<T>::~DoublyLinkedList(void)
	{
	    DoublyLinkedListNode<T> *pNode = head;
	    while (pNode != NULL)
	    {
	        pNode = head->next;
	        delete head;
	        head = pNode;
	    }
	    head = NULL;
	    tail = NULL;
	}

	template<class T>
	void DoublyLinkedList<T>::addToDoublyLinkedListHead(T& elem)
	{
	    if (head == NULL)   // DoublyLinkedList is empty
	    {
	        head = new DoublyLinkedListNode<T>(elem);
	        head->prev = NULL;
	        head->next = NULL;

	        tail = head;
	    }
	    else
	    {
            head = new DoublyLinkedListNode<T>(elem, head, NULL);
            (head->next)->prev = head;
        }
	}

	template<class T>
	void DoublyLinkedList<T>::addToDoublyLinkedListTail(T& elem)
	{
	    if (tail == NULL)
	    {
	        tail = new DoublyLinkedListNode<T>(elem);
	        tail->prev = NULL;
	        tail->next = NULL;

	        head = tail;
	    }
	    else
	    {
#if 0
            /* 不能使用此种新建一个结点的方法，它会导致结点之间无法连接起来。 */
	    	DoublyLinkedListNode<T> *pNewNode = new DoublyLinkedListNode<T>(elem);
	    	pNewNode->next = NULL;
	    	pNewNode->prev = tail;
	    	tail = pNewNode;
#else
            tail = new DoublyLinkedListNode<T>(elem, NULL, tail);
            (tail->prev)->next = tail;
#endif
	    }
	}

	template<class T>
	void DoublyLinkedList<T>::printDoublyLinkedList(void)
	{
	    DoublyLinkedListNode<T> *pNode = head;
	    std::printf(" Prev. node		| Curr. node		| Data		| Next  node	\n");
	    std::printf("----------------------------------------------------------------------------------------------------\n");
	    while (pNode != NULL)
	    {
	    	std::printf(" 0x%016lX	| 0x%016lX	| ", pNode->prev, pNode);
	    	std::cout<<(pNode->info)<<"			| ";
	    	std::printf("0x%016lX	\n", pNode->next);
	    	std::printf("----------------------------------------------------------------------------------------------------\n");

	    	pNode = pNode->next;
	    }
	    std::printf("\n\n");
	}

	template<class T>
	void DoublyLinkedListNode<T>::printNodesChain(void)
	{
		DoublyLinkedListNode<T> *pNode = this;
		std::printf(" Prev. node		| Curr. node		| Data		| Next  node	\n");
		std::printf("----------------------------------------------------------------------------------------------------\n");
		while (pNode != NULL)
		{
			std::printf(" 0x%016lX	| 0x%016lX	| ", pNode->prev, pNode);
			std::cout<<(pNode->info)<<"			| ";
			std::printf("0x%016lX	\n", pNode->next);
			std::printf("----------------------------------------------------------------------------------------------------\n");

			pNode = pNode->next;
		}
		std::printf("\n\n");
	}

	template<class T>
	T DoublyLinkedList<T>::deleteFromDoublyLinkedListTail(void)
	{
		T elem = tail->info;
		if (head == NULL)
		{
			delete head;
			tail = NULL;
		}
		else
		{
			DoublyLinkedListNode<T> *pPrevNode = tail->prev;
			delete tail;
			tail = pPrevNode;
			tail->next = NULL;
		}
		return elem;
	}

	template<class T>
	T DoublyLinkedList<T>::deleteFromDoublyLinkedListHead(void)
	{
		T elem = head->info;
		if (head == tail)
		{
			delete head;
			tail = NULL;
		}
		else
		{
			DoublyLinkedListNode<T> *pNextNode = head->next;
			delete head;
			head = pNextNode;
			head->prev = NULL;
		}
		return elem;
	}

	template<class T>
	int DoublyLinkedList<T>::numberOfNodes(void)
	{
		int num = 0;
		DoublyLinkedListNode<T> *pNode = head;
		while (pNode != NULL)
		{
			num++;
			pNode = pNode->next;
		}
		return num;
	}

	template<class T>
	void DoublyLinkedList<T>::insertNewNodeBeforePositionN(T& elem, int n)
	{
		int num = numberOfNodes();
		if ((n>num) || (n <= 0))
		{
			std::cout<<"The position number you entered is wrong."<<std::endl
					 <<"Currently the list has total "<<num<<" nodes.\n"
					 <<"Please re-enter the position number."<<std::endl;
			return;
		}

        if (n == 1)
        {
            addToDoublyLinkedListHead(elem);
            return;
        }
		int pos;
		DoublyLinkedListNode<T> *pNode;
		if (n <= num/2)		// Search from the first half part
		{
			pos = 0;
			pNode = head;
			while (pNode != NULL)
			{
				pos++;
				if (pos == n)	// Move, until to position n
				{
					break;
				}
				pNode = pNode->next;
			}
			DoublyLinkedListNode<T> *pPrevNode = pNode->prev;	// node of position (n-1)
			DoublyLinkedListNode<T> *pNewNode = new DoublyLinkedListNode<T>(elem, pNode, pPrevNode);
			if (pNode != NULL)
                pNode->prev = pNewNode;
			if (pPrevNode != NULL)
                pPrevNode->next = pNewNode;
		}
		else
		{
			pos = num;
			pNode = tail;
			while (pNode != NULL)
			{
                if (pos == n)
                {
                    break;
                }
				pNode = pNode->prev;
				pos--;
			}
			DoublyLinkedListNode<T> *pPrevNode = pNode->prev;
			DoublyLinkedListNode<T> *pNewNode = new DoublyLinkedListNode<T>(elem, pNode, pPrevNode);
			if (pPrevNode != NULL)
                pPrevNode->next = pNewNode;
			if (pNode != NULL)
                pNode->prev = pNewNode;
		}
	}

	template<class T>
	void DoublyLinkedList<T>::insertNewNodeAfterPositionN(T& elem, int n)
	{
		int num = numberOfNodes();
		if ((n > num) || (n <= 0))
		{
			std::cout<<"The position number you entered is wrong"<<std::endl;
			return;
		}

        if (n == num)
        {
            addToDoublyLinkedListTail(elem);
            return;
        }
		int pos;
		DoublyLinkedListNode<T> *pNode;
		if (n <= num/2)
		{
			pos = 0;
			pNode = head;	// 从前半部分搜索，可将搜索次数减半
			while (pNode != NULL)
			{
				pos++;
				if (pos == n)
				{
					break;
				}
				pNode = pNode->next;	// Move to next node, from the head
			}
			DoublyLinkedListNode<T> *pNextNode = pNode->next, *pCurrNode = pNode;
			DoublyLinkedListNode<T> *pNewNode = new DoublyLinkedListNode<T>(elem, pNextNode, pCurrNode);
			if (pNextNode != NULL)
                pNextNode->prev = pNewNode;
			if (pCurrNode != NULL)
                pCurrNode->next = pNewNode;
		}
		else
		{
			pos = num;
			pNode = tail;	// 从后半部分搜索，亦可将搜索次数减半
			while (pNode != NULL)
			{
				pNode = pNode->prev;	// Move to previous node, from the tail
                pos--;
                if (pos == n)
                {
                    break;
                }
			}
			DoublyLinkedListNode<T> *pCurrNode = pNode, *pNextNode = pNode->next;
			DoublyLinkedListNode<T> *pNewNode = new DoublyLinkedListNode<T>(elem, pNextNode, pCurrNode);
			if (pCurrNode != NULL)
                pCurrNode->next = pNewNode;
			if (pNextNode != NULL)
                pNextNode->prev = pNewNode;
		}
	}

	template<class T>
	T DoublyLinkedList<T>::deleteNodeOfPositionN(int n)
	{
		T elem;
		int num = numberOfNodes();
		if ((n<=0) || (n>num))
		{
			std::cout<<"The position number you entered is wrong."<<std::endl;
			return 0;
		}
		if (n == 1)
		{
			elem = head->info;
			deleteFromDoublyLinkedListHead();
		}
		else if (n == num)
		{
			elem = tail->info;
			deleteFromDoublyLinkedListTail();
		}
		else
		{
			int pos;
			DoublyLinkedListNode<T> *pNode;
			if (n <= num/2)
			{
				pos = 0;
				pNode = head;
				while (pNode != NULL)
				{
					pos++;
					if (pos == n)
					{
						break;
					}
					pNode = pNode->next;
				}
			}
			else
			{
				pos = num;
				pNode = tail;
				while (pNode != NULL)
				{
					pNode = pNode->prev;
					pos--;
					if (pos == n)
					{
						break;
					}
				}
			}
			DoublyLinkedListNode<T> *pPrevNode = pNode->prev, *pNextNode = pNode->next;
			elem = pNode->info;
			delete pNode;
			pPrevNode->next = pNextNode;
			pNextNode->prev = pPrevNode;
		}
		return elem;
	}

	template<class T>
	T DoublyLinkedList<T>::getElementOfPositionN(int n)
	{
		int pos;
		int num = numberOfNodes();
		if ((n <= 0) || (n > num))
		{
			std::cout<<"The position number you entered is wrong."<<std::endl;
			return 0;
		}
		DoublyLinkedListNode<T> *pNode;
		if (n <= num/2)
		{
			pos = 0;
			pNode = head;
			while (pNode != NULL)
			{
				pos++;
				if (pos == n)
					break;
				pNode = pNode->next;
			}
		}
		else
		{
			pos = num;
			pNode = tail;
			while (pNode != NULL)
			{
				if (pos == n)
					break;
				pNode = pNode->prev;
				pos--;
			}
		}
		return (pNode->getNodeInfo());
	}

	template<class T>
	void DoublyLinkedList<T>::setElementOfPositionN(T& elem, int n)
	{
		int num = numberOfNodes();
		if ((n <= 0) || (n > num))
		{
			std::cout<<"The position number you entered is wrong."<<std::endl;
            return;
		}
		int pos;
		DoublyLinkedListNode<T> *pNode;
		if (n <= num/2)
		{
			pos = 0;
			pNode = head;
			while (pNode != NULL)
			{
				pos++;
				if (pos == n)
				{
					break;
				}
				pNode = pNode->next;
			}
		}
		else
		{
			pos = num;
			pNode = tail;
			while (pNode != NULL)
			{
				if (pos == n)
				{
					break;
				}
				pNode = pNode->prev;
				pos--;
			}
		}
		pNode->setNodeInfo(elem);
	}

	template<class T>
	DoublyLinkedListNode<T>* DoublyLinkedList<T>::getNodeOfPositionN(int n)
	{
		int num = numberOfNodes();
		if ((n <= 0) || (n > num))
		{
			std::cout<<"The position number you entered is wrong."<<std::endl;
			return NULL;
		}
		int pos;
		DoublyLinkedListNode<T> *pNode;
		if (n <= num/2)
		{
			pos = 0;
			pNode = head;
			while (pNode != NULL)
			{
				pos++;
				if (pos == n)
				{
					break;
				}
				pNode = pNode->next;
			}
		}
		else
		{
			pos = num;
			pNode = tail;
			while (pNode != NULL)
			{
				if (pos == n)
				{
					break;
				}
				pNode = pNode->prev;
				pos--;
			}
		}
		return pNode;
	}

	template<class T>
	void DoublyLinkedList<T>::exchangeHeadWithAnotherNode(int posN2)
	{
		int num = numberOfNodes();
		if ( ((posN2 == 1) || (posN2 == num)) ||
			 ((posN2 <= 0) || (posN2 > num)) )
		{
			std::cout<<"The position 2 number you entered is wrong."<<std::endl;
			return;
		}
		DoublyLinkedListNode<T> *pHead = head, *pHead_Successor = head->next;
		DoublyLinkedListNode<T> *pNode2 = getNodeOfPositionN(posN2), *pPrevNode2, *pNextNode2;
        pPrevNode2 = pNode2->prev;
        pNextNode2 = pNode2->next;

		pNode2->next = pHead_Successor;
		pNode2->prev = NULL;
		pHead_Successor->prev = pNode2;
		head = pNode2;

		pPrevNode2->next = pHead;
		pNextNode2->prev = pHead;
		pHead->next = pNextNode2;
		pHead->prev = pPrevNode2;
	}

	template<class T>
	void DoublyLinkedList<T>::exchangeTailWithAnotherNode(int posN1)
	{
		int num = numberOfNodes();
		if ( ((posN1 == 1) || (posN1 == num)) ||
			 ((posN1 <= 0) || (posN1 > num)) )
		{
			std::cout<<"The position 1 number you entered is wrong."<<std::endl;
			return;
		}

		DoublyLinkedListNode<T> *pTail = tail, *pTail_Predecessor = tail->prev;
		DoublyLinkedListNode<T> *pNode1 = getNodeOfPositionN(posN1), *pPrevNode1, *pNextNode1;
        pPrevNode1 = pNode1->prev;
        pNextNode1 = pNode1->next;

		pPrevNode1->next = pTail;
		pNextNode1->prev = pTail;
		pTail->prev = pPrevNode1;
		pTail->next = pNextNode1;

		pTail_Predecessor->next = pNode1;
		pNode1->prev = pTail_Predecessor;
		pNode1->next = NULL;
		tail = pNode1;
	}

	template<class T>
	void DoublyLinkedList<T>::exchangeHeadWithTail(void)
	{
		DoublyLinkedListNode<T> *pHead = head, *pHead_Successor = head->next,
								*pTail = tail, *pTail_Predecessor = tail->prev;
		pTail_Predecessor->next = pHead;
		pHead->next = NULL;
		pHead->prev = pTail_Predecessor;
		tail = pHead;

		pHead_Successor->prev = pTail;
		pTail->prev = NULL;
		pTail->next = pHead_Successor;
		head = pTail;
	}

	template<class T>
	void DoublyLinkedList<T>::exchangePositionBetween2Nodes(int posN1, int posN2)
	{
		int num = numberOfNodes();
		if ((posN1 <= 0) || (posN1 > num))
		{
			std::cout<<"The position 1 number you entered is wrong."<<std::endl;
			return;
		}
		if ((posN2 <= 0) || (posN2 > num))
		{
			std::cout<<"The position 2 number you entered is wrong."<<std::endl;
			return;
		}

		if ((posN1 ==1) && (posN2 != num))
		{
			exchangeHeadWithAnotherNode(posN2);
		}
		else if ((posN1 != 1) && (posN2 == num))
		{
			exchangeTailWithAnotherNode(posN1);
		}
        else if ((posN1 == num) && (posN2 != 1))
        {
            exchangeTailWithAnotherNode(posN2);
        }
        else if ( ((posN1 == 1) && (posN2 == num)) ||
                 ((posN1 == num) && (posN2 == 1)) )
        {
            exchangeHeadWithTail();
        }
		else if ((posN1 != 1) && (posN2 != num))
		{
			DoublyLinkedListNode<T> *pNode1 = getNodeOfPositionN(posN1), *pPrevNode1, *pNextNode1;
			DoublyLinkedListNode<T> *pNode2 = getNodeOfPositionN(posN2), *pPrevNode2, *pNextNode2;
			pPrevNode1 = pNode1->prev;
			pNextNode1 = pNode1->next;
			pPrevNode2 = pNode2->prev;
			pNextNode2 = pNode2->next;

			// Exchange now
			pPrevNode1->next = pNode2;
			pNextNode1->prev = pNode2;
			pNode2->prev = pPrevNode1;
			pNode2->next = pNextNode1;

			pPrevNode2->next = pNode1;
			pNextNode2->prev = pNode1;
			pNode1->prev = pPrevNode2;
			pNode1->next = pNextNode2;
		}
	}

#endif  /* DOUBLY_LINKED_LIST_H */

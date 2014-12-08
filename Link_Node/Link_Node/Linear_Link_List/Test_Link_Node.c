/***************************************************************
 * File name		: Test_Link_Node.c
 * Description		: 测试链表的用例
 * Creator			: XU ZAN
 * Creation date	: Thur.	Nov. 20, 2014
 * Copyright(C)		2014	All rights reserved.
 *
 ***************************************************************/

#include "Test_Link_Node.h"

#include "Link_Node.h"
#include <stdio.h>
#include <stdlib.h>

void TestCase_Link_List(void)
{
	Status result = 0;
	ElemType e = 0;
	LinkList myLinkList = {NULL, NULL, 0};
	Link myNode = NULL, Nodes = NULL, Node2BeDeleted = NULL;

	result = InitList(&myLinkList);
	if (result == OK)
		result = CreateLinkList(&myLinkList, 7);
	DisplayLinkList(myLinkList);
	DisplayList(myLinkList.head);

	MakeNode(&myNode, 705);
	Append(&myLinkList, myNode);
	DisplayLinkList(myLinkList);

	/* Create an independent link-nodes.
	 */
	CreateLinkNode(&Nodes, 3);
	Append(&myLinkList, Nodes);
	DisplayLinkList(myLinkList);

	InsFirst(&Nodes, myNode);
	DisplayList(Nodes);

	Remove(&myLinkList, &e);
	DisplayLinkList(myLinkList);

	/*
	DelFirst(&Nodes, &Node2BeDeleted);
	DisplayList(Nodes);
	DisplayLinkList(myLinkList);
	 */

	DestroyList(&myLinkList);
	DisplayLinkList(myLinkList);
}

void TestCase_Link_Node(void)
{
	Link Nodes = NULL;
	int n = 0;
	
	printf("Please enter the node counters : ");
	scanf("%d", &n);
	// InitLinkNode(&Nodes);
	CreateLinkNode(&Nodes, n);

	DisplayList(Nodes);

	DestroyLinkNode(&Nodes);
	DisplayList(Nodes);
}
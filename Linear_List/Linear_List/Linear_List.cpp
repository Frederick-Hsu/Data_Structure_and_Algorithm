/********************************************************************************************
 * File name	: Linear_List.cpp
 * Description	: To implement the structure of Linear_List and its algorithm.
 * Creator		: XU ZAN
 * Creation date: Thur.	Nov. 28, 2013
 * Copyright(C)		2013	All rights reserved.
 *
 ********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "Linear_List.h"

Status InitList_Sq(SqList &L)
{
	// 構造一個空的綫性表L
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem)
		exit(OVERFLOW);		// 存儲分配失敗
	L.length = 0;					// 空表長度為0
	L.listsize = LIST_INIT_SIZE;	// 初始存儲容量
	return OK;
}
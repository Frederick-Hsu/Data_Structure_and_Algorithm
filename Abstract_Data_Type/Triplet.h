/********************************************************************************************
 * File name	: Triplet.h
 * Description	: The data structure of triplet
 * Creator		: XU ZAN
 * Creation date: Fri.	Nov. 15, 2013
 * COpyright(C)		2013	All rights reserved.
 *
 ********************************************************************************************/


#ifndef TRIPLET_H
#define TRIPLET_H
	
	/********************************************************
	 * Includes :
	 */
	#include "pre_definition.h"

	/********************************************************
	 * Type defintitions :
	 */
	typedef int ElemType;

	//----- 採用動態分配的順序存儲結構 -----
	typedef ElemType *Triplet;

	// ----- 基本操作的函數原形説明 -----
	Status InitTriplet(Triplet pT, ElemType v1, ElemType v2, ElemType v3);
	

#endif	/*  TRIPLET_H  */
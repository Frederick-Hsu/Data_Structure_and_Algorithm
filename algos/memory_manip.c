/**************************************************************************************************
 * File name	: memory_manip.c
 * Description	: Study the algorithms, prepare for C++ programming interview.
 * Creator		: Frederique Hsu
 * Creation date: Sat.	18 April 2020
 * Copyright(C)	2020	All rights reserved.
 *
 **************************************************************************************************/

#include <stdio.h>

void* memmove(void* dest, void* src, size_t n);

int main(int argc, char* argv[])
{
	return 0;
}

void* memmove(void* dest, void* src, size_t n)
{
	char *pdest = dest;
	const char *psrc = src;

	if (psrc < pdest)
	{
		psrc += n;
		pdest += n;
		while (n-- != 0)
		{
			*--pdest = *--psrc;
		}
	}
	else
	{
		while (n-- != 0)
		{
			*pdest++ = *psrc++
		}
	}
	return (void*)pdest;
}
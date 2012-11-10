/*
 * tools.c
 *
 * Some basic tools for c 
 *
 * Copyright (C) 2012 Abhishek Reddy kondaveeti
 *
 * Contributor: Abhishek Reddy Kondaveeti <abhishek.kondaveeti@gmail.com>
 *              
 *
 * This file is licensed under the terms of the GNU General Public License
 * version 2. This program is licensed "as is" without any warranty of any
 * kind, whether express or implied.
 *
 */

#include <tools.h>

void insertToArray(int* arr, int data, int pos, int size)
{
   int count, tmp;
   for(count = pos; count < size; count++)
   {
	   tmp = arr[count];
	   arr[count]= data;
	   data = tmp;
   }
}

void insertion_sort(int* a, int size)
{
	int key, i=0, j;

	for(j = 1 ; j < size; j++) 
	{
		key = *(a+j);
		i = j-1;
		while( i >=0 && (*(a+i))  > key)
		{
			*(a +i + 1) = *(a+i);
			*(a+i) = key;
			i--;
		}
	}

}

/*
 * example.c
 *
 * Usage example of tools
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

int main()
{
	int a[9] = {4, 2, 7, 1, 6, 5, 9, 8};
	int i=0;
	insertion_sort(a, 9);
	for(i = 0; i < 9; i++) 
	{
		printf("%d\t", a[i]);
	}
	return 0; 
}

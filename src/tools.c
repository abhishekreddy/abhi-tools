/*
 * tools.c
 *
 * Some basic tools for c 
 *
 * Copyright (C) 2014-15 Abhishek Reddy kondaveeti
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

void selection_sort(int* a, int size)
{
	int key, i=0, j, min;
	
	for(j = 0 ; j < size - 1; j++)
	{
		key = *(a+j);
		min = j;
		for(i = j; i < size; i++)
		{
			if(key > *(a+i))
			{
				key = *(a+i);
				min = i;
			}
		}
		if(j != min)
		{
			*(a+min) = *(a+j);
			*(a+j) = key;
		}
	}
}

/*Linked List Implementations*/
void displayList(struct NODE* HEAD)
{
	struct NODE *node = HEAD;
	
	if(node == NULL)
	{
		printf("Invalid NODE\n");
	}
	
	if(node->next != NULL)
	{
		node = node->next;
	}
	else
	{
		printf("No elements in Array\n");
		return;
	}
	

	while(node->next != NULL) {
		printf("%d\t", node->data);
		node = node->next;
		}
	printf("%d\n", node->data);
}

void deleteFromList(struct NODE* HEAD) 
{
	struct NODE *node = HEAD;
	
	if(node == NULL)
	{
		printf("Invalid NODE\n");
	}
	
	if(node->next == NULL)
	{
		printf("No elements left in List\n");
		return;
	}
	while(node->next->next != NULL) {
		node = node->next;
	}
	free(node->next);
	node->next = NULL;
}

void addToList(struct NODE* HEAD, int data) 
{
	struct NODE *node = HEAD, *nnode;
	
	if(node == NULL)
	{
		printf("Invalid NODE\n");
	}
	
	while(node->next != NULL) {
		node = node->next;
	}
	nnode = (struct NODE*)malloc(sizeof(struct NODE));
	node->next = nnode;
	nnode->data = data;
	nnode->next = NULL;
}

void deleteFromGivenAtPosition(struct NODE* HEAD, int pos)
{
	struct NODE *node = HEAD, *dnode;
	int count = 0;
	
	if(node == NULL)
	{
		printf("Invalid NODE\n");
	}
	
	if(pos < 0)
	{
		printf("Invalid Position\n");
		return;
	}
	
	while(node->next != NULL) {
		if(count == (pos - 1))
			break;
		count++;
		node = node->next;
	}
	if((count+1) < pos)
	{
		printf("Invalid Position\n");
		return;
	}

	dnode = node->next;
	node->next = node->next->next;
	free(dnode);
}

void addToListAtPosition(struct NODE* HEAD, int pos, int data) 
{
	struct NODE *node = HEAD, *nnode;
	int count = 0;
	
	if(node == NULL)
	{
		printf("Invalid NODE\n");
	}
	
	if(pos < 0)
	{
		printf("Invalid Position\n");
		return;
	}
	
	while(node->next != NULL) {
		if(count == (pos - 1))
			break;
		count++;
		node = node->next;
	}

	if((count+1) < pos)
	{
		printf("Invalid Position\n");
		return;
	}

	nnode = (struct NODE*)malloc(sizeof(struct NODE));
	nnode->next = node->next;
	node->next = nnode;
	nnode->data = data;
}

void modifyListAtPosition(struct NODE* HEAD, int pos, int data) 
{
	struct NODE *node = HEAD;
	int count = 0;
	
	if(node == NULL)
	{
		printf("Invalid NODE\n");
	}
	
	if(pos < 0)
	{
		printf("Invalid Position\n");
		return;
	}
	
	while(node->next != NULL) {
		if(count == pos)
			break;
		count++;
		node = node->next;
	}

	if(count < pos)
	{
		printf("Invalid Position\n");
		return;
	}
	node->data = data;
}

void displayListAtPosition(struct NODE* HEAD, int pos) 
{
	struct NODE *node = HEAD;
	int count = 0;
	
	if(node == NULL)
	{
		printf("Invalid NODE\n");
	}
	
	if(pos < 0)
	{
		printf("Invalid Position\n");
		return;
	}
	
	while(node->next != NULL) {
		if(count == pos)
			break;
		count++;
		node = node->next;
	}

	if(count < pos)
	{
		printf("Invalid Position\n");
		return;
	}
	printf("%d\n", node->data);
}

struct NODE* initializeList()
{
	struct NODE* HEAD = NULL;
	HEAD = (struct NODE*)malloc(sizeof(struct NODE));
	if(HEAD == NULL)
	 {
		 printf("Unable to initialize List\n");
	 }
	HEAD->next = NULL;
	return HEAD;
}


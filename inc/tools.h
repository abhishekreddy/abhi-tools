/*
 * tools.h
 *
 * Some basic tools for c
 *
 * Copyright (C) 2015 Abhishek Reddy kondaveeti
 *
 * Contributor: Abhishek Reddy Kondaveeti <abhishek.kondaveeti@gmail.com>
 *
 *
 * This file is licensed under the terms of the GNU General Public License
 * version 2. This program is licensed "as is" without any warranty of any
 * kind, whether express or implied.
 *
 */
#ifndef _TOOLS_H
#define _TOOLS_H

#include <stdio.h>
#include <stdlib.h>

#define MYSIZE(X) ((X*)0+1)

#ifdef DEBUG_MODE
#define TOOL_ERR(fmt, args...)  printf(fmt, ##args)
#define TOOL_DBG(fmt, args...)  printf(fmt, ##args)
#else
#define TOOL_ERR(fmt, args...)  printf(fmt, ##args)
#define TOOL_DBG(fmt, args...) do {} while (0)
#endif

struct NODE {
  int data;
  struct NODE *next;
};

struct DNODE {
  int data;
  struct DNODE *next;
  struct DNODE *prev;
};

typedef enum {
  SELECTION_SORT,
  INSERTION_SORT,
  BUBBLE_SORT,
  MERGE_SORT,
  HEAP_SORT,
  QUICK_SORT,
  MAX_SORT
}sort_type_t;

void insertToArray(int* arr, int data, int pos, int size);
void insertion_sort(int* a, int size);
void selection_sort(int* a, int size);

//Linked List Functions
struct NODE* initializeList();
void addToList(struct NODE* HEAD, int data);
void addToListAtPosition(struct NODE* HEAD, int pos, int data);
void displayList(struct NODE* HEAD);
void displayListAtPosition(struct NODE* HEAD, int pos);
void deleteFromList(struct NODE* HEAD);
void deleteFromListAtPosition(struct NODE* HEAD, int pos);
void modifyListAtPosition(struct NODE* HEAD, int pos, int data);

//Double Linked List Functions
struct DNODE* initializeDList();
void addToDList(struct DNODE* HEAD, int data);
void addToDListAtPosition(struct DNODE* HEAD, int pos, int data);
void displayDList(struct DNODE* HEAD);
void displayDListAtPosition(struct DNODE* HEAD, int pos);
void deleteFromDList(struct DNODE* HEAD);
void deleteFromDListAtPosition(struct DNODE *HEAD, int pos);
void modifyDListAtPosition(struct DNODE* HEAD, int pos, int data);

void sort_list(struct NODE* head, sort_type_t type);
#endif // _TOOLS_H

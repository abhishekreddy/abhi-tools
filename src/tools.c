/*
 * tools.c
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

#include <tools.h>

void insertToArray(int* arr, int data, int pos, int size)
{
  int count, tmp;
  for (count = pos; count < size; count++) {
    tmp = arr[count];
    arr[count]= data;
    data = tmp;
  }
}

void insertion_sort(int* a, int size)
{
  int key, i=0, j;

  for (j = 1 ; j < size; j++) {
    key = *(a+j);
    i = j-1;
    while ( i >=0 && (*(a+i))  > key) {
      *(a +i + 1) = *(a+i);
      *(a+i) = key;
      i--;
    }
  }
}

void selection_sort(int* a, int size)
{
  int key, i=0, j, min;

  for (j = 0 ; j < size - 1; j++) {
    key = *(a+j);
    min = j;
    for (i = j; i < size; i++) {
      if (key > *(a+i)) {
        key = *(a+i);
        min = i;
      }
    }
    if (j != min) {
      *(a+min) = *(a+j);
      *(a+j) = key;
    }
  }
}

void sort_list(struct NODE* head, sort_type_t type)
{
  struct NODE* node = NULL;
  struct NODE* trav_node = NULL;
  if (head == NULL) {
    TOOL_ERR("%s: %d Invalid List\n", __func__, __LINE__);
    return;
  }
  if (head->next == NULL) {
    TOOL_ERR("%s: %d No elements in the list\n", __func__, __LINE__);
    return;
  }
  node = head->next;
  switch (type) {
    case SELECTION_SORT: {
      struct NODE* min_node = NULL;
      int min = 0;
      do {
        min = node->data;
        min_node = node;
        trav_node = node->next;
        if (trav_node == NULL)
          break;
        do {
          if (trav_node->data < min) {
            min_node = trav_node;
            min = trav_node->data;
          }
          trav_node = trav_node->next;
        } while(trav_node != NULL);
        if ((node != min_node)) {
          node->data = min_node->data + node->data;
          min_node->data = node->data - min_node->data;
          node->data = node->data - min_node->data;
        }
        node = node->next;
      } while(node != NULL);
    }
    break;

    case BUBBLE_SORT: {
      int sorted = 0;
      struct NODE* last_sorted = NULL;
      do {
        sorted = 0;
        while (node->next != last_sorted) {
          if (node->data > node->next->data) {
            node->data = node->data + node->next->data;
            node->next->data = node->data - node->next->data;
            node->data = node->data - node->next->data;
            sorted = 1;
          }
          node = node->next;
        }
        last_sorted = node;
        node = head->next;
      } while(sorted);
    }
    break;

    default:
    break;
  }
  return;
}

/*Linked List Implementations*/
void displayList(struct NODE* HEAD)
{
  struct NODE *node = HEAD;

  if (node == NULL) {
    TOOL_ERR("Invalid NODE\n");
    return;
  }

  if (node->next != NULL) {
    node = node->next;
  } else {
    printf("No elements in Array\n");
    return;
  }

  while (node->next != NULL) {
    TOOL_ERR("%d\t", node->data);
    node = node->next;
  }
  TOOL_ERR("%d\n", node->data);
}

void deleteFromList(struct NODE* HEAD)
{
  struct NODE *node = HEAD;

  if (node == NULL) {
    TOOL_ERR("Invalid NODE\n");
    return;
  }

  if (node->next == NULL) {
    TOOL_ERR("No elements left in List\n");
    return;
  }
  while (node->next->next != NULL) {
    node = node->next;
  }
  free(node->next);
  node->next = NULL;
}

void addToList(struct NODE* HEAD, int data)
{
  struct NODE *node = HEAD, *nnode = NULL;

  if (node == NULL) {
    TOOL_ERR("Invalid NODE\n");
    return;
  }

  while (node->next != NULL) {
    node = node->next;
  }
  nnode = (struct NODE*)malloc(sizeof(struct NODE));
  if (nnode == NULL) {
    TOOL_ERR("Ran out of memory\n");
    return;
  }
  node->next = nnode;
  nnode->data = data;
  nnode->next = NULL;
}

void deleteFromListAtPosition(struct NODE* HEAD, int pos)
{
  struct NODE *node = HEAD, *dnode;
  int count = 0;

  if (node == NULL) {
    TOOL_ERR("Invalid NODE\n");
    return;
  }

  if (pos < 0) {
    TOOL_ERR("Invalid Position\n");
    return;
  }

  while (node->next != NULL) {
    if (count == (pos - 1))
      break;
    count++;
    node = node->next;
  }
  if ((count+1) < pos) {
    TOOL_ERR("Invalid Position\n");
    return;
  }

  dnode = node->next;
  node->next = node->next->next;
  free(dnode);
}

void addToListAtPosition(struct NODE* HEAD, int pos, int data)
{
  struct NODE *node = HEAD, *nnode = NULL;
  int count = 0;

  if (node == NULL) {
    TOOL_ERR("Invalid NODE\n");
    return;
  }

  if (pos < 0) {
    TOOL_ERR("Invalid Position\n");
    return;
  }

  while (node->next != NULL) {
    if (count == (pos - 1))
      break;
    count++;
    node = node->next;
  }

  if ((count+1) < pos) {
    TOOL_ERR("Invalid Position\n");
    return;
  }

  nnode = (struct NODE*)malloc(sizeof(struct NODE));
  if (nnode == NULL) {
    TOOL_ERR("Ran out of memory\n");
    return;
  }
  nnode->next = node->next;
  node->next = nnode;
  nnode->data = data;
}

void modifyListAtPosition(struct NODE* HEAD, int pos, int data)
{
  struct NODE *node = HEAD;
  int count = 0;

  if (node == NULL) {
    TOOL_ERR("Invalid NODE\n");
    return;
  }

  if (pos < 0) {
    TOOL_ERR("Invalid Position\n");
    return;
  }

  while (node->next != NULL) {
    if (count == pos)
      break;
    count++;
    node = node->next;
  }

  if (count < pos) {
    TOOL_ERR("Invalid Position\n");
    return;
  }
  node->data = data;
}

void displayListAtPosition(struct NODE* HEAD, int pos)
{
  struct NODE *node = HEAD;
  int count = 0;

  if (node == NULL) {
    TOOL_ERR("Invalid NODE\n");
    return;
  }

  if (pos < 0) {
    TOOL_ERR("Invalid Position\n");
    return;
  }

  while (node->next != NULL) {
    if (count == pos)
      break;
    count++;
    node = node->next;
  }

  if (count < pos) {
    TOOL_ERR("Invalid Position\n");
    return;
  }
  printf("%d\n", node->data);
}

struct NODE* initializeList()
{
  struct NODE* HEAD = NULL;
  HEAD = (struct NODE*)malloc(sizeof(struct NODE));
  if (HEAD == NULL) {
    TOOL_ERR("Unable to initialize List\n");
    return NULL;
  }
  HEAD->next = NULL;
  return HEAD;
}

void displayDList(struct DNODE* HEAD)
{
  struct DNODE *node = HEAD;

  if (node == NULL) {
    TOOL_ERR("Invalid NODE\n");
    return;
  }

  if (node->next != NULL) {
    node = node->next;
  } else {
    TOOL_ERR("No elements in Array\n");
    return;
  }

  while (node->next != NULL) {
    TOOL_ERR("%d\t", node->data);
    node = node->next;
  }
  TOOL_ERR("%d\n", node->data);
}

void displayDListAtPosition(struct DNODE* HEAD, int pos)
{
  struct DNODE *node = HEAD;
  int count = 0;

  if (node == NULL) {
    TOOL_ERR("Invalid NODE\n");
    return;
  }

  if (pos < 0) {
    TOOL_ERR("Invalid Position\n");
    return;
  }

  while (node->next != NULL) {
    if (count == pos)
      break;
    count++;
    node = node->next;
  }

  if (count < pos) {
    TOOL_ERR("Invalid Position\n");
    return;
  }
  TOOL_ERR("%d\n", node->data);
}

void addToDList(struct DNODE* HEAD, int data)
{
  struct DNODE *node = HEAD, *nnode = NULL;

  if (node == NULL) {
    TOOL_ERR("Invalid NODE\n");
    return;
  }

  while (node->next != NULL) {
    node = node->next;
  }
  nnode = (struct DNODE*)malloc(sizeof(struct DNODE));
  if (nnode == NULL) {
    TOOL_ERR("%s: %d: Ran out of memory\n", __func__, __LINE__);
    return;
  }
  node->next = nnode;
  nnode->data = data;
  nnode->prev = node;
  nnode->next = NULL;
}

void deleteFromDList(struct DNODE* HEAD)
{
  struct DNODE *node = HEAD;

  if (node == NULL) {
    TOOL_ERR("Invalid NODE\n");
    return;
  }

  if (node->next == NULL) {
    TOOL_ERR("No elements left in List\n");
    return;
  }
  while (node->next->next != NULL) {
    node = node->next;
  }
  free(node->next);
  node->next = NULL;
}

void deleteFromDListAtPosition(struct DNODE* HEAD, int pos)
{
  struct DNODE *node = HEAD;
  int count = 0;

  if (node == NULL) {
    TOOL_ERR("Invalid NODE\n");
    return;
  }

  if (pos < 0) {
    TOOL_ERR("Invalid Position\n");
    return;
  }

  while (node->next != NULL) {
    if (count == pos)
      break;
    count++;
    node = node->next;
  }
  if (count < pos) {
    TOOL_ERR("Invalid Position\n");
    return;
  }

  node->prev->next = node->next;
  node->next->prev = node->prev;
  free(node);
}

void addToDListAtPosition(struct DNODE* HEAD, int pos, int data)
{
  struct DNODE *node = HEAD, *nnode = NULL;
  int count = 0;

  if (node == NULL) {
    TOOL_ERR("Invalid NODE\n");
    return;
  }

  if (pos < 0) {
    TOOL_ERR("Invalid Position\n");
    return;
  }

  while (node->next != NULL) {
    if (count == pos)
      break;
    count++;
    node = node->next;
  }

  if ((count) < pos) {
    TOOL_ERR("Invalid Position\n");
    return;
  }

  nnode = (struct DNODE*)malloc(sizeof(struct DNODE));
  if (nnode == NULL) {
    TOOL_ERR("Ran out of memory\n");
    return;
  }
  nnode->next = node;
  nnode->prev = node->prev;
  node->prev->next = nnode;
  node->prev = nnode;
  nnode->data = data;
}

void modifyDListAtPosition(struct DNODE* HEAD, int pos, int data)
{
  struct DNODE *node = HEAD;
  int count = 0;

  if (node == NULL) {
    TOOL_ERR("Invalid NODE\n");
    return;
  }

  if (pos < 0) {
    TOOL_ERR("Invalid Position\n");
    return;
  }

  while (node->next != NULL) {
    if (count == pos)
      break;
    count++;
    node = node->next;
  }

  if (count < pos) {
    TOOL_ERR("Invalid Position\n");
    return;
  }
  node->data = data;
}

struct DNODE* initializeDList()
{
  struct DNODE* HEAD = NULL;
  HEAD = (struct DNODE*)malloc(sizeof(struct DNODE));
  if (HEAD == NULL) {
    TOOL_ERR("Unable to initialize List\n");
    return NULL;
  }
  HEAD->next = NULL;
  HEAD->prev = NULL;
  return HEAD;
}

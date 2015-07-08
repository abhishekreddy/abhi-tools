/*
 * example.c
 *
 * Usage example of tools
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
int main()
{
  //int a[9] = {4, 2, 7, 1, 6, 5, 9, 8};
  //int i=0;
  //insertion_sort(a, 9);
  //for(i = 0; i < 9; i++)
  //{
  //	printf("%d\t", a[i]);
  //}
  //return 0;
  struct NODE* llist = NULL;
  llist = initializeList();
  int choice = 0, data = 0, pos = 0, type = 0;
  while(1) {
    printf("Please choose the operation do you want to do on list\n");
    printf("1. ADD\n");
    printf("2. DELETE\n");
    printf("3. DISPLAY\n");
    printf("4. ADD AT GIVEN POSITION\n");
    printf("5. DELETE AT GIVEN POSITION\n");
    printf("6. MODIFY AT GIVEN POSITION\n");
    printf("7. DISPLAY AT GIVEN POSITION\n");
    printf("8: SORT\n");
    printf("9. QUIT\n");
    scanf("%d", &choice);
    switch(choice) {
      case 1:
        printf("Enter the data to add\n");
        scanf("%d", &data);
        addToList(llist, data);
      break;
      case 2:
        deleteFromList(llist);
      break;
      case 4:
        printf("Enter the position\n");
        scanf("%d", &pos);
        printf("Enter the data\n");
        scanf("%d", &data);
        addToListAtPosition(llist, pos, data);
      break;
      case 5:
        printf("Enter the position\n");
        scanf("%d", &pos);
        deleteFromListAtPosition(llist, pos);
      break;
      case 6:
        printf("Enter the position\n");
        scanf("%d", &pos);
        printf("Enter the data\n");
        scanf("%d", &data);
        modifyListAtPosition(llist, pos, data);
      break;
      case 7:
        printf("Enter the position\n");
        scanf("%d", &pos);
        displayListAtPosition(llist, pos);
      break;
      case 8:
        printf("Before sorting the list\n");
        displayList(llist);
        printf("---->Enter the sorting type<----\n");
        printf("------->0.SELECTION_SORT<-------\n");
        printf("------->1.INSERTION_SORT<-------\n");
        printf("------->2.BUBBLE_SORT   <-------\n");
        printf("------->3.MERGE_SORT    <-------\n");
        printf("------->4.HEAP_SORT     <-------\n");
        printf("------->5.QUICK_SORT    <-------\n");
        scanf("%d", &type);
        printf("Sorting the List\n");
        sort_list(llist, (sort_type_t)type);
        printf("After sorting the list\n");
        displayList(llist);
      break;
      case 9:
        return 0;
      case 3:
      default:
        displayList(llist);
      break;
    }
  }
  return 0;
}

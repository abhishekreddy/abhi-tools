/*
 * stringsupport.c
 *
 * Some basic string support tools for c
 *
 * Copyright (C) 2015-2106 Abhishek Reddy kondaveeti
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
#include <stringsupport.h>

void swap_char(char* ptr1, char* ptr2)
{
  char temp;
  temp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = temp;
}

void sort_string(char* str, sort_type_t type)
{
  int i,j, sorted = 0;
  char *tmp1 = NULL;
  char *tmp2 = NULL;
  char *start = NULL;

  IF_NULL_VOID_RETURN(str);

  tmp1 = str;
  tmp2 = str;

  switch (type) {
    case BUBBLE_SORT: {
      TOOL_DBG("%s: Using Bubble sort\n", __func__);
      start = str;
      do {
		sorted = 0;
        tmp2 = start+1;
        tmp1 = start;
        while (*tmp2 != '\0') {
          if (*tmp1 > *tmp2) {
            swap_char(tmp1, tmp2);
            sorted = 1;
          }
          tmp1++;
          tmp2++;
        }
        TOOL_DBG("%s: Sorted string %s\n", __func__, str);
      } while (sorted);
    }
    break;
    default:
    break;
  }

}

void  max_array(int a[], int num_elements, int *max_idx, int *max)
{
   int i;
   *max = 0;
   *max_idx = 0;
   for (i=0; i<num_elements; i++)
   {
	 if (a[i]> *max)
	 {
	    *max=a[i];
        *max_idx = i;
	 }
   }
}

int str_len(char *str)
{
  int len = 0, i;
  if (!str)
    return len;
  while (*str != '\0') {
    len++;
    str++;
  }
  TOOL_DBG("String Length is %d\n",len);
  return len;
}

int check_if_polindrome(char *str, int len)
{
  int is_polindrome = 1, i = 0;

  for (i = 0; i < len/2; i++) {
    if (str[i] != str[(len-i) - 1]) {
      TOOL_DBG("str[%d]  %c and str[%d] %c\n", i, str[i], len - i, str[(len-i) - 1]);
      is_polindrome = 0;
      break;
    }
  }
  return is_polindrome;
}


void find_all_subpolindromes(char *str)
{
  int i = 0;
  int len;
  char *fptr, *bptr, *tptr;

  len = str_len(str);
  fptr = str;
  bptr = str + len - 1;
  while (fptr != bptr) {
    tptr = bptr;
    len = bptr - fptr + 1;
    while (tptr != fptr) {
      if (check_if_polindrome(fptr, len)) {
        for (i = 0; i < len; i++)
          printf("%c",fptr[i]);
        TOOL_ERR("\n");
      }
     tptr--;
     len--;
    }
   fptr++;
  }
}

int check_if_isomorphic(char* str1, char* str2)
{
  int is_isomorphic = 1;
  char map_array[MAX_NUM_CHARS];
  int is_visited[MAX_NUM_CHARS];
  int len, i;
  memset(map_array, 0, sizeof(char) * MAX_NUM_CHARS);
  memset(is_visited, 0, sizeof(int) * MAX_NUM_CHARS);
  len = str_len(str1);
  if (len != str_len(str2)) {
    TOOL_ERR("The Given strings are not isomorpic\n");
    is_isomorphic = 0;
  } else {
    for (i = 0; i < len; i++) {
      if (is_visited[str1[i]]) {
        if (map_array[str1[i]] != str2[i])
          is_isomorphic = 0;
      } else {
        is_visited[str1[i]] = 1;
        map_array[str1[i]] = str2[i];
      }
    }

  }
  TOOL_DBG("%s: Isomorphic %d\n", __func__, is_isomorphic);
  return is_isomorphic;
}
void get_max_occur_char(char* str, char* max)
{
  int max_count = 0 , max_char = 0;;
  int count_char[MAX_NUM_CHARS] = {0};
  char* tmp;

  IF_NULL_VOID_RETURN(str);
  IF_NULL_VOID_RETURN(max);

  tmp = str;
  while (*tmp != '\0') {
    count_char[*tmp]++;
    tmp++;
  }


  max_array(count_char, MAX_NUM_CHARS, &max_char, &max_count);

  *max = (char) max_char;
  return;
}

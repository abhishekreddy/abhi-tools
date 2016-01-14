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
#include <string.h>

void swap_char( unsigned char* ptr1, unsigned char* ptr2)
{
  char temp;
  temp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = temp;
}

void sort_string(unsigned char* str, sort_type_t type)
{
  int sorted = 0;
  unsigned char *tmp1 = NULL;
  unsigned char *tmp2 = NULL;
  unsigned char *start = NULL;

  IF_NULL_RETURN_VOID(str);

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

int str_len(unsigned char *str)
{
  int len = 0;
  if (!str)
    return len;
  while (*str != '\0') {
    len++;
    str++;
  }
  TOOL_DBG("String Length is %d\n",len);
  return len;
}

int check_if_polindrome(unsigned char *str, int len)
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


void find_all_subpolindromes(unsigned char *str)
{
  int i = 0;
  int len;
  unsigned char *fptr, *bptr, *tptr;

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

unsigned char* str_cat(unsigned char* str1, unsigned char* str2)
{
  unsigned char* result = NULL;
  unsigned int offset = 0;

  IF_NULL_RETURN_NULL(str1);
  IF_NULL_RETURN_NULL(str2);

  result = (unsigned char*)malloc(
    sizeof(unsigned char) * (str_len(str1) + str_len(str2)));
    if (!result) {
      TOOL_ERR("%s: %d Memory allocation failed\n", __func__, __LINE__);
      return NULL;
    }
  offset = sizeof(unsigned char) * str_len(str1);
  memcpy(result , str1, offset);
  memcpy(result + offset, str2, sizeof(unsigned char) * str_len(str2));
  return result;
}

int check_substring(unsigned char* str1, unsigned char* str2)
{
  int result = -1, i, j = 0;
  int len1, len2, start_monitor = 1, pos = 0;

  IF_NULL_RETURN_INT(str1);
  IF_NULL_RETURN_INT(str2);

  len1 = str_len(str1);
  len2 = str_len(str2);

  if (len1 < len2)
    return result;
  for (i =0 ; i < len1; i++) {
    if (start_monitor) {
      if (str1[i] != str2[j]) {
        start_monitor =  j = 0;
        if (str1[i] == str2[j]) {
          start_monitor = 1;
          pos = i;
          j = 1;
          TOOL_DBG("%s: Starting position monitor from pos %d  \
            main string %s substring %s\n", __func__,
            pos, str1, str2);
        }
      } else {
         j++;
         if (j == len2) {
           TOOL_DBG("%s: Found %s in %s at pos %d\n", __func__,
             str2, str1, pos);
           result = pos;
           break;
         }
      }
    } else {
      if (str1[i] == str2[j])
         start_monitor = 1;
         pos = i;
         j = 1;
      TOOL_DBG("%s: Starting position monitor from pos %d \
        main string %s substring %s\n", __func__,
        pos, str1, str2);
    }
  }
  return  result;
}

int check_if_rotated(unsigned char* str1, unsigned char* str2)
{
  int is_rotated = 1;
  unsigned char* result = NULL;

  IF_NULL_RETURN_INT(str1);
  IF_NULL_RETURN_INT(str2);
  if (str_len(str1) != str_len(str2)) {
    is_rotated = 0;
    return is_rotated;
  }
  result = str_cat(str1, str2);

  IF_NULL_RETURN_INT(result);
  if (check_substring(result, str2) == -1)
    is_rotated = 0;
  return is_rotated;
}

int check_if_isomorphic(unsigned char* str1, unsigned char* str2)
{
  int is_isomorphic = 1;
  unsigned char map_array[MAX_NUM_CHARS];
  int is_visited[MAX_NUM_CHARS];
  int len, i;
  memset(map_array, 0, sizeof(unsigned char) * MAX_NUM_CHARS);
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
void get_max_occur_char(unsigned char* str,unsigned char* max)
{
  int max_count = 0 , max_char = 0;;
  int count_char[MAX_NUM_CHARS] = {0};
  unsigned char* tmp;

  IF_NULL_RETURN_VOID(str);
  IF_NULL_RETURN_VOID(max);

  tmp = (unsigned char*)str;
  while (*tmp != '\0') {
    count_char[*tmp]++;
    tmp++;
  }


  max_array(count_char, MAX_NUM_CHARS, &max_char, &max_count);

  *max = (char) max_char;
  return;
}

/*
 * stringex.c
 *
 * Usage example of strings
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
#include <stringsupport.h>
void main()
{

  int i = 0;
  char str[1000];
  printf("Enter String\n");
  scanf("%s", str);

  printf("Entered String %s\n", str);
  str_len(str);
  printf("Polindrome Status: %d\n", check_if_polindrome(str, str_len(str)));
}


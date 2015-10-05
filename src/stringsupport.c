/*
 * stringsupport.c
 *
 * Some basic string support tools for c
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

int str_len(char *str)
{
  int len = 0, i;
  if (!str)
    return len;
  while (*str != '\0') {
    len++;
    str++;
  }
  TOOL_ERR("String Length is %d\n",len);
  return len;
}

int check_if_polindrome(char *str, int len)
{
  int is_polindrome = 1, i = 0;

  for (i = 0; i < len/2; i++) {
    if (str[i] != str[(len-i) - 1]) {
      TOOL_ERR("str[%d]  %c and str[%d] %c\n", i, str[i], len - i, str[(len-i) - 1]);
      is_polindrome = 0;
      break;
    }
  }
  return is_polindrome;
}

/*
char** find_all_subpolindromes(char *str)
{

}
*/

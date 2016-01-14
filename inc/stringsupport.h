/*
 * stringsupport.h
 *
 * Some basic string tools for c
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
#ifndef _STRINGSUPPORT_H
#define _STRINGSUPPORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_CHARS 256


void sort_string(char* str, sort_type_t type);
int str_len(char* str);
int check_if_polindrome(char *str, int len);
void find_all_subpolindromes(char *str);
void get_max_occur_char(char* str, char* max);
int check_if_isomorphic(char* str1, char* str2);
#endif //_STRINGSUPPORT_H

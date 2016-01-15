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


void sort_string(unsigned char* str, sort_type_t type);
int str_len(unsigned char* str);
int check_if_polindrome(unsigned char *str, int len);
void find_all_subpolindromes(unsigned char *str);
void get_max_occur_char(unsigned char* str,unsigned  char* max);
int check_if_isomorphic(unsigned char* str1, unsigned char* str2);
int check_if_rotated(unsigned char* str1, unsigned char* str2);
int check_substring(unsigned char* str1, unsigned char* str2);
void string_reverse(unsigned char* str, int pos, int len);
#endif //_STRINGSUPPORT_H

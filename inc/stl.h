/*
 * stl.h
 *
 * adding OOPS concept for C.Reference the linux kernel source code
 *
 * Copyright (C) 2012 Ajay Nandakumar
 *
 * Contributor: Ajay Nandakumar <mnajay@gmail.com>
 *              
 *
 * This file is licensed under the terms of the GNU General Public License
 * version 2. This program is licensed "as is" without any warranty of any
 * kind, whether express or implied.
 *
 */
#ifndef __STL__
#define __STL__

#undef offsetof
#ifdef __compiler_offsetof
#define offsetof(TYPE,MEMBER) __compiler_offsetof(TYPE,MEMBER)
#else
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#endif

#define get_derived_pointer(ptr, type, member) ({                      \
        const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
        (type *)( (char *)__mptr - offsetof(type,member) );})

#define get_base_pointer(ptr,member) (&ptr->member)

#endif // __STL__

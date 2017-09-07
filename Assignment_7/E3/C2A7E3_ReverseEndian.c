/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 8/22/2017
 * File Name: C2A7E3_ReverseEndian.c
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the definition of function ReverseEndian which Converts any
 * scalar object pointed to by ptr from big endian to little endian (or vice versa)
 * by swapping its bytes.
 */
#include <stddef.h>
void *ReverseEndian(void *ptr, size_t size)
{
    //pointer to the first byte
    char *head  = (char *)ptr;
    //pointer to the last byte
    char *tail = head + size - 1;
    //swapping the bytes
    for (; tail > head; --tail, ++head)
    {
        char temp = *head;
        *head = *tail;
        *tail = temp;
    }
    return ptr;
}

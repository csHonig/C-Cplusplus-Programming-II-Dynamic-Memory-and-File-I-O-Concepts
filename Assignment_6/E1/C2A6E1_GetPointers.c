/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 8/7/2017
 * File Name: C2A6E1_GetPointers.c
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the definition of the functions GetPrintfPointer and
 * GetPutsPointer returning pointers to  standard library function printf and puts
 * respectively
 */
#include <stdio.h>

int (*GetPrintfPointer(void))(const char *format, ...)
{
    int (*pPrintf)(const char *format, ...) = printf;
    return pPrintf;
}

int (*GetPutsPointer(void))(const char *str)
{
    int (*pPuts)(const char *str) = puts;
    return pPuts;
}

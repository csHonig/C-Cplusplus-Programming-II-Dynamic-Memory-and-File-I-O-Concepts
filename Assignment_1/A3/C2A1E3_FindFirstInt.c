/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 7/12/2017
 * File Name: C2A1E3_FindFirstInt.c
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the definition of function FindFirstInt which finds the
 * first occurrence of the value represented by value in the array ptr which
 * has count elements. If the value is found, a pointer to that element is
 * returned
 */
#include <stdio.h>
//function to find the first occurrence of value in the array
int *FindFirstInt(const int *ptr, size_t count, int value)
{
    //start the the index 0 till it reach end of the array of size value
    for (size_t iter = 0; iter < count; iter++)
    {
        //comparing each element of the array with the value
        if (ptr[iter] == value)
            return (int *)(ptr + iter);
    }
    //returning NULL pointer if the value doesn't exits
    return NULL;
}

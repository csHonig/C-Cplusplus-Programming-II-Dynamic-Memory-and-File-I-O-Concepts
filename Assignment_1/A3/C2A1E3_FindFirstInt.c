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
 * Class Type Employee is defined. Most of the member functions are also defined
 * Function overloading is implemented for functions name Set and Get
 *
 * DO NOT COPY OR RESTATE MY INSTRUCTIONS IN THE TITLE BLOCK.
 */
#include <stdio.h>
//function to find the first occurrence of value in the array
int *FindFirstInt(const int *ptr, size_t count, int value)
{
    size_t iter = 0;
    //start the the index 0 till it reach end of the array of size value
    while (iter < count)
    {
        //comparing each element of the array with the value
        if (ptr[iter] == value)
            return (int *)(ptr + iter);
        iter++;
    }
    //returning NULL pointer if the value doesn't exits
    return NULL;
}

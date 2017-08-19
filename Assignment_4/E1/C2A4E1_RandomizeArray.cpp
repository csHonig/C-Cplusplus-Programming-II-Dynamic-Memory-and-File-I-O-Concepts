/* Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 7/31/2017
 * File Name: C2A4E1_RandomizeArray.cpp
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the definitions of function RandomizeArray which Initializes
 * the elements of the 4D array with the randam values
 */
#include <ctime>
#include <cstdlib>
#include "C2A4E1_ArraySize.h"
void RandomizeArray(float (*ptestArray)[DIM1][DIM2][DIM3])
{   //fptr is a pointer to a float
    srand((unsigned int)time(NULL));
    //Initialize the elements of the array using compact pointers with the Random value
    for (float *fptr = (float *)ptestArray; fptr < (float *)ptestArray + DIM0 * DIM1 * DIM2 * DIM3; ++fptr)
    {
        *fptr = (float)rand();
    }
    return;
}

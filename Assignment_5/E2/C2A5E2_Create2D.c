/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 8/7/2017
 * File Name: C2A5E2_Create2D.c
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the definition of the function Create2D for creating 2D
 * pointer array using single dynamical allocation call.
 */
#include "C2A5E2_Type-Driver.h"
#include <stdlib.h>
#include <stdio.h>
Type **Create2D(size_t rows, size_t cols)
{
    //total byte needed for storing all the info of array along with the pointers
    //for pointing to each row
    size_t totalsize = rows * cols * sizeof(Type) + rows * sizeof(Type *);
    void *ptr = malloc(totalsize);
    //If the allocation is not successful, write the error msg and exiting the program
    if (ptr == NULL)
    {
        fprintf(stderr, "couldn't allocate for creating 2D array");
        exit(1);
    }
    //p an q points to pointer to array member and array member respectively
    Type **ppType, *pType;
    //Typecast ptr to type pointer to pointer to Type and assign to variable ppType
    ppType = (Type **)ptr;
    //pType  will the the starting addr where the actual array elements will be located
    // (pType + 1) will point second element of array becoz, pType is of type pointer to Type
    pType = (Type *)(ppType + rows);
    //The for loop initializes each of the pointers to an array to the calculated
    //value of the addr from the single block of memory
    for (size_t n_rows = 0; n_rows < rows; ++n_rows)
    {
        ppType[n_rows] = pType + n_rows * cols;
    }
    return ptr;
}


void Free2D(void *p)
{   //single free function will free the whole block of memory allocated
    free(p);
}

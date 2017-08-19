/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 8/7/2017
 * File Name: C2A5E1_SwapObjects.c
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the definition of the function SwapObjects which swap the
 * objects in pa and pb

 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void SwapObjects(void *pa, void *pb, size_t size)
{
    //allocate a memory for holding the value temporarily for swapping purpose
    void *tmp = malloc(size);
    //If allocation fails, exit the program after writting the errorcode to stderr
    if (tmp == NULL)
    {
        fprintf(stderr, "couldn't allocate memory for swapping");
        exit(1);
    }
    //using the block copy function for copying the block of memory for swapping
    memcpy(tmp, pa, size);
    memcpy(pa, pb, size);
    memcpy(pb, tmp, size);
    //once swapping is done, freeing the tmp location allocated
    free(tmp);
}

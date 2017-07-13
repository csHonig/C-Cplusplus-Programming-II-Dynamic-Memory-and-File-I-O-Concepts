/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 7/12/2017
 * File Name: C2A1E5_ResizeAlloc.c
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * Class Type Employee is defined. Most of the member functions are also defined
 * Function overloading is implemented for functions name Set and Get
 *
 * DO NOT COPY OR RESTATE MY INSTRUCTIONS IN THE TITLE BLOCK.
 */
#include <stdlib.h>
//implementing the reallocation of dynamically allocated memory spaces
void *ResizeAlloc(void *pOld, size_t newSize, size_t oldSize)
{
    //dest is the void pointer which needs to be typecast for the purpose of using after returned
    void *dest;
    if (newSize == 0)
        return NULL;
    else
    {
        //checking if malloc operation is successful or not
        if ((dest = malloc(sizeof(size_t)* newSize)) == NULL)
            return NULL;
        //checking if the nothing is given in the pOld.
        else if (pOld == NULL)
            return dest;
        //proceeding when both the pOld and newly allocated memory are both not NULL
        else
        {
            //typecast both the pOld and dest to char *
            char *cdest = (char *)dest;
            char *csrc = (char *)pOld;
            //copy the content from location pointed by pOld to newly allocated space
            if (newSize > oldSize)
                for (size_t count = 0; count < oldSize; count++)
                    cdest[count] = csrc[count];
            else
                for (size_t count = 0; count < newSize; count++)
                    cdest[count] = csrc[count];
            free(pOld);
        }
    }
    return dest;
}

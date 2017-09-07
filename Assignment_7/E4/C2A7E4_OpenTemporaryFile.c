/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 8/22/2017
 * File Name: C2A7E4_OpenTemporaryFile.c
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the definition of function OpenTemporaryFile which opens
 * a temporary file using the standard library tmpfile function.
 */
#include <stdio.h>
#include <stdlib.h>

FILE *OpenTemporaryFile(void)
{
    //create a file pointer using standard function tmpfile()
    FILE *file = tmpfile();
    //if temporary file couldn't be created, exit the program
    if (file == NULL)
    {
        fprintf(stderr, "couldn't create a temporary file. Now exiting the program");
        exit(1);
    }
    return file;
}

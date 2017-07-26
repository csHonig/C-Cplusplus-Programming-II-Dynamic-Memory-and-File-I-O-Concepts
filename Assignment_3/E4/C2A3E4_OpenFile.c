/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 7/24/2017
 * File Name: C2A3E4_OpenFile.c
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the definition of function OpenFile which opens the file
 * fileName in read only text mode and exits  the program with error msg if
 * it could not open
 */
#include <stdlib.h>
#include <stdio.h>
FILE *OpenFile(const char *fileName)
{
    //open the file fileName in read only mode
    FILE *fp = fopen(fileName, "r");
    //if unable to open the file, print out the error in stderr and
    //exit the program
    if (fp == NULL)
    {
        fprintf(stderr, "Error opening file: %s\n", fileName);
        exit(1);
    }
    //return FILE pointer otherwise
    return fp;
}

/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 8/29/2017
 * File Name: C2A8E2_OpenFileBinary.c
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the definition of OpenFileBinary
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


FILE *OpenFileBinary(const char *fileName)
{
   FILE *inFile;
   //Test the file, if available open in binary, if not return error
   if ((inFile = fopen(fileName, "rb")) == NULL)
   {
      //Print to stderr when printing errors
      fprintf(stderr, "Unable to open file %s", fileName);
      exit(EXIT_FAILURE);
   }
   return(inFile);
}

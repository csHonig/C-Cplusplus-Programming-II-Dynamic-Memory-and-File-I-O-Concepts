/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 7/24/2017
 * File Name: C2A3E4_ParseStringFields.c
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the definition of function ParseStringFields which read
 * each line of the file pointed by fp, parses each line with the delimeter
 * "AEIOUaeiou\t\n", and prints them by suppressing the leading space if any
 */
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#define SIZE 255
#define DELIMITER "AEIOUaeiou\t\n"

//Function definition of ParseStringFields
void ParseStringFields(FILE *fp)
{
    char *delimiter = DELIMITER;
    int bufsize = SIZE;
    char buffer[SIZE];
    //read each line from the file pointed by fp into buffer
    while (fgets(buffer, bufsize, fp) != NULL)
    {
        //parse each line using strtok func with the delimiters pointed by
        // variable delimiter
        for (char *cptr = strtok(buffer, delimiter); cptr != NULL; cptr = strtok(NULL, delimiter))
        {
            //iteratively check if each token pointed by cptr has starting spaces
            while (isspace(*cptr))
            {
                ++cptr;
            }
            //print each token that has been separated out by delimeter
            puts(cptr);
        }
    }
}

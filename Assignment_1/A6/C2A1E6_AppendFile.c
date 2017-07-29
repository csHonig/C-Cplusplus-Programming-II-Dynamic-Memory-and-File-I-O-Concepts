/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 7/12/2017
 * File Name: C2A1E6_AppendFile.c
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file constains the definition of AppendFile function which opens the
 * files inFile and outFile using the minimum access privileges necessary and
 * append the contents of the file specified by inFile onto the file outFile
 * creating the outFile if it doesn't exist. It works for both binary and text
 * mode.
 *
 */
#include <stdio.h>
//This function is to append the inFile to outFile
int AppendFile(const char *inFile, const char *outFile)
{
    //opening the file in readonly mode in text + binary mode
    FILE *fi = fopen(inFile, "rb");
    //checking if opening the infile is successful or not
    if (fi == NULL)
    {
        fprintf(stderr, "Could not open file %s", inFile);
        return -1;
    }
    //open the outFile in append mode with text+binary mode
    FILE *fo = fopen(outFile, "ab");
    //if outFile could not be openned, close any other open files and return
    if (fo == NULL)
    {
        fprintf(stderr, "Could not open file %s", outFile);
        fclose(fo);
        return -1;
    }
    //Continue copying the char from fi to fo until eof is reached in fi
    for (;;)
    {
        int character = fgetc(fi);
        if (feof(fi))
        {
            break;
        }
        fputc(character, fo);
    }
    fclose(fi);
    fclose(fo);
    return 0;
}

/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 7/12/2017
 * File Name: C2A1E4_StrToUpper.c
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This File contains the definition of function StrToUpper which copies the
 * string represented by its second parameter, source into memory represented by
 * its first parameter destination with any lowercase converted to uppercase.
 */
#include <ctype.h>
//function to convert to upper case for any given string
size_t StrToUpper(char destination[], const char source[])
{
    const char *Initial = source;
    //checking if the source is empty
    if (!*source)
    {
        *destination = *source;
    }
    //when the source is not empty
    else
    {
        //foreach char pointed by source, change it to upper case
        while (*source)
        {
            char mychar = (char)toupper(*source);
            *destination = mychar;
            source++;
            destination++;
        }
        *destination = '\0';
    }
    //the difference between the initial and final pointer will become the total count of character
    return((size_t)(source - Initial));
}

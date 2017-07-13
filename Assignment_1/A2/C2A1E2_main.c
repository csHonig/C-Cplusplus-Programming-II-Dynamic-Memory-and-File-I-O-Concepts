/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 7/12/2017
 * File Name: C2A1E2_main.c
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * Class Type Employee is defined. Most of the member functions are also defined
 * Function overloading is implemented for functions name Set and Get
 *
 * DO NOT COPY OR RESTATE MY INSTRUCTIONS IN THE TITLE BLOCK.
 */
#include <stdio.h>
//the main func to print the total number of arguments along followed by value
int main(int argc, char *argv[])
{
    //the argc indicates the total argument count along with the program name
    printf("%d\n", argc);
    //argv is the argument vector which will point to each of the command line argument passed
    for (int iter = 0; iter < argc; iter++)
    {
        //printing each argument followed by new line character
        printf("%s\n", argv[iter]);
    }
    return 0;
}

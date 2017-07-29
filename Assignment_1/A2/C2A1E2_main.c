/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 7/14/2017
 * File Name: C2A1E2_main.c
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the main function definition, which takes variable command line arguments.
 * It then prints the total count of the number of command line arguments that were present when the
 * program was started followed by each arguments in the same order starting with argv[0]
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

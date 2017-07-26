/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 7/14/2017
 * File Name: C2A2E1_CountIntBitsF.c
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the definition of function CountIntBitsF which
 * determines the no. of bits used to represent a type int
 */
#define NO 1
#define SHIFTBY 1
//function to determine the no. of bits in the int type
int CountIntBitsF(void)
{
    //assign NO (i.e 1) to the variable intNo. Note that intNo only has one '1'
    //bit
    unsigned int intNo = NO;
    //set the count variable to 0
    int count = 0;
    //left shit intNo by 1 and continue doing in loop till the value of intNo
    //becomes 0
    for (; intNo; ++count)
    {
        intNo <<= SHIFTBY;
    }
    return count;
}

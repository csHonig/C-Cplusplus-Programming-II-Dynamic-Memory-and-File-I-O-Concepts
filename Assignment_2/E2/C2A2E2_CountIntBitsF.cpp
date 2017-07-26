/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 7/14/2017
 * File Name: C2A2E2_CountIntBitsF.cpp
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the definition of function CountIntBitsF which
 * determines the no. of bits used to represent a type int
 */
const int SHIFTBY = 1;
int CountIntBitsF()
{
    //intialize the intValue varaible to 1
    unsigned int intValue = 1;
    //intialize count of bit position to zero
    int count = 0;
    //run the loop until the value of initValue becomes non-zero
    while (intValue)
    {
        //left shit the value in intValue by SHIFTBY bit
        intValue <<= SHIFTBY;
        ++count;
    }
    return count;
}

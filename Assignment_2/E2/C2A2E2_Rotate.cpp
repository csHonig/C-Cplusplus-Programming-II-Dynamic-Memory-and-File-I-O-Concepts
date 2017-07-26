/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 7/14/2017
 * File Name: C2A2E2_Rotate.cpp
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the definition of function Rotate which
 * which rotates all bits in object by the number of bit positions given in
 * count
 */
int CountIntBitsF(void);
unsigned Rotate(unsigned object, int count)
{
    int CountIntBits = CountIntBitsF();
    //making sure the count amount doen't cross the width of the int type
    count %= CountIntBits;
    //Rotate Left
    if (count < 0)
    {
        count = -count;
        object = object << count | object >> (CountIntBits - count);
    }
    //Rotate Right
    else
    {
        object = object >> count | object << (CountIntBits - count);
    }
    return object;
}

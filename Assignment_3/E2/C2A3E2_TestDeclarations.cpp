/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 7/24/2017
 * File Name: C2A3E2_TestDeclarations.cpp
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the definition of function TestDeclarations which contains
 * the declaration of various function, pointers, reference and typecast as
 * provided by the Assignment requirements 
 */
const int SIZE = 9;
void TestDeclarations()
{
    //represents declaration for sentence one
    void *vp = 0;
    //represents declaration for sentence two
    int fcnA(int val);
    //represents declaration for sentence three
    float (**ppa)[SIZE];
    //represents declaration for sentence four
    float (**&rppa)[SIZE] = ppa;
    //represents declaration for sentence five
    ppa = (float (**)[SIZE])vp;
    return;
}

/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 8/7/2017
 * File Name: C2A6E2_GetValues.cpp
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the definition of the function GetValues which prompts user
 * to enter float values that needs to be sorted
 */
#include <iostream>
//#include <cstdlib>
//using namespace std;
float *GetValues(float *first, size_t elements)
{
    float *position = first;
    std::cout << "Enter " << elements << " number of elements:\n";
    //ask for the values in loop for elements no of count
    for (size_t count = 0; count < elements; ++count)
    {
        std::cin >> *position++;
    }
    return first;
}

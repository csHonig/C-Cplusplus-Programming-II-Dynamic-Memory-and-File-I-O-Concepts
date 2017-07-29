#ifndef C2A1E1_MACROS_H
/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 7/14/2017
 * File Name: C2A1E1_Macros.h
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the macro definition as below
 *  Product: takes two arguments and calculates the product of them
 *  Negate: It takes one argument and produce the negative value of this argument
 *  Elements: It takes one argument of array variable type and produces the total
 * count of  elements in that array
 */
#define C2A1E1_MACROS_H

#define Product(a,b) ((a) * (b))
#define Negate(a) (-(a))
#define Elements(a) (sizeof(a) / sizeof((a)[0]))

#endif

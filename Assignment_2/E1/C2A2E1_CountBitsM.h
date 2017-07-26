#ifndef C2A2E1_COUNTBITSM_H
/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 7/14/2017
 * File Name: C2A2E1_CountBitsM.h
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the macro definition for counting the no. of bits of
 * a given Object or Type.
 * The value produced by CountBitsM for type int could be different that the
 * value produced by CountIntBitsF. This is because, except for the type char,
 * in other types, all the bits might not be used to represent its value, so
 * padding might be enforced for those extra spaces. So this is the reason that
 * simply multiplying the no. of bits in type char by the no. of bytes in the
 * arbitrary datatype (as in CountBitsM macro) doesn't necessarily produce same
 * as those from CountIntBitsF for type int.
 */
#define C2A2E1_COUNTBITSM_H
#include <limits.h>
#define CountBitsM(objectOrType) ((int)sizeof(objectOrType) * CHAR_BIT)

#endif

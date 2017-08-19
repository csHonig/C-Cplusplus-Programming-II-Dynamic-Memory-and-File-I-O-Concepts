/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 7/31/2017
 * File Name: C2A4E3_pointerArray4D.cpp
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the implementation of 4D array without the need to have
 * storage map equation when accessing elements.
 */
extern const int DIM0 = 2, DIM1 = 3, DIM2 = 4, DIM3 = 5;
static float a1[DIM3], a2[DIM3], a3[DIM3], a4[DIM3], a5[DIM3], a6[DIM3], a7[DIM3],
a8[DIM3], a9[DIM3], a10[DIM3], a11[DIM3], a12[DIM3], a13[DIM3], a14[DIM3],
a15[DIM3], a16[DIM3], a17[DIM3], a18[DIM3], a19[DIM3], a20[DIM3], a21[DIM3],
a22[DIM3], a23[DIM3], a24[DIM3];
static float *b1[DIM2] = {a1, a2, a3, a4}, *b2[DIM2] = {a5, a6, a7, a8},
*b3[DIM2] = {a9, a10, a11, a12}, *b4[DIM2] = {a13, a14, a15, a16},
*b5[DIM2] = {a17, a18, a19, a20}, *b6[DIM2] = {a21, a22, a23, a24};
static float **c1[DIM1] = {b1, b2, b3}, **c2[DIM1] = {b4, b5, b6};
float ***pointerArray4D[DIM0] = {c1, c2};

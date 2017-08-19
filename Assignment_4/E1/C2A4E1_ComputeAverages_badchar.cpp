
/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 7/31/2017
 * File Name: C2A4E1_ComputeAverages.cpp
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the definition of the function ComputeAverages which
 * computers the average of all the elements in the 4D array represented by the
 * function’s 1st parameter using nexted loop method and store the result in the
 * in the addr specified by the second parameter. Also it computes the average
 * of the same elements of the 4D array now using compact pointers and store the
 * result in the addr specified by the function's third parameter
 */
#include "C2A4E1_ArraySize.h"
void ComputeAverages(float (*ptestArray)[DIM1][DIM2][DIM3], float *nestedAvg, float *linearAvg)
{
    //Initialize the value pointed by nextedAag and linearAvg to zero
    *nestedAvg = 0;
    *linearAvg = 0;
    for (int index0 =0; index0 < DIM0; ++index0)
        for (int index1 =0; index1 < DIM1; ++index1)
            for (int index2 =0; index2 < DIM2; ++index2)
                for (int index3 =0; index3 < DIM3; ++index3)
                    //add all the elements value to location pointed by nestedAvg
                    *nestedAvg += ptestArray[index0][index1][index2][index3];
    //divide the totalsum by total number of elements of the array
    *nestedAvg = *nestedAvg/(DIM0 * DIM1 * DIM2 * DIM3);
    //computer the average using compact pointer
    for (float *fptr = (float *)ptestArray; fptr < (float *)ptestArray +
        DIM0 * DIM1 * DIM2 * DIM3; ++fptr)
    {
        *linearAvg += *fptr;
    }
    *linearAvg = *linearAvg/(DIM0 * DIM1 * DIM2 * DIM3);

}

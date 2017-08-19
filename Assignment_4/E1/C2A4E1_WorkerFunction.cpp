/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 7/31/2017
 * File Name: C2A4E1_WorkerFunction.cpp
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the definitions of WorkerFunction which Initializes a 4D
 * array and computer the average of them by calling RandomizeArray function and
 * ComputeAverages function respectively
 */
#include "C2A4E1_ArraySize.h"
void RandomizeArray(float (*ptestArray)[DIM1][DIM2][DIM3]);
void ComputeAverages(float (*ptestArray)[DIM1][DIM2][DIM3], float *nestedAvg,
      float *linearAvg);
void WorkerFunction(float *nestedAvg, float *linearAvg)
{
    //a four D testArray is declared
    float testArray[DIM0][DIM1][DIM2][DIM3];
    //Initialize the arry testArray with random value generated
    RandomizeArray(testArray);
    //compute the nexted and linearAvg of the array elements of testArray
    ComputeAverages(testArray, nestedAvg, linearAvg);
    return;
}

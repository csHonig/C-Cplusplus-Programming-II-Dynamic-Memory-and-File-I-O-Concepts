/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 8/7/2017
 * File Name: C2A6E2_SortValues.cpp
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the definition of the function SortValues which sorts the
 * values pointed by first in descending order using bubble sort algo
 */
#include <cstdlib>
#include <cstdio>
float *SortValues(float *first, size_t elements)
{
    bool didSwap;
    float *last = &first[elements - 1];
    //outerloop which controls the number of passes for the bubble sort
    do
    {
        //current always points to the first element before starting of outerloop
        float *current = first;
        //innter loop which will compare each corresponding elements and exchange
        // the vlaue if condition is not met until end of the array is not reached
        // upto which the values are not sorted
        for (didSwap = false; current < last;)
        {
            float temp = *current;
            //swapping the values if the conition is true and rearranging current
            //variable so that it points to the next item
            if (temp < *++current)
            {
                float interim = *current;
                *current = temp;
                *--current = interim;
                current++;
                didSwap = true;
            }
        }
        //descrease the last by 1 since, after each iteration, the max/min values
        //bubbles up to the top
        --last;
    } while (didSwap);
    return first;
}

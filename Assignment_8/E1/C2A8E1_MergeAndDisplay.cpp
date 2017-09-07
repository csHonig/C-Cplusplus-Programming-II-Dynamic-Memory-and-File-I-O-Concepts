/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 8/29/2017
 * File Name: C2A8E1_MergeAndDisplay.cpp
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the definition of MergeAndDisplay function
 */
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void MergeAndDisplay(ifstream files[], size_t count)
{
    //Creates a buffer to readlines into
    string buffer;
    //Save the start of input array, and set end of loop
    ifstream *startSave = files, *end = files + count;
    while (count != 0)
    {
        for (files = startSave; files < end; ++files)
        {
            if (!files->is_open())
                continue;
            //reads the next
            getline(*files, buffer);
            //Need to check if data is actually present...may not be the best way
            if (files->eof())
            {
                //File has reached the end, close and subtract one from count
                files->close();
                --count;
            }
            else
                cout << buffer << "\n";
        }
    }
}

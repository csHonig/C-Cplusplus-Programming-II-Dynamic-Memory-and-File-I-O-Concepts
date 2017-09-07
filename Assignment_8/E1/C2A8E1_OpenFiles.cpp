/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 8/29/2017
 * File Name: C2A8E1_OpenFiles.cpp
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the definition of OpenFiles
 */
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

ifstream *OpenFiles(char * const fileNames[], size_t count)
{
    //Check if an empty array was sent
    if (count == 0)
    {
        cerr << "No files input\n";
        exit(EXIT_FAILURE);
    }
    //Allocate space for ifstream array
    ifstream *head;
    if ((head = new (nothrow) ifstream[count]) == NULL)
    {
        //Check if allocation successful
        cerr << "Couldn't allocate memory, closing\n";
        exit(EXIT_FAILURE);
    }
    for (size_t actFile = 0; actFile < count; actFile++)
    {
        //Open each file individually/safely in read only text mode
        head[actFile].open(fileNames[actFile]);
        if (!head[actFile].is_open())
        {
            //If unable to open, exits and prints error
            cerr << "Couldn't open file " << fileNames[actFile] << "\n";
            delete[] head;
            exit(EXIT_FAILURE);
        }
    }
    return head;
}

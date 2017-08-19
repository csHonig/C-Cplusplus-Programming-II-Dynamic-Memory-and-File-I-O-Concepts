/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 8/9/2017
 * File Name: C2A5E4_OpenFile.cpp
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the definition of function OpenFile which opens the file
 * fileName in read only text mode and exits  the program with error msg if
 * it could not open
 */
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;
//function to open the file fileName
void OpenFile(const char *fileName, ifstream &inFile)
{
    //open the file fileName in readonly text mode
    inFile.open(fileName);
    //if the file could not be oppened
    if (!inFile.is_open())
    {
        //write the error msg to cerr obj
        cerr << "Inputfile could not be openned:" << fileName;
        //terminate the program
        exit(1);
    }
    return;
}

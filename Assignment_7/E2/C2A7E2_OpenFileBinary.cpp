/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 8/22/2017
 * File Name: C2A7E2_OpenFileBinary.cpp
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the definition of function OpenFileBinary which opens the
 * file named in fileName in the read-only binary mode using the inFile object.
 */
#include <fstream>
#include <iostream>
using namespace std;
void OpenFileBinary(const char *fileName, ifstream &inFile)
{
    //open the file in binary mode
    inFile.open(fileName, ios::binary);
    if (!inFile.is_open()) {
        cerr  << "Unable to  open file " << fileName << "\n";
        exit(EXIT_FAILURE);
    }
}

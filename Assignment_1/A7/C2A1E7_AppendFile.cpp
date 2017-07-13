/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 7/12/2017
 * File Name: C2A1E7_AppendFile.cpp
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * Class Type Employee is defined. Most of the member functions are also defined
 * Function overloading is implemented for functions name Set and Get
 *
 * DO NOT COPY OR RESTATE MY INSTRUCTIONS IN THE TITLE BLOCK.
 */

#include <fstream>
#include <iostream>
using namespace std;
//This subroutine will append inFile to outFile
int AppendFile(const char *inFile, const char *outFile)
{
    //create input stream ifile and output stream ofile
    ifstream ifile(inFile, ios::binary);
    ofstream ofile(outFile, ios::app | ios::binary);
    //check if open operation is successful or not for ifile
    if (!ifile.is_open())
    {
        cerr << "inputfile could not be openned\n";
        return -1;
    }
    //check if open operation is sucessful or not for ofile
    if (!ofile.is_open())
    {
        cerr << "outputfile could not be openned\n";
        ifile.close();
        return -1;
    }
    //read char by char until EOF is detected and write to the output file
    for (;;)
    {
        int ch = ifile.get();
        if (ch == EOF)
            break;
        ofile.put((char)ch);
    }
    //closing both the ofile and ifile
    ofile.close();
    ifile.close();
    return 0;
}

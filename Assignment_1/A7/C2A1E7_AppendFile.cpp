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
 * This file constains the definition of AppendFile function which opens the
 * files inFile and outFile using the minimum access privileges necessary and
 * append the contents of the file specified by inFile onto the file outFile
 * creating the outFile if it doesn't exist. It works for both binary and text
 * mode.
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

/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 7/18/2017
 * File Name: C2A2E4_Reverse.cpp
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the definition of function Reverse which
 * recursively prints out each character until a separator is encountered in
 * reverse order. It also has the definition of isSeparator function which
 * basically finds out if the character under consideration is separator or not
 */
#include <fstream>
#include <iostream>
const int LEVELINC = 1;
const int LEVEL_FOR_UPPER_CASE = 1;
using namespace std;
//inline function definition to findout if given character is separator or not
inline bool isSeparator(int val)
{
    return(isspace(val) || val == '.' || val == '?' || val == EOF ||
            val == ':' || val == ';' || val == ',' || val == '!');
}
//recursive function definition for Reverse which prints out each character from
//input stream and returnout the separator
int Reverse(ifstream &inFile, const int level)
{
    //read the character from ifstream inFile and initialize auto varaible thisChar
    int thisChar = inFile.get();
    //check if the character read is a separator
    if (isSeparator(thisChar))
    {
        //returns the separator
        return thisChar;
    }
    else
    {
        //if thisChar is not separator, call the Reverse func again
        int thisSeparator = Reverse(inFile, level + LEVELINC);
        //change the first character after of the word separaterd by separator to
        //upper case
        if (level == LEVEL_FOR_UPPER_CASE)
            thisChar = toupper(thisChar);
        //print each character in reverse-order
        cout.put((char)thisChar);
        return thisSeparator;
    }
}

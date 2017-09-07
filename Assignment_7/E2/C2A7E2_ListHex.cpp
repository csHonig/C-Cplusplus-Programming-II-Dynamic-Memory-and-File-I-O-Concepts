/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 8/22/2017
 * File Name: C2A7E2_ListHex.cpp
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the definition of function ListHex which displays the contents
 * of the file in inFile as one pair of hexadecimal characters per file byte, zero-filled
 * on the left if necessary to produce the two characters.
 */
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
void ListHex(ifstream &inFile, int bytesPerLine)
{
    //dynamicaly allocating memory for bytesPerLine
    char *buffer = new char[(unsigned int)bytesPerLine];
    //filling the unfilled space with 0s
    cout << setfill('0') << hex;
    //read a total of bytesPerLine bytes from inFile into buffer until eof is found
    for (inFile.read(buffer, bytesPerLine); !inFile.eof(); inFile.read(buffer, bytesPerLine))
    {
        //pointing to the end of of buffer upto which bytes are filled
        char *end = buffer + (size_t)inFile.gcount();
        //iterating each of the byte
        for (char *ptr = buffer; ptr < end; ptr++)
        {
            cout << setw(2) << (int)(unsigned char)*ptr;
            //separate each byte with a space
            if (ptr < end - 1)
                cout << ' ';
        }
        //new line character after each bytesPerLine bytes read
        cout << '\n';
    }
    //one more processing for the last read operation which has eof detected
    char *end = buffer + (size_t)inFile.gcount();
    for (char *ptr = buffer; ptr < end; ptr++)
    {
        cout << setw(2) << (int)(unsigned char)*ptr;
        if (ptr < end - 1)
            cout << ' ';
    }
    delete[] buffer;
    return;
}

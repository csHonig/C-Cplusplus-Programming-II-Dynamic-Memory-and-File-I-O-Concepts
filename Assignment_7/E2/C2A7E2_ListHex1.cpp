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
    char *buffer = new char[1];
    std::streampos begin, end;
    size_t size;
    //pointer pointing to the beginning of the file
    begin = inFile.tellg();
    inFile.seekg(0, ios::end);
    //pointer pointing to the end of the file
    end = inFile.tellg();
    //total no of bytes in the file
    size = (size_t)(end - begin);
    //again going back to point to the beginning of the file
    inFile.seekg(0, ios::beg);
    //filling with 0 if room is enough for total of 2 bytes
    std::cout << std::setfill('0');
    std::cout << hex;
    for (int count = 1; size != 0; ++count, --size)
    {
        //reading one byte each time, but we can also read multiple bytes at time
        inFile.read(buffer, 1);
        //setting a width of 2 and printing the byte
        std::cout << std::setw(2) << (int)(unsigned char)*buffer;
        if (count % bytesPerLine == 0)
            std::cout << '\n';
        else
            std::cout << ' ';
    }
    delete[] buffer;
    return;
}

/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 7/12/2017
 * File Name: C2A1E8_Employee.cpp
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the definition of function Employee::Set which dynamically
 * allocates exactly the amount of memroy necessary to hold that string pointed
 * by ch with null terminator, set member name to point to that memory and copy
 * the string into that memory
 */
#include <cstring>
#include "C2A1E8_Employee.h"

//member function "Set" defintion of class Employee for name of the employee
void Employee::Set(const char *ch)
{
   //dynamic memory allocation for the name of the employee
   name = new char[strlen(ch) + 1];
   //creating a tmp char pointer that points to the beginning of allocated location
   char *dest = name;
   //Implementing deep copy--could have used memcpy also
   while ((*dest++ = *ch++) != '\0')
      ;
}

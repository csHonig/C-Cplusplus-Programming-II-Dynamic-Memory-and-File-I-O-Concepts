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
 * Class Type Employee is defined. Most of the member functions are also defined
 * Function overloading is implemented for functions name Set and Get
 *
 * DO NOT COPY OR RESTATE MY INSTRUCTIONS IN THE TITLE BLOCK.
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

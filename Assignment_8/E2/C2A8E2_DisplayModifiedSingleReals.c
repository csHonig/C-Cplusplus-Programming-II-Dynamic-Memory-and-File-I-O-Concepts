/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 8/29/2017
 * File Name: C2A8E2_DisplayModifiedSingleReals.c
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the definition of functions DisplayModifiedSingleReals
 * and DisplayHelperFunc
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BASE_POWA 2
#define HEX_SIZE 8
#define ARRAY_SIZE 4

#define F_PNORM 1
#define F_NNORM (-F_PNORM)
#define F_PDENORM 2
#define F_NDENORM (-F_PDENORM)
#define F_PZERO 3
#define F_NZERO (-F_PZERO)
#define F_PINF 4
#define F_NINF (-F_PINF)
#define F_PNAN 5
#define F_NNAN (-F_PNAN)

#define SIGN_MASK 0X80000000uL
#define EXP_MASK 0x7FC00000uL
#define FRAC_MASK 0x003FFFFFuL
#define FRAC_BITS 22
#define EXP_NBIAS 255
#define EXP_DBIAS 254
#define EXP_MAX 511
static int DisplayHelperFunc(unsigned long pattern, double *result)
{
   int signIsnegative = !!(SIGN_MASK & pattern);
   int exponent = (EXP_MASK & pattern) >> FRAC_BITS;
   long fraction = FRAC_MASK & pattern;
   int status;
   //Test for negative/postive zeros
   if (exponent == 0 && fraction == 0)
   {
      //logical test to decide if is negative or positive zero
      status = signIsnegative ? F_NZERO : F_PZERO;
      //compute value
      *result = 0;
   }
   //Test for negative/postive infinities
   else if (exponent == EXP_MAX && fraction == 0)
      status = signIsnegative ? F_NINF : F_PINF;
   //test for negative/postive NANs
   else if (exponent == EXP_MAX && fraction != 0)
      status = signIsnegative ? F_NNAN : F_PNAN;
   //Defaults case
   else
   {
      int bias;
      *result = fraction * pow(BASE_POWA, -FRAC_BITS);
      //if number is normalized
      if (exponent != 0)
      {
         //bias to use
         bias = EXP_NBIAS;
         status = signIsnegative ? F_NNORM : F_PNORM;
         ++*result;
      }
      else
      {
         bias = EXP_DBIAS;
         status = signIsnegative ? F_NDENORM : F_PDENORM;
      }
      *result *= pow(BASE_POWA, exponent - bias);
      //Negate number, if required
      if (signIsnegative)
         *result = -*result;
   }
   //return the status of the analysis
   return(status);
}

void DisplayModifiedSingleReals(FILE *inFile)
{
   double result;
   unsigned char buffer[ARRAY_SIZE];
   for (;;)
   {
      int arrayLoop, status;
      unsigned long pattern;
      //read ARRAY_SIZE byte of data from the inFile
      size_t readCount = fread(buffer, 1, ARRAY_SIZE, inFile);
      //if the total read is not equal to ARRAY_SIZE, EOF is reached Unexpectedly
      if (readCount != ARRAY_SIZE)
      {
         //if EOF is reached Unexpectedly
         if (readCount != 0)
            printf("Unexpected EOF\n");
         break;
      }
      pattern = (unsigned long)buffer[ARRAY_SIZE - 1];
      for (arrayLoop = ARRAY_SIZE - BASE_POWA; arrayLoop >= 0; arrayLoop--)
         pattern |= (unsigned long)buffer[arrayLoop] << (ARRAY_SIZE - 1 - arrayLoop) * HEX_SIZE;
      //print the pattern
      printf("0x%08lx     ", pattern);
      //calling DisplayHelperFunc for the status used in switch statement
      status = DisplayHelperFunc(pattern, &result);
      switch (status)
      {
      case F_PNORM:
         printf("+%-18eNormal\n", result);
         break;
      case F_NNORM:
         printf("%-19eNormal\n", result);
         break;
      case F_PDENORM:
         printf("+%-18eDenormal\n", result);
         break;
      case F_NDENORM:
         printf("%-19eDenormal\n", result);
         break;
      case F_PZERO:
         printf("+%-18eZero\n", result);
         break;
      case F_NZERO:
         printf("-%-18eZero\n", result);
         break;
      case F_PINF:
         printf("+INF\n");
         break;
      case F_NINF:
         printf("-INF\n");
         break;
      case F_PNAN:
         printf("+NAN\n");
         break;
      case F_NNAN:
         printf("-NAN\n");
         break;
      default:
         printf("This is an error\n");
      }
      //break from the for loop if feof is detected
      if (feof(inFile))
         break;
   }
}

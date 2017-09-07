/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 8/22/2017
 * File Name: C2A7E4_ProcessStructures.c
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the definition of three functions ReverseMembersEndian,
 * ReadStructures and WriteStructures
 * Answers:
 * (1): Yes, I got correct results for my implemenation
 * (2): I found a total of four padding bytes in my structure. These four padding
 * bytes are from after the structure's flt member. For my implemenation, its taking
 * 4 bytes for float, 8 bytes for double and 8 bytes for void pointer. So having
 * a padding of 4 bytes by the Compiler after float makes sense for the alligment
 * purpose.x
 */
#include "C2A7E4_Test-Driver.h"
#include <stdio.h>
#include <stdlib.h>
void *ReverseEndian(void *ptr, size_t size);

struct Test *ReverseMembersEndian(struct Test *ptr)
{
    //calling ReverseEndian function for each of the members of the structure
    ReverseEndian((void *)&ptr->flt, sizeof(ptr->flt));
    ReverseEndian((void *)&ptr->dbl, sizeof(ptr->dbl));
    ReverseEndian((void *)&ptr->vp, sizeof(ptr->vp));
    return ptr;
}

struct Test *ReadStructures(struct Test *ptr, size_t count, FILE *fp)
{
    //it reads the count Struct Test from fp into ptr
    if (fread(ptr, sizeof(struct Test), count, fp) != count)
    {
        fprintf(stderr, "Error in reading structures");
        exit(1);
    }
    return ptr;
}

struct Test *WriteStructures(const struct Test *ptr, size_t count, FILE *fp)
{
    //it writes the count Struct Test into fp from ptr
    if (fwrite(ptr, sizeof(ptr[0]), count, fp) != count)
    {
        fprintf(stderr, "couldn't write %zu number of struct Test Object", count);
        exit(1);
    }
    return (struct Test *)ptr;
}

/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 8/7/2017
 * File Name: C2A6E3_DisplayClassStatus.c
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the definition of the functions Compare, SortStudents and
 * DisplayClassStatus
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int Compare(const void *elemA, const void *elemB)
{
    // compare the strings and return
    return(strcmp(*(char **)elemA, *(char **)elemB));
}

void SortStudents(const char *studentList[], size_t studentCount)
{
    //the standard library function qsort used for qsorting the studentList
    qsort((void *)studentList, studentCount, sizeof(studentList[0]), Compare);
}

void DisplayClassStatus(const char *registrants[], size_t registrantCount,
                        const char *attendees[], size_t attendeeCount)
{
    printf("Not present:\n");

    for (size_t r_count = 0; r_count < registrantCount; r_count++)
    {
        char *Found;
        //standard library function bsearch is called for sorting purpose where the user defined
        //function pointer Compare is used within bsearch
        Found = bsearch(&registrants[r_count], attendees, attendeeCount, sizeof(attendees[r_count]), Compare);
        //If the registere student is not found in attenees array, print it
        if (Found == NULL)
            printf("    %s\n", registrants[r_count]);
    }
    printf("\nNot registered:\n");
    for (size_t a_count = 0; a_count < attendeeCount; a_count++)
    {
        char *Found;
        //standard library function bsearch is called for sorting purpose where the user defined
        //function pointer Compare is used within bsearch
        Found = bsearch(&attendees[a_count], registrants, registrantCount, sizeof(registrants[a_count]),
                        Compare);
        //If the attenee student is not found in registrants array, print it
        if (Found == NULL)
            printf("    %s\n", attendees[a_count]);
    }
    return;
}

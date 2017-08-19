/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 8/15/2017
 * File Name: C2A6E4_List.c
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the definition of function CreateList, PrintList, and
 * FreeList.
 */

#include "C2A6E4_List-Driver.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#define SIZE 255
#define DELIMITER " \n"
//function CreateList Creates a singly-linked list from strings it reads from the
//text file represented by parameter fp. Each list node represents a unique
//case-dependent string and the number of times it occurred in the file.
List *CreateList(FILE *fp)
{
    char *delimiter = DELIMITER;
    int bufsize = SIZE;
    char buffer[SIZE];
    List *head = NULL;
    while (fgets(buffer, bufsize, fp) != NULL)
    {
        for (char *cptr = strtok(buffer, delimiter); cptr != NULL; cptr = strtok(NULL, delimiter))
        {
            //iteratively check if each token pointed by cptr has starting spaces
            while (isspace(*cptr))
            {
                ++cptr;
            }
            //search the List for each cptr read
            size_t found = 0;
            for (List * ptr = head; ptr != NULL; ptr = ptr->next)
            {
                //if the two strings- cptr and ptr->str are same
                if (!strcmp(cptr, ptr->str))
                {
                    ptr->count++;
                    found = 1;
                    break;
                }
            }
            //if cptr read is not found in the list,
            //allocate the memory for the node ans store string cptr in that node
            if (!found)
            {
                List *newNode;
                newNode = (List *)malloc(sizeof(List));
                if (newNode == NULL)
                {
                    fprintf(stderr, "Unable to allocate memory for newNode");
                    exit(1);
                }
                //allocate memory for the string
                size_t strSize = strlen(cptr);
                newNode->str = (char *)malloc(sizeof(cptr[0]) * strSize + 1);
                if (newNode->str == NULL)
                {
                    fprintf(stderr, "Unable to allocate memory for newNode->str");
                    exit(1);
                }
                //copy the string into the memory location
                memcpy((void *)newNode->str, (void *)cptr, strSize + 1);
                newNode->count = 1;
                //push the newNode onto the top of stack
                newNode->next = head;
                head = newNode;
            }
        }
    }
    return (List *)head;
}

//function PrintList displays a non-sorted table of the data attributes from the
// list whose head  pointer is passed to it, starting at the head of the list.
List *PrintList(const List *head)
{
    const List *ptr = head;
    //itterate over all the nodes until the node is terminated by NULL
    for (; ptr != NULL; ptr = ptr->next)
    {
        //print each string in the node with left justified while no. of occurrence
        //of that string right justifed
        printf("%-15s    %4d ea\n", ptr->str, ptr->count);
    }
    return((List *)head);
}

//function FreeList frees all dynamic allocations in the list.
void FreeList(List *head)
{
    //if List is not empty list
    if (head != NULL)
    {
        while (head->next != NULL)
        {
            List *ptr = head->next;
            free(head->str);
            free(head);
            head = ptr;
        }
        //frees the remaining single node
        free(head->str);
        free(head);
    }
}

/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 7/24/2017
 * File Name: C2A3E3_RecordOpinions.c
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the definition of function RecordOpinions which prompts
 * user for their ratings of a product, counts the quantity of each rating,
 * and displays a table of the total quantity of each rating.
 */
#define ENDPOINT 5
#define TERMINATE 999

#define SIZE (2 * ENDPOINT + 1)
#include <stdio.h>
//function defintion of RecordOpinions
void RecordOpinions(void)
{
    //define and initialize the count array to zero
    int count[SIZE] = {0};
    //pointer pcount points to the index ENDPOINT of count array  which is
    //treated as 0 index for pcount for supporting -ve indexing
    int *pcount = &count[ENDPOINT];

    for (;;)
    {
        printf("Please enter the rating in range %d to %d, %d being the highest\n",
                ENDPOINT, -ENDPOINT, ENDPOINT);
        int userresponse;
        scanf("%d", &userresponse);
        //for the valid userresponse, increment the value pointed by pcount
        //offset by userresponse
        if (-ENDPOINT <= userresponse && userresponse <= ENDPOINT)
            pcount[userresponse]++;
        else if (userresponse  == TERMINATE)
        {
            printf("%5s%10s\n%5s%10s\n", "Rating", "Responses", "------", "---------");
            //print the tabular output of the all the response count
            for (int loop = -ENDPOINT; loop <= ENDPOINT; ++loop)
                printf("%5d%10d\n", loop, pcount[loop]);
            break;
        }
        else
            printf("Wrong Entry: Please try again\n");
    }
}

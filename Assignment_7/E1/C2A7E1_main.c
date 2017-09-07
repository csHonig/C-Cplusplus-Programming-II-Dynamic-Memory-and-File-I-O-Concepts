/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 8/22/2017
 * File Name: C2A7E1_main.c
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the definition of related functions and main function for
 * creating a hash table for the text read from a file where each bin stores
 * the data in binary tree
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* fewest command line arguments */
#define MIN_ARGS 3
/* index of file name argument */
#define FILE_ARG_IX 1
/* index of bin count argument */
#define BINS_ARG_IX 2
typedef struct Node NODE;
/* size of input buffer */
#define LINE_LEN 256
/* field width for input buffer scan */
#define BUFFMT "%255"

void *SafeMalloc(size_t size)
{
    void *vp;
    //allocate the memory for size bytes
    if ((vp = malloc(size)) == NULL)
    {
        //if not able to allocate memory, exit with error msg
        fputs("Out of memory\n", stderr);
        exit(EXIT_FAILURE);
    }
    return(vp);
}

FILE *OpenFile(const char *fileName)
{
    FILE *fp;
    //open the file fileName in read only mode
    if ((fp = fopen(fileName, "r")) == NULL)
    {
        //if opening the file failed, print the error msg in stderr
        fprintf(stderr, "File \"%s\" didn't open.\n", fileName);
        perror(fileName);
        //exit the program
        exit(EXIT_FAILURE);
    }
    return fp;
}

struct Node
{
    char *strng;
    size_t count;
    NODE *left, *right;
};

typedef struct
{
    size_t nodes;
    NODE *firstNode;
} BIN;

typedef struct
{
    size_t bins;
    BIN *firstBin;
} TABLE;

/* get bin value from key */
int HashFunction(const char *key, size_t bins)
{
    /* value is character count % bins */
    return((int)(strlen(key) % bins));
}

/* CreateTable creates and initializes the hash table and its bins */
TABLE *CreateTable(size_t bins)
{
    TABLE *hashTable;
    BIN *bin, *end;
    /* alloc desc struct */
    hashTable = (TABLE *)SafeMalloc(sizeof(TABLE));
    /* how many bins */
    hashTable->bins = bins;
    /* alloc bins */
    hashTable->firstBin = (BIN *)SafeMalloc(bins * sizeof(BIN));
    /* end of bins */
    end = hashTable->firstBin + bins;
    /* initialize bins */
    for (bin = hashTable->firstBin; bin < end; ++bin)
    {
        /* no list nodes */
        bin->nodes = 0;
        /* no list */
        bin->firstNode = NULL;
    }
    return(hashTable);
}

NODE *BuildList(NODE *pNode, char *str, BIN *binptr)
{
    /* string not found */
    if (pNode == NULL)
    {
        /* length of string */
        size_t length = strlen(str) + 1;
        /* allocate a node */
        pNode = (NODE *)SafeMalloc(sizeof(NODE));
        pNode->strng = (char *)SafeMalloc(length);
        /* copy string */
        memcpy(pNode->strng, str, length);
        /* 1st occurrence */
        pNode->count = 1;
        /* no subtrees */
        pNode->left = pNode->right = NULL;
        binptr->nodes++;
    }
    else
    {
        /* compare strings */
        int result = strcmp(str, pNode->strng);
        /* new string == current */
        if (result == 0)
            /* increment occurrence */
            ++pNode->count;
        /* new string < current */
        else if (result < 0)
            /* traverse left */
            pNode->left = BuildList(pNode->left, str, binptr);
        /* new string > current */
        else
            /* traverse right */
            pNode->right = BuildList(pNode->right, str, binptr);
    }
    return(pNode);
}
/*  PrintTree recursively prints the binary tree in pNode alphabetically */
void PrintTree(const NODE *pNode)
{
    /* if child exists */
    if (pNode != NULL)
    {
        /* traverse left */
        PrintTree(pNode->left);
        printf("%4d  %s\n", (int)pNode->count, pNode->strng);
        /* traverse right */
        PrintTree(pNode->right);
    }
}

/* PrintTable prints the hash table */
void PrintTable(const TABLE *hashTable)
{
    BIN *bin, *end;
    /* end of bins */
    end = hashTable->firstBin + hashTable->bins;
    /* visit bins */
    for (bin = hashTable->firstBin; bin < end; ++bin)
    {
        //NODE *node;
        printf("%d entries for bin %d:\n",
            (int)bin->nodes, (int)(bin - hashTable->firstBin));
        /* Visit nodes */
        PrintTree(bin->firstNode);
    }
}
/*  FreeTree recursively frees the binary tree in pNode */
void FreeTree(NODE *pNode)
{
    /* if child exists */
    if (pNode != NULL)
    {
        /* traverse left */
        FreeTree(pNode->left);
        /* traverse right */
        FreeTree(pNode->right);
        /* free the string */
        free(pNode->strng);
        /* free the node */
        free(pNode);
    }
}

/* FreeTable frees the hash table */
void FreeTable(TABLE *hashTable)
{
    BIN *bin, *end;
    /* end of bins */
    end = hashTable->firstBin + hashTable->bins;
    /* visit bins */
    for (bin = hashTable->firstBin; bin < end; ++bin)
    {
        FreeTree(bin->firstNode);
    }
    /* free all bins */
    free(hashTable->firstBin);
    /* free table descriptor */
    free(hashTable);
}

int main(int argc, char *argv[])
{
    /* word string buffer */
    char buf[LINE_LEN];
    /* file name buffer */
    char fileName[LINE_LEN];
    /* number of bins to create */
    int howManyBins;
    /* pointer to hash table */
    TABLE *hashTable;
    FILE *fp;

    /* Read file name from command line */
    if (argc < MIN_ARGS || sscanf(argv[FILE_ARG_IX], BUFFMT "s", fileName) != 1)
    {
        fprintf(stderr, "No file name specified on command line\n");
        return EXIT_FAILURE;
    }
    fp = OpenFile(fileName);

    /* Read bin count from command line */
    if (sscanf(argv[BINS_ARG_IX], "%d", &howManyBins) != 1)
    {
        fprintf(stderr, "No bin count specified on command line\n");
        return EXIT_FAILURE;
    }
    /* allocate table array */
    hashTable = CreateTable((size_t)howManyBins);
    /* get string from file */
    while (fscanf(fp, BUFFMT "s", buf) != EOF)
    {
        /* find appropriate bin */
        BIN *bin = &hashTable->firstBin[HashFunction(buf, (size_t)howManyBins)];
        NODE *nptr = BuildList(bin->firstNode, buf, bin);
        bin->firstNode = nptr;
    }
    fclose(fp);
    PrintTable(hashTable);
    /* print all strings */
    FreeTable(hashTable);
    /* free the table */
    return(EXIT_SUCCESS);
}

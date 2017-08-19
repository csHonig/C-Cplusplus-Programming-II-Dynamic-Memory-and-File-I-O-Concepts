/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 8/9/2017
 * File Name: C2A5E4_DetectFloats.cpp
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file contains the definition of function DetectFloats which parse a given
 * string and determines whether it is a valid floating literal or not
 */
#include "C2A5E4_StatusCode-Driver.h"
#include <cctype>
StatusCode DetectFloats(const char *chPtr)
{
    //enum for the nine states from the state diagram, and initialize state to START
    enum States
    {
        START,
        NO_WHOLE,
        FRACT,
        INTERIM_EXPONENT,
        LONG,
        EXPONENT,
        SIGN_EXPONENT,
        FLOAT,
        WHOLE
    } state = START;

    //starting the infinite loop
    for (;;)
    {
        //switch to appropiate state based on the previous state
        switch (state)
        {
            //each case is unique state and trasition from it to other state
            // failed case or success case has been derived from the state
            //machine diagram
            case START:
                if (*chPtr == '.')
                    state = NO_WHOLE;
                else if (isdigit(*chPtr))
                    state = WHOLE;
                else
                    return NOTFLOATING;
                break;

            case NO_WHOLE:
                if (isdigit(*chPtr))
                    state = FRACT;
                else
                    return NOTFLOATING;
                break;

            case FRACT:
                if (isdigit(*chPtr))
                    state = FRACT;
                else if (*chPtr == '\0')
                    return TYPE_DOUBLE;
                else if (*chPtr == 'E' || *chPtr == 'e')
                    state = INTERIM_EXPONENT;
                else if (*chPtr == 'L' || *chPtr == 'l')
                    state = LONG;
                else if (*chPtr == 'F' || *chPtr == 'f')
                    state = FLOAT;
                else
                    return NOTFLOATING;
                break;

            case WHOLE:
                if (isdigit(*chPtr))
                    state = WHOLE;
                else if (*chPtr == '.')
                    state = FRACT;
                else if (*chPtr == 'E' || *chPtr == 'e')
                    state = INTERIM_EXPONENT;
                else
                    return NOTFLOATING;
                break;

            case INTERIM_EXPONENT:
                if (*chPtr == '+' || *chPtr == '-')
                    state = SIGN_EXPONENT;
                else if (isdigit(*chPtr))
                    state = EXPONENT;
                else
                    return NOTFLOATING;
                break;

            case LONG:
                if (*chPtr == '\0')
                    return TYPE_LDOUBLE;
                else
                    return NOTFLOATING;

            case EXPONENT:
                if (isdigit(*chPtr))
                    state = EXPONENT;
                else if (*chPtr == 'F' || *chPtr == 'f')
                    state = FLOAT;
                else if (*chPtr == 'L' || *chPtr == 'l')
                    state = LONG;
                else if (*chPtr == '\0')
                    return TYPE_DOUBLE;
                else
                    return NOTFLOATING;
                break;

            case SIGN_EXPONENT:
                if (isdigit(*chPtr))
                    state = EXPONENT;
                else
                    return NOTFLOATING;
                break;

            case FLOAT:
                if (*chPtr == '\0')
                    return TYPE_FLOAT;
                else
                    return NOTFLOATING;
        }
        chPtr++;
    }
}

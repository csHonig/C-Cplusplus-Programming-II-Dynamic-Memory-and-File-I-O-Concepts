#ifndef C2A4E2_STORAGEMAP5D
/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 7/31/2017
 * File Name: C2A4E2_StorageMap5D.h
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * This file defines the macro StorageMap5D whose first parameter ptr is the
 * pointer to the first element, idx0 through idx4-indices of the desired
 * element of the array and dim1 through dim4 are rightmost 4 Dimennsions of the
 * array(dim0 is not needed).
 */
#define C2A4E2_STORAGEMAP5D
#define StorageMap5D(ptr, idx0, idx1, idx2, idx3, idx4, dim1, dim2, dim3, dim4) \
 (*((ptr) + (idx0) * (dim1) * (dim2) * (dim3) * (dim4) + (idx1) * (dim2) * \
 (dim3) * (dim4) +(idx2) * (dim3) * (dim4) + (idx3) * (dim4) + (idx4)))
#endif

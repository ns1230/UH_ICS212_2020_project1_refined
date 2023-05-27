//*****************************************************************
//
//  NAME:        Nonoka Sasaki
//
//  PROJECT:     Project1
//  
//  CLASS:       UHM ICS 212
//
//  DATE:        March 12, 2020;  refined May 27, 2023
//  
//  FILE:        database.c
//  
//  DESCRIPTION:
//  database.h is a header file that defines the structure and function prototypes used in the database operations. 
//  It contains the structure definition for the "record" data type, which represents a single record in the database. 
//  The structure includes fields such as account number, name, and address.
//  
/****************************************************************/

struct record
{
    int                accountno;
    char               name[25];
    char               address[80];
    struct record*     next;            
};



































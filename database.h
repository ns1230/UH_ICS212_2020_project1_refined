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
//  FILE:        database.h
//  
//  DESCRIPTION:
//  database.h is a header file that defines the structure and function prototypes used in the database operations. 
//  It contains the structure definition for the "record" data type, which represents a single record in the database. 
//  The structure includes fields such as account number, name, and address.
//  
/****************************************************************/

#ifndef  _RECORD_H_
#define _RECORD_H_

#include "record.h"

#endif


extern int debug;
extern int setting;     //is this really needed? not used in any file other than main in user_interface


/*****************************************************************
//
//  Function name: addRecord
//  //  //  //
//  //  //  //  DESCRIPTION:   adds a record
//  //  //  //
//  //  //  //  Parameters:    start (struct record **): points to beggining of linked list
//  //  //  //                 accountnum (int): users account number
//  //  //  //                 name(char[]): users name
//  //  //  //                 address(char[]): users mailing address
//  //  //  //
//  //  //  //  Return values:  0 : success
//  //  //  //
//  //  //  ****************************************************************/

int addRecord (struct record **, int, char [ ],char [ ]);


/*****************************************************************
//
//  Function name: printRecord
//  //  //  //
//  //  //  //  DESCRIPTION:   prints a record
//  //  //  //
//  //  //  //  Parameters:    start (struct record *): points to beggining of linked list
//  //  //  //                 accountnum (int): users account number
//  //  //  //
//  //  //  //  Return values:  0 : success
//  //  //  //
//  //  //  ****************************************************************/

int printRecord (struct record *, int);


/*****************************************************************
//
//  Function name: printAllRecord
//  //  //  //
//  //  //  //  DESCRIPTION:   prints all the records
//  //  //  //
//  //  //  //  Parameters:    start (struct record **): points to beggining of linked list
//  //  //  //
//  //  //  ****************************************************************/

void printAllRecords(struct record *);


/*****************************************************************
//
//  Function name: modifyRecord
//  //  //  //
//  //  //  //  DESCRIPTION:   modyfies a record
//  //  //  //
//  //  //  //  Parameters:    start (struct record **): points to beggining of linked list
//  //  //  //                 accountnum (int): users account number
//  //  //  //                 address(char[]): users mailing address
//  //  //  //
//  //  //  //  Return values:  0 : success
//  //  //  //
//  //  //  ****************************************************************/

int modifyRecord (struct record *, int, char [ ]);


/*****************************************************************
//
//  Function name: deleteRecord
//  //  //  //
//  //  //  //  DESCRIPTION:   deletes a record
//  //  //  //
//  //  //  //  Parameters:    start (struct record **): points to beggining of linked list
//  //  //  //                 accountnum (int): users account cumber
//  //  //  //                 
//  //  //  //  Return values:  0 : success
//  //  //  //
//  //  //  ****************************************************************/

int deleteRecord(struct record **, int);


/*****************************************************************
//
//  Function name: cleanup
//  //
//  //  DESCRIPTION:   releases all allocated spaces in the heap memory and assign NULL to start
//  //
//  //  Parameters:    start (struct record **): points to beggining of linked list
//  //
//  ****************************************************************/

void cleanup(struct record**);


/*****************************************************************
//
//  Function name: readfile
//  //
//  //  DESCRIPTION:   reads a file and puts it in an array
//  //
//  //  Parameters:    start (struct record **): points to beggining of linked list
//  //                 file(char[]): name of the file
//  //                 
//  //  Return values:  0 : success
//  //
//  ****************************************************************/

int readfile(struct record **, char []);


/*****************************************************************
//
//  Function name: writefile
//  //
//  //  DESCRIPTION:   writes into a file from an array
//  //
//  //  Parameters:    start (struct record **): points to beggining of linked list
//  //                 file(char[]): name of the file
//  //                 
//  //  Return values:  0 : success
//  //
//  ****************************************************************/

int writefile(struct record *, char []);


void cleanup(struct record**);














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

extern int debug;

/*****************************************************************
//
//  Function name: addRecord
//
//  DESCRIPTION:   adds a new record to the database.
//
//  Parameters:    start (struct record**): points to the beginning of the linked list
//                 accountnum (int): account number of the new record
//                 name (char[]): name of the new record
//                 address (char[]): address of the new record
//
//  Return value:  None
//
*****************************************************************/
int addRecord (struct record **, int, char [ ],char [ ]);


/*****************************************************************
//
//  Function name: printRecord
//
//  DESCRIPTION:   prints a record with the given account number.
//
//  Parameters:    start (struct record*): points to beginning of linked list
//                 accountnum (int): account number of the record to print
//
//  Return value:  0 : success
//                -1: record not found
//
*****************************************************************/
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

#endif














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
//  Function name: printAllRecords
//
//  DESCRIPTION:   prints all the records in the database.
//
//  Parameters:    start (struct record*): points to the beginning of the linked list
//
//  Return value:  None
//
*****************************************************************/
void printAllRecords(struct record *);


/*****************************************************************
//
//  Function name: modifyRecord
//
//  DESCRIPTION:   modifies the address of a record with the given account number.
//
//  Parameters:    start (struct record*): points to beginning of linked list
//                 accountnum (int): account number of the record to modify
//                 address (char[]): new mailing address
//
//  Return value:  0 : success
//                -1: record not found
//
*****************************************************************/
int modifyRecord (struct record *, int, char [ ]);


/*****************************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION:   deletes a record from the database based on the account number.
//
//  Parameters:    start (struct record**): points to beginning of linked list
//                 accountnum (int): account number of the record to delete
//
//  Return value:  0 : success
//                -1: record not found
//
*****************************************************************/
int deleteRecord(struct record **, int);


/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   reads records from a file and adds them to the linked list.
//
//  Parameters:    start (struct record**): points to the pointer to the beginning of the linked list
//                 file (char[]): name of the file to read from
//
//  Return value:  0 : success
//                -1: error occurred while reading the file
//
*****************************************************************/
int readfile(struct record **, char []);


/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   writes records from the linked list into a file.
//
//  Parameters:    start (struct record*): points to the beginning of the linked list
//                 file (char[]): name of the file to write to
//
//  Return value:  0 : success
//                -1: error occurred while writing to the file
//
*****************************************************************/
int writefile(struct record *, char []);


/*****************************************************************
//
//  Function name: cleanup
//
//  DESCRIPTION:   Frees the memory allocated for the linked list
//                 and sets the start pointer to NULL, effectively
//                 clearing the database.
//
//  Parameters:    start (struct record**): points to the beginning
//                 of the linked list
//
//  Return value:  None
//
*****************************************************************/
void cleanup(struct record**);

#endif














/*****************************************************************
//
//  NAME:        Nonoka Sasaki
//  //  //
//  //  //  HOMEWORK:    project1
//  //  //
//  //  //  CLASS:       ICS 212
//  //  //
//  //  //  INSTRUCTOR:  Ravi Narayan
//  //  //
//  //  //  DATE:        March 12, 2020
//  //  //
//  //  //  FILE:        database.h
//  //  //
//  //  //  DESCRIPTION:
//  //  //   This file is the header file for database for project1.
//  //  //   It contains addRecord, printRecord, printAllRecords, modifyrecord, and
//  //  //   deleteRecord.
//  //  //
//  //  ****************************************************************/

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














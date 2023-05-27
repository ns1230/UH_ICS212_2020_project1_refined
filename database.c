/*****************************************************************
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
//  Database.c is a source file that contains the implementation of various functions for managing a database of records. 
//  It provides functions for adding records, deleting records, modifying records, printing individual records, 
//  printing all records, reading records from a file, and writing records to a file. 
//  The functions are designed to work with a linked list data structure to store and manipulate the records.
//  
/****************************************************************/

#include<stdio.h>
#include<string.h>
#include <stdlib.h>

#ifndef  _RECORD_H_
#define _RECORD_H_
#include "record.h"
#endif

#ifndef  _DATABASE_H_
#define _DATABASE_H_
#include "database.h"
#endif


int debug = 0;

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

int addRecord(struct record** start, int accountnum, char uname[], char uaddress[])
{

    struct record* curr;
    struct record* prev;
    struct record* temp;
    int returnval = -1;

    if (debug == 1)
    {
        printf("addRecord has been called\n");
        printf("This is a debug mode\n");
        printf("You have passed account number: %d, \n", accountnum);
        printf("name: %s, and address: %s \n", uname, uaddress);
    }
    else
    {
        //printf("addRecord has been called\n");
    }

    temp = (struct record*)malloc(sizeof(struct record));
    if (temp == NULL) {
        printf("Failed to allocate memory for new record.\n");
        return returnval;
    }

    temp->accountno = accountnum;
    //strcpy(temp->name, uname, 25);
    strcpy_s(temp->name, 25, uname);
    //strcpy(temp->address, uaddress, 80);
    strcpy_s(temp->address, 80, uaddress);
    temp->next = NULL;

    if (*start == NULL) {
        *start = temp;
    }
    else {
        curr = *start;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = temp;
    }

    returnval = 0;
    return returnval;
}



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
int printRecord(struct record* start, int accountnum)
{
    struct record* curr = start;

    if (debug == 1)
    {
        printf("printRecord has been called. \n");
        printf("This is a debug mode\n");
        printf("You have passed  struct record pointer start, and the account number: %d \n", accountnum);
    }
    if (debug != 1)
    {
        //printf("printRecord has been called. \n");
    }

    // Traverse the linked list to find the record with the given account number
    while (curr != NULL && curr->accountno != accountnum) {
        curr = curr->next;
    }

    // If the record is found, print its details
    if (curr != NULL) {
        printf("\n");
        printf("Account Number: %d\n", curr->accountno);
        printf("Name: %s\n", curr->name);
        printf("Address: %s\n", curr->address);
        return 0;
    }
    else {
        printf("Record with account number %d not found.\n", accountnum);
        return -1;  // Record not found
    }
}



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

void printAllRecords(struct record* start)
{
    struct record* curr;
    curr = start;

    if (debug == 1)
    {
        printf("PrintAllRecords has been called. \n");
        printf("This is a debug mode\n");
        printf("You have passed the struct record pointer\n");
    }
    else if (debug != 1)
    {
        //printf("PrintAllRecords has been called. \n");
    }
    if (curr == NULL)
    {
        printf("There are no records\n");
    }
    else
    {
        while (curr != NULL)
        {
            printf("\n");
            printf("Account Number: %d\n", curr->accountno);
            printf("Name: %s\n", curr->name);
            printf("Address: %s\n\n", curr->address);
            curr = curr->next;
        }
    }
}


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
int modifyRecord(struct record* start, int accountnum, char address[])
{
    struct record* curr = start;

    if (debug == 1)
    {
        printf("modifyRecord has been called. \n");
        printf("This is a debug mode\n");
        printf("You have passed the struct record pointer, account number: %d, and address: %s \n", accountnum, address);
    }
    else if (debug != 1)
    {
        //printf("ModifyRecord has been called.  \n");
    }

    // Traverse the linked list to find the record with the given account number
    while (curr != NULL && curr->accountno != accountnum) {
        curr = curr->next;
    }

    // If the record is found, modify its address
    if (curr != NULL) {
        //strncpy(curr->address, address, sizeof(curr->address));
        strcpy_s(curr->address, sizeof(curr->address), address);
        curr->address[sizeof(curr->address) - 1] = '\0';  // Ensure the address is null-terminated
        printf("Address modified successfully.\n");
        return 0;
    }
    else {
        printf("Record with account number %d not found.\n", accountnum);
        return -1;  // Record not found
    }
}



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

int deleteRecord(struct record** start, int accountnum)
{
    struct record* prev = NULL;
    struct record* curr = *start;

    if (debug == 1)
    {
        printf("deleteRecord has been called. \n");
        printf("This is a debug mode\n");
        printf("You have passed the struct record pointer, and account number: %d \n", accountnum);
    }
    if (debug != 1)
    {
        //printf("deleteRecord has been called. \n");
    }

    // Traverse the linked list to find the record with the given account number
    while (curr != NULL && curr->accountno != accountnum) {
        prev = curr;
        curr = curr->next;
    }

    // If the record is found, delete it
    if (curr != NULL) {
        // If it's the first record, update the start pointer
        if (prev == NULL) {
            *start = curr->next;
        }
        else {
            prev->next = curr->next;
        }

        // Free the memory allocated for the record
        free(curr);
        printf("Record with account number %d has been deleted.\n", accountnum);
        return 0;
    }
    else {
        printf("Record with account number %d not found.\n", accountnum);
        return -1;  // Record not found
    }
}


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
int readfile(struct record** start, const char* file) {
    FILE* fp;
    char line[150];
    int accountnum;
    char name[25];
    char address[80];
    int lineNum = 0;

    if (debug == 1) {
        printf("This is the readfile function.\n");
        printf("This is a debug mode.\n");
        printf("You have passed the struct record pointer and the file name: %s \n", file);
    }

    // Open the file for reading
    errno_t err = fopen_s(&fp, file, "r");
    if (err != 0) {
        printf("File opening error occurred.\n");
        return -1;
    }
    if (fp == NULL) {
        printf("Failed to open the file: %s\n", file);
        return -1;
    }

    // Read the file line by line
    while (fgets(line, sizeof(line), fp) != NULL) {
        lineNum++;

        // Remove newline character at the end of the line
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        // Parse based on line number
        switch (lineNum % 3) {
        case 1: // Account number
            if (sscanf_s(line, "%d", &accountnum) != 1) {
                printf("Error parsing account number in line %d\n", lineNum);
                fclose(fp);
                return -1;
            }
            break;
        case 2: // Name
            strncpy_s(name, sizeof(name), line, _TRUNCATE);
            break;
        case 0: // Address
            strncpy_s(address, sizeof(address), line, _TRUNCATE);
            addRecord(start, accountnum, name, address);
            break;
        }
    }

    fclose(fp);
    printf("File %s has been read successfully.\n", file);
    return 0;
}



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
int writefile(struct record* start, const char* file) {
    FILE* fp;
    struct record* current = start;

    if (debug == 1) {
        printf("This is the writefile function.\n");
        printf("This is a debug mode.\n");
        printf("You have passed the struct record pointer and the file name: %s \n", file);
    }

    // Open the file for writing
    errno_t err = fopen_s(&fp, file, "w");
    if (err != 0) {
        printf("File opening error occurred.\n");
        return -1;
    }
    if (fp == NULL) {
        printf("Failed to open the file: %s\n", file);
        return -1;
    }

    // Write each record to the file
    while (current != NULL) {
        //fprintf(fp, "%d\n", current->accountno);
        //fprintf(fp, "%s\n", current->name);
        fprintf(fp, "%d\n%s", current->accountno, current->name);
        fprintf(fp, "%s\n", current->address);
        current = current->next;
    }

    fclose(fp);
    printf("Records have been written to the file: %s\n", file);
    return 0;
}


/*****************************************************************
//
//  Function name: cleanup
//  //
//  //  DESCRIPTION:   releases all allocated spaces in the heap memory and assign NULL to start
//  //
//  //  Parameters:    start (struct record **): points to beggining of linked list
//  //
//  ****************************************************************/

void cleanup (struct record** start)
{
    struct record* one;
    struct record* two;
    one = NULL;
    two = NULL;
    one = *start;
    two = *start;

    if (debug == 1)
    {
        printf("This is the cleanup function.\n");
        printf("struct record pointer start was passed.\n");
    }

    if (one != NULL)
    {
        while (one->next != NULL)
        {
            two = one;
            one = one->next;
            free(two);
        }
        free(one);
    }
}





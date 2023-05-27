/*****************************************************************
//
//  NAME:        Nonoka Sasaki
//  //  //  //
//  //  //  //  HOMEWORK:    project1
//  //  //  //
//  //  //  //  CLASS:       ICS 212
//  //  //  //
//  //  //  //  INSTRUCTOR:  Ravi Narayan
//  //  //  //
//  //  //  //  DATE:        March 12, 2020
//  //  //  //
//  //  //  //  FILE:        database.c
//  //  //  //
//  //  //  //  DESCRIPTION:
//  //  //  //   This file is the database for project1.
//  //  //  //   It contains addRecord, printRecord, printAllRecords, modifyrecord, deleteRecord, readfile, writefile, and cleanup functions.
//  //  //  //
//  //  //  ****************************************************************/

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
/*
int addRecord (struct record** start, int accountnum, char uname[],char uaddress[])
{
    struct record* curr;
    struct record* prev;
    struct record* temp;
    int returnval;

    temp = NULL;
    curr = NULL;
    curr = *start;
    prev = NULL;
    returnval = -1;

    if (debug == 1)
    {
        printf("addRecord has been called\n");
        printf("This is a debug mode\n");
        printf("You have passed account number: %d, \n", accountnum);
        printf("name: %s, and address: %s \n",  uname, uaddress);
    }
    else
    {
        printf("addRecord has been called\n");
    }

    if (curr == NULL)
    {
        temp = (struct record*)malloc(sizeof(struct record));
        curr = temp;
        (curr->accountno) = accountnum;
        strcpy_s(curr->name, 25, uname);
        strcpy_s(curr->address, 80, uaddress);
        curr->next = NULL;
        returnval = 0;
    }
    else if (curr != NULL)
    {
        while ((curr->next) != NULL)
        {
            prev = curr;
            curr = curr->next;
            prev-> next = curr;
        }
        if ((curr->next) == NULL)
        {
            prev = curr;
            temp = (struct record*)malloc(sizeof(struct record));
            curr = temp; 
            (curr->accountno) = accountnum;
            strcpy_s(curr->name, 25, uname);
            strcpy_s(curr->address, 80, uaddress);
            prev->next = curr;
            curr->next = NULL;
            returnval = 0;
        } 
    }
    free(curr);
    free(temp);
    free(prev);
    return returnval;
}*/
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
//  //  //  //
//  //  //  //  DESCRIPTION:   prints a record
//  //  //  //
//  //  //  //  Parameters:    start (struct record *): points to beggining of linked list
//  //  //  //                 accountnum (int): users account number
//  //  //  //
//  //  //  //  Return values:  0 : success
//  //  //  //
//  //  //  ****************************************************************/
/*
int printRecord (struct record* start, int accountnum)
{
    int returnval;
    struct record* curr;
    returnval = -1;
    curr = start;

    if (debug == 1)
    {
        printf("printRecord has been called. \n");
        printf("This is a debug mode\n");
        printf("You have passed  struct record pointer start, and the account number: %d \n", accountnum);
    }
    if (debug != 1)
    {
        printf("printRecord has been called. \n");
    }
    
    if (curr == NULL)
    {
        printf("There is no record in the list\n");
        returnval = -1;
    }
    else 
    {
        while ((curr->next) != NULL)
        {
            if (accountnum == ((curr)->accountno))
            {
                printf("%d %s %s \n", curr->accountno, curr->name, curr->address);
                returnval = 0;
            } 
            else
            {
                curr = curr->next;
            }
        }
        if ((curr->next) == NULL)
        {
            if (accountnum == curr->accountno)
            {
                printf("%d %s %s \n", curr->accountno, curr->name, curr->address);
                returnval = 0;
            }
            else
            {
                printf("There is no record with the given account number: %d\n", accountnum);
                returnval = -1;
            }
        }
    }
    return returnval;
}*/
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
//  Function name: printAllRecord
//  //  //  //
//  //  //  //  DESCRIPTION:   prints all the records
//  //  //  //
//  //  //  //  Parameters:    start (struct record **): points to beggining of linked list
//  //  //  //                 
//  //  //  //  Return values:  0 : success
//  //  //  //
//  //  //  ****************************************************************/

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
/*
int modifyRecord (struct record* start, int accountnum, char uaddress[ ])
{
    struct record* curr;
    int returnval;

    curr = start;
    returnval = -1;

    if (debug == 1)
    {
        printf("modifyRecord has been called. \n");
        printf("This is a debug mode\n");
        printf("You have passed the struct record pointer, account number: %d, and address: %s \n", accountnum, uaddress);
    }
    else if (debug != 1)
    {
        printf("ModifyRecord has been called.  \n");
    }

    if (curr == NULL)
    {
        printf("There are no records\n");
        returnval = -1;
    }
    else
    {
        while (curr->next != NULL)
        {
            if (accountnum == ((curr)->accountno))
            {
                if (curr->next != NULL)
                {
                    strcpy_s(curr->address, 80, uaddress);
                    curr = curr->next;
                    returnval = 0;
                }
                else
                {
                    printf("error");
                }
            }
            if (accountnum != (curr->accountno))
            {
                if (accountnum == curr->accountno)
                {
                    strcpy_s(curr->address, 80, uaddress);
                    curr = curr->next;
                    returnval = 0;
                }
                else
                    if (accountnum != curr->accountno)
                    {
                        curr = curr->next;
                    }
            }
        }
        if (curr->next == NULL)
        {
            if (accountnum == curr->accountno)
            {
                strcpy_s(curr->address, 80, uaddress);
                curr = NULL;
                returnval = 0;
            }
            else
            {
                if (accountnum == curr->accountno)
                {
                    strcpy_s(curr->address, 80, uaddress);
                    curr = NULL;
                }
                else
                    if (accountnum != curr->accountno)
                    {
                        curr = NULL;
                    }
            }
        }
        if (curr != NULL && curr == NULL && returnval == -1)
        {
            printf("There is no record with the account number %d\n", accountnum);
            returnval = -1;
        }
    }

    
    return returnval;
}*/
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
//  //  //  //
//  //  //  //  DESCRIPTION:   deletes a record
//  //  //  //
//  //  //  //  Parameters:    start (struct record **): points to beggining of linked list
//  //  //  //                 accountnum (int): users account cumber
//  //  //  //                 
//  //  //  //  Return values:  0 : success
//  //  //  //
//  //  //  ****************************************************************/
/*
int deleteRecord(struct record **start, int accountnum)
{
    struct record *curr;
    struct record* prev;
    struct record *tempstart;
    int returnval;
    returnval = -1;
    curr = *start;                                                                              //set curr to the first record in the list
    tempstart = *start;                                                                         //set tempstart to the first record in the list
    prev = NULL;

    if (debug == 1)
    {
        printf("deleteRecord has been called. \n");
        printf("This is a debug mode\n");
        printf("You have passed the struct record pointer, and account number: %d \n", accountnum);
    }
    if (debug != 1)
    {
        printf("deleteRecord has been called. \n");
    }
    
    if (curr == NULL)                                                                         //if there is no record
    {
        printf("There are no records\n");
        returnval = -1;
    }
    else
    {
        while (curr->next != NULL)                                                                  //while next of curr is not NULL
        {
            if (curr == *start)                                                                      //if curr is pointing the the first record in the list
            {
                if (accountnum == (tempstart->accountno))                                           //if account number of the RTD and the tempstart is the same
                {
                    if (tempstart->next != NULL)                                                    //if next of tempstart is not NULL 
                    {
                        *start = tempstart->next;                                                   //set next of tempstart to be the first record of the list 
                        curr = curr->next;                                                          //set next of curr to be curr
                        returnval = 0;
                    }
                }
            }
            if (accountnum != (tempstart->accountno))                                              //if account number to be deleted is NOT the same as the account number of tempstart
            {
                if (curr == *start)                                                                 //if curr is pointing at the first record in the link
                {
                    prev = *start;                                                                  //set prev to the first record in the list
                    curr = curr->next;                                                              //set curr to the next of curr
                    returnval = 0;
                }
                else
                    if (accountnum == curr->accountno)                                                  //if account number to be deleted is the same as the account number of curr
                    {
                        curr = curr->next;                                                              //set curr to the next of curr 
                        prev->next = curr;                                                              //set next of prev to curr
                    }
                    else
                        if (accountnum != curr->accountno)                                                  //if account number to be deleted is NOT the same as the account number of curr
                        {
                            curr = curr->next;                                                              //set the next of curr to curr
                            prev = prev->next;                                                              //set thhe next of prev to prev
                        }
            }
        }
        if (curr->next == NULL)                                                                     //if the next of curr is NULL
        {
            if (curr == *start && accountnum == (tempstart->accountno))                             //if curr is pointing at the first record in the list AND account number to be deleted is the same as the account number of tempstart
            {
                free(curr);
                returnval = 0;
            }
            else
            {
                if (accountnum == curr->accountno)                                                  //if the account number to be deleted is the same as the account number of curr
                {
                    prev->next = NULL;                                                              //set the next of prev is NULL
                    curr = NULL;                                                                    //set curr to NULL
                    returnval = 0;
                }
                else
                    if (accountnum != curr->accountno)                                                  //if the account number to be deleted is NOT the same as the account number of curr
                    {
                        curr = NULL;                                                                    //set curr to NULL
                    }
            }
        }
        if (*start != NULL && curr == NULL && returnval == -1)                                      //if starting record pointer is not NULL AND curr is NULL AND returnval is -1
        {
            printf("There is no record with the account number %d\n", accountnum);
            returnval = -1;
        }
    }

    
    return returnval;
}*/

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
//  //
//  //  DESCRIPTION:   reads a file and puts it in an array
//  //
//  //  Parameters:    start (struct record **): points to beggining of linked list
//  //                 file(char[]): name of the file
//  //                 
//  //  Return values:  0 : success
//  //
//  ****************************************************************/
/*
int readfile(struct record** start, char filename[])
{
    FILE* inputfile;
    int accountno;
    char name[25];
    char address[80];
    int i = 0;
    char bin[30];
    int returnval = -1;
    char temp;
    int error;

    error = 1;

    if (debug == 1)
    {
        printf("This is the readfile function.\n");
        printf("This is a debug mode\n");
        printf("You have passed the struct record pointer, and the file name: %s \n", filename);
    }
    error = fopen_s(&inputfile, filename, "r");
    if(inputfile == NULL) 
    {
        returnval = -1;
    }
    else 
    {
        while (fscanf_s(inputfile, "%d", &accountno) == 1) 
        {
            i = 0;
            fgets(bin, 1, inputfile);
            fgets(name, 25, inputfile);
            name[strlen(name)-1] = '\0';

            while ((temp = getc(inputfile)) != '+')
            {
                address[i] = temp;
                i = i + 1;
            }
            address[i] = '\0';
            temp = getc(inputfile);
            addRecord(start, accountno, name, address);
                //memset(address, '\0', 80);
        }
        fclose(inputfile);
    }
    return returnval;
}*/
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
int readfile(struct record** start, char file[])
{
    FILE* fp;
    char line[150];
    int accountnum;
    char name[25];
    char address[80];
    int lineNum = 0;

    // Open the file for reading
    errno_t err = fopen_s(&fp, file, "r");
    if (err != 0) {
        printf("File opening error occurred\n");
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

/*int readfile(struct record** start, char file[])
{
    FILE* fp;
    char line[150];
    int accountnum;
    char name[25];
    char address[80];

    if (debug == 1)
    {
        printf("This is the readfile function.\n");
        printf("This is a debug mode\n");
        printf("You have passed the struct record pointer, and the file name: %s \n", file);
    }

    //fp = fopen(file, "r");
    errno_t err = fopen_s(&fp, file, "r");
    if (err != 0) {
        // Handle file opening error
        printf("file opening error occured");
        return -1;
    }
    if (fp == NULL) {
        printf("Failed to open the file: %s\n", file);
        return -1;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        // Read the account number, name, and address from each line
        //if (sscanf_s(line, "%d %[^\n]%*c %[^\n]", &accountnum, name, address) != 3) {
        if (sscanf_s(line, "%d %[^\n]%*c %[^\n]", &accountnum, name, (unsigned)_countof(name), address, (unsigned)_countof(address)) != 3)
        {
            printf("Error parsing line: %s\n", line);
            fclose(fp);
            return -1;
        }

        // Add the record to the linked list
        addRecord(start, accountnum, name, address);
    }

    fclose(fp);
    printf("File %s has been read successfully.\n", file);
    return 0;
}*/



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

/*
int writefile(struct record* start, char filename[])
{
    FILE *outputfile;
    int returnval;
    struct record *p = start;
    int error;

    returnval = -1;
    error = 1;

    if (debug == 1)
    {
        printf("This is the readfile function.\n");
        printf("This is a debug mode\n");
        printf("You have passed the struct record pointer, and the file name: %s \n", filename);
    }
        
    error = fopen_s(&outputfile, filename,"w");
    if (outputfile == NULL)
    {
    returnval = -1;;
    }
    else
    {
        while (p != NULL)
        {
            fprintf(outputfile, "%d\n", p->accountno);
            fprintf(outputfile, "%s\n", p->name);
            fprintf(outputfile, "%s+\n", p->address);
            p = p->next;
        }
        fclose(outputfile);
    }
    return returnval;
}*/
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
int writefile(struct record* start, char file[])
{
    FILE* fp;
    struct record* current = start;

    // Open the file for writing
    errno_t err = fopen_s(&fp, file, "w");
    if (err != 0) {
        printf("File opening error occurred\n");
        return -1;
    }
    if (fp == NULL) {
        printf("Failed to open the file: %s\n", file);
        return -1;
    }

    // Write each record to the file
    while (current != NULL) {
        fprintf(fp, "%d\n%s\n%s\n", current->accountno, current->name, current->address);
        current = current->next;
    }

    fclose(fp);
    printf("Records have been written to the file: %s\n", file);
    return 0;
}

/*
int writefile(struct record* start, char file[])
{
    FILE* fp;
    struct record* current = start;

    if (debug == 1)
    {
        printf("This is the readfile function.\n");
        printf("This is a debug mode\n");
        printf("You have passed the struct record pointer, and the file name: %s \n", file);
    }

    //fp = fopen(file, "w");
    errno_t err = fopen_s(&fp, file, "w");
    if (err != 0) {
        // Handle file opening error
        printf("file opening error occured");
        return -1;
    }

    if (fp == NULL) {
        printf("Failed to open the file: %s\n", file);
        return -1;
    }

    while (current != NULL) {
        fprintf(fp, "%d %s %s\n", current->accountno, current->name, current->address);
        current = current->next;
    }

    fclose(fp);
    printf("Records have been written to the file: %s\n", file);
    return 0;
}
*/


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





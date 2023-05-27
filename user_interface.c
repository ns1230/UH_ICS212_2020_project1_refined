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
//  FILE:        user_interface.c
//  
//  DESCRIPTION:
//  user_interface.c is a source file that serves as the user interface for interacting with the database. 
//  It contains the main function and supporting functions for displaying a menu, getting user input, and executing the requested operations on the database. 
//  The file handles user inputs, such as adding a new record, printing information about a record, modifying a record, deleting a record, and quitting the program. 
//  It also includes functions for reading records from a file at the beginning and writing records to a file before exiting. 
//  
/****************************************************************/


#include<stdio.h>
#include<string.h>
#ifndef  _RECORD_H_
#define _RECORD_H_
#include "record.h"
#endif

#ifndef  _DATABASE_H_
#define _DATABASE_H_
#include "database.h"
#endif

int debug;
//int setting doesn't need to be here instaed of main??


/*****************************************************************
//
//  Function name: printmenu
//  //  //  //
//  //  //  //  DESCRIPTION:   prints out all the menu options
//  //  //  //
//  //  //  ****************************************************************/

void printmenu()
{
    printf("\nPick and type one digit from options 1-6 below: \n");
    printf("1: Add a new record in the database \n");
    printf("2: Print information about a record using the account # as a key \n");
    printf("3: Print all records in the database \n");
    printf("4: Modify the address field of a record specified by account number \n");
    printf("5: Delete an existing record from the database using the account # as a key \n");
    printf("6: Quit the program \n\n");
    printf("Your answer: \n");
}


/*****************************************************************
//
//  Function name: getaddress
//  
//  DESCRIPTION:   gets address.
//                 allows user to enter multiple lines of address
//
//  Parameters:    address (char[]): char array for address to be put in
//                 ad (int): size of the address array
//
//****************************************************************/

void getaddress (char address [ ], int ad)
{
    char x;
    int i = 0;
    int y = 0;

    while((x = getchar()) != '+' && (y == 0))
    {
        address[i] = x;
        i++;
        if (i > (ad -1))
        {
            printf("Address is too long...\n");
            i = 0;
            y = 0;                                                  
        }
    }
    address[i] = '\0';
}


/*****************************************************************
//
//  Function name: main function
//
//  DESCRIPTION:   main function. Asks the user what they would like to do,
//                 and then does what they're told.
//
//  Parameters:    argc (int): argument count
//                 argv (char*[]): argument vector
//
//  Return values:  0 : success
//
//  ****************************************************************/

int main(int argc, char* argv[])
{
    struct record* start;
    int answer;
    int setting;

    int accountnum;
    char name[100];
    char address[100];
    start = NULL;
    debug = 0;
    setting = 1;    

    // Call readfile function to load records from the file
    readfile(&start, "project1file.txt");

    if (argc == 2)
    {
        if (strcmp(argv[1], "debug") == 0)
        {
            debug = 1;
        }
        else
        {
            printf("debug: error. If you are trying to use debug,");
            printf(" the second word has to be debug.\n\n");
            setting = 0;
        }
    }
    else if (argc == 1)
    {
        debug = 0;
    }
    else
    {
        printf("debug: error.");
        printf("If you want to use the debug mode, the second word has to be 'debug', "); 
        printf("and nothing should be typed after that\n\n");
        setting = 0;
    }

     
    while (setting == 1)
    {
        printf("\nWelcome. \n");
        printmenu();
        scanf_s("%d", &answer);
        printf("\n");

        if (answer == 1)
        {
            printf("\n");
            printf("What's your account number?\n");
            scanf_s("%d", &accountnum);
            printf("What's your name? \n");
            scanf_s("%s", name, 25);
            printf("What's your mailing address? \n");
            printf("Once done typing, type + \n");
            getaddress(address, 200);
            if (address[0] != '\0')
            {
                printf("%d %s %s \n", accountnum, name, address);
                addRecord(&start, accountnum, name, address);
                printf("The following record has been added\n");
                printf("%d %s %s \n", accountnum, name, address);
            }
            else 
            {
                printf("Address is too long. Try again\n\n");
            }
        }
                
        if (answer ==2)
        {
            printf("\n");
            printf("What's your account number?\n");
            scanf_s("%d", &accountnum);
            printRecord(start, accountnum);
        }
        
        if (answer == 3)
        {
            printf("\n");
            printAllRecords(start);
        }

        if (answer == 4)
        {
            printf("\n");
            printf("What's your account number?\n");
            scanf_s("%d", &accountnum);
            printf("What's your mailing address? \n");
            printf("Once done typing, type + \n");
            getaddress(address, 200);
            if (address[0] != '\0')
            {
                modifyRecord(start, accountnum, address);
            }
            else 
            {
                printf("Address is too long. Try again\n");
            }
        }

        if (answer == 5)
        {
            printf("\n");
            printf("What's your account number?\n");
            scanf_s("%d", &accountnum);
            deleteRecord(&start, accountnum);
        }

        if (answer == 6)
        {
            printf("\n");
            printf("Bye. \n");
            setting = 0;
        }
        
        else if (answer < 1 || answer > 6)
        {
            printf("\n");
            printf("type a valid number from 1 - 6\n");
        }
    }
    writefile(start, "project1file.txt");
    cleanup(&start);
    return 0;
}





















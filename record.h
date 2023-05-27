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
//  //  //  FILE:        record.h
//  //  //
//  //  //  DESCRIPTION:
//  //  //   This file is the record file(header) for project1.
//  //  //   It contains basic informations needed for a record.
//  //  ****************************************************************/

struct record
{
    int                accountno;
    char               name[25];
    char               address[80];
    struct record*     next;            //"struct record* next" and "struct record *next" means the same in c. '*' denotes that it is a pointer
};



































# UH_ICS212_2020_project1_refined

# Simple Database Management System

This project is a simple command-line-based database management system implemented in C. It allows users to manage records consisting of account numbers, names, and addresses. The program provides various functionalities such as adding records, deleting records, searching records, printing individual records, and printing all records.

## Features

- **Add Record**: Users can add a new record to the database by providing an account number, name, and address.
- **Delete Record**: Users can delete a record from the database based on the account number.
- **Search Record**: Users can search for a record in the database based on the account number.
- **Print Individual Record**: Users can print the details of an individual record by providing the account number.
- **Print All Records**: Users can print the details of all records in the database.
- **File I/O**: The program supports reading records from a text file and writing records to a text file.
- **Debug Mode**: The program provides a debug mode that can be enabled to display additional debug information during runtime.

## Usage

1. Compile the program using a C compiler (e.g., GCC).
2. Run the executable file to start the database management system.
3. Follow the on-screen instructions to perform various operations on the database.

## File Structure

- `database.h`: Header file containing the structure definition and function prototypes for the database operations.
- `database.c`: Source file containing the implementations of the database operations.
- `user_interface.c`: Source file containing the user interface and main program logic.
- `record.h`: Header file containing the structure definition for the record.
- `record.c`: Source file containing helper functions for record-related operations.

## Dependencies

This program does not have any external dependencies and is implemented using standard C libraries.


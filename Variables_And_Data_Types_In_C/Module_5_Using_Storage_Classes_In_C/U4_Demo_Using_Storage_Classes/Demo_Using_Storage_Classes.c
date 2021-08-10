#include <stdlib.h> // For printf etc.
#include <stdio.h>
#include <string.h>
#include "employees.c" // Make sure we pull in the file containing our functions!

const static char companyName[100] = "Jake's Jumpers";

//  We could put extern declerations of the functions we're expecting from the
//  source file... But as mentioned, extern is the default function storage 
//  class. We don't need to when using functions from another file!
// 
//  However, if we want to use global variables from another file, we need
//  to explicitly define those as "extern"!
//
//  extern void readEmployees(int nEmployees);
//  extern void printEmployees(int nEmployees);


/* 
    Let's put all we've learned about storage classes into practice using our
    previous Employee data importer example. 
*/
int main (void)
{
    static int nEmployees;

    printf("Welcome to the %s Employee System", companyName);
    printf("Please provide the number of employees you wish to import: ");

    scanf("%d", &nEmployees);

    readEmployees(nEmployees);
    printEmployees(nEmployees);

    /* 
        Where are our functions!? 

        In this exercise, we'll define them in a seperate file which we'll import. 

        We'll need to make sure we're using extern though so we tell the compiler
        to wait for the functions to be found in the other file! 
    */
    return 0;
}
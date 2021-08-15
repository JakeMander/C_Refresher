#include <stdlib.h>
#include <stdio.h>   //  For printf
#include <time.h>    //  For date/time handling.
#include <locale.h>  //  For locale.
#include <stdint.h>  //  For bit fields.
#include <stdbool.h> //  For boolean types.
#include <string.h>  //  For strcpy etc.
#include <inttypes.h> // For PRI macros - Portable casting from FW int's to int.

/*
   In this demo, we'll build our first fully fledged C application!

   We're going to build an employee registration system that uses some
   of the basic and derived types we've covered to record and track
   employees within a business!

   In this example, we'll cover:
    -   Using the basic and derived data types.
    -   Applying type casting and type qualifiers.
    -   Using time's and dates.
    -   Applying localisation to the app.
*/

//  Struct to represent employee in the system. Tracks
//  a number of properties that represent an employee
//  in the system.
struct employee
{

    //  Use an integer type of fixed width 8 bits. This gurantee's
    //  that the property will be 8 bits long regardless of architecture.
    //  Probably not a good idea to use 8-bits (0-255) for an ID in real life,
    //  but we'll use this as an example!
    uint8_t employeeNumber;
    char name[200];
    float salary;

    /*  
        Bit field sets max number of bits used for this property field to be 7.
        Why? We want our maximum age to be reasonable! 
    
        The oldest person ever alive lived to 122! 2^7 = 128 (so 127 when we account for 0). 
        By setting age to 7 bits we limit the max value to 127 (we'll get overflow is we go above).
        But what happens to the remaining bit left over (remember, we work in bytes regardless
        of how many of those bits we actually use). Well that depends on what we do for the next
        declated variable.

        If the next variable uses a bit field as well, the remaining bit will end up being used
        as storage for the next variable that get's declared. 
        
        So our next variable will end up referencing two bytes (the byte used to build age 
        that has the 1 bit left over), and the bytes used to construct the next variable type.

        If the next variable doesn't use bit fields, then the remaining bit is padded (unused).
        It's pretty much wasted! Bear this in mind when using bit fields. If used correctly, you
        can cut down on memory usage by sharing bytes between variables!
    */
    int age : 7;
    struct tm dateOfBirth; // Use the time struct to track D.O.B as a calendar value.
};

//  Keep the company name constant! We don't plan on a rebrand mid program execution!
//  This value is global in scope so can be accessed anywhere!
const char companyName[100] = "Jake's Jumper's"; // We'll sell cosy wooly jumpers!

//  Let's define prototypes for some of the methods we'll use to add employees to our
//  in memory log, and read employee data.

void writeEmployees(struct employee *employees, int nEmployees);
void printEmployees(struct employee employees[100], int nEmployees);

int main(void)
{
    struct employee employeeLog[100];   // Array to track employees. Max size: 100 emp's
    int nEmployees; // Number of employees to create/print. Defined by user.

    printf("Welcome to the Employee System of %s \n\n", companyName);
    printf("Please provide the number of employees you want to import: ");

    scanf("%d", &nEmployees);
    printf("\n");

    writeEmployees(employeeLog, nEmployees);
    printEmployees(employeeLog, nEmployees);
    return 0;
}

/*
    #   Description
            Function to generate a user defined number of employees and 
            store them in a targetted array.

    #   Parameters
            employees (struct employee *) - A pointer to either an array
            of employee structures that the newly generated employees will
            be added to.

            nEmployees (int) - An integer value representing the number of
            employees to add to the targetted array.
*/
void writeEmployees(struct employee *employees, int nEmployees)
{
    //  Keep iterating over an employee creation process until
    //  we've added the number of employees specified by nEmployees.
    for (int i = 0; i < nEmployees; i++)
    {
        printf("\nProcessing Employee %d \n", i + 1); // i is 0 indexed. Increment by 1 to correct.
        printf("Please provide the employee name, number, salary and DOB (dd/mm/yyyy):\n");

        /*
            Define temporary variables to hold the scanned employee name and
            D.O.B values ready struct creation. Unlike the employee numbers 
            and salary values which are integers and thus direclty assignable
            to each struct in the array, we need to do a strcpy of the string
            over to the struct property (Remember, strings are not directly 
            assignable in C), and we need to first create a time struct to 
            hold each D.O.B part and then assign a copy of the struct to an
            indexed struct in the array. 
        */
        char empName[200];
        int dayOfBirth;
        int monthOfBirth;
        int yearOfBirth;

        scanf("%s %" PRId8 "%f %d/%d/%d", empName, &employees[i].employeeNumber,
              &employees[i].salary, &dayOfBirth, &monthOfBirth, &yearOfBirth);

        //  Copy over our user input over to the indexed employee in the array.
        strcpy(employees[i].name, empName);

        printf("\nMonth of Birth: %d\n ", monthOfBirth);

        //  Create a new time struct to hold the user's D.O.B input so that it
        //  can be assigned over to the indexed employee struct in the array.
        struct tm tempDOB;
        tempDOB.tm_mday = dayOfBirth;
        //  - 1 because tm_mon January starts from 0. December is 11!
        tempDOB.tm_mon = monthOfBirth - 1;
        //  Remember, year is stored relative to 1900 (i.e. the year date is
        //  represented by how many years after 1900 the supplied date is.
        //  We need to correct for this by subtracting  1900 from our input!
        tempDOB.tm_year = yearOfBirth - 1900;

        //  We now need to work out the users age based on the current time.
        //  To do this, store the current time in seconds, then convert this
        //  to a tm sruct. Once we've got this, we can subtract the year they
        //  were born from the current year (Don't need to account for 1900
        //  in this one. Both dates are relative so the age calculation checks out).
        time_t currentTimeInSecs;
        time(&currentTimeInSecs);
        struct tm *currentDateTime = localtime(&currentTimeInSecs);

        employees[i].age = currentDateTime->tm_year - tempDOB.tm_year;

        //  ...What if the employee hasn't had their birthday this year yet?
        //  The calculation will still work out their age value as if they
        //  have! We need to correct for the system time not yet being past
        //  the users actual birthday by subtracting 1 from age if the system
        //  time is less than the user's birthday.
        if (currentDateTime->tm_mon < currentDateTime->tm_mon ||
            (currentDateTime->tm_mon == tempDOB.tm_mon && currentDateTime->tm_mday < 
             tempDOB.tm_mday))
        {
            employees[i].age--;
        }
        employees[i].dateOfBirth = tempDOB;
    }
}

void printEmployees(struct employee *employees, int nEmployees)
{
    printf("\n");
    setlocale(LC_ALL, "");
    struct lconv *currentLocale = localeconv();

    printf("Printing Employees\n");

    for (int i = 0; i < nEmployees; i++)
    {
        struct employee currentEmployee = employees[i];
        char dateOfBirthString[30];
        
        //  Format the employees D.O.B ready for printing.
        int successfulChars = strftime(dateOfBirthString, sizeof(dateOfBirthString), 
        "%x", &currentEmployee.dateOfBirth);

        printf("Employee %d\n", i + 1);
        printf("Name: %s\n", currentEmployee.name);
        printf("Employee Number: %d\n", currentEmployee.employeeNumber);
        printf("Salary: %.2f %s\n", currentEmployee.salary, currentLocale -> int_curr_symbol);
        printf("Date of Birth: %s\n", dateOfBirthString);
        printf("Age: %d\n", currentEmployee.age);
    }
}
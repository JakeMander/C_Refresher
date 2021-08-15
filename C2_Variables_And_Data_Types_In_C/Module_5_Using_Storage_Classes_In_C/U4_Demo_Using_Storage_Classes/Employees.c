#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <inttypes.h>

//  Let's type define our struct so that for our custom type,
//  we can create a struct variable by calling the "employee"
//  alias.
typedef struct 
{
    uint8_t employeeNo;
    char name[200];
    float salary;
    int age :7;
    struct tm dob;
} employee;

//  Global array to track the employees in the company.
employee employeesArray[100];

void readEmployees(int nEmployees)
{
    //  Iterator for the array. Initalise it to point at the first
    //  element of our employees array.
    employee * employees = employeesArray;

    for (int i = 0; i < nEmployees; i++)
    {
        printf("Processing Employee: %d\n", i + 1);
        printf("Please provide the employee name, number, salary and DOB (dd/mm/yyyy): ");

        char empName[200];
        int dayDob;
        int monthDob;
        int yearDob;

        scanf("%s %" PRId8 "%f %d/%d/%d", empName, &employees[i].employeeNo, &employees[i].salary,
        &dayDob, &monthDob, &yearDob);

        strcpy(employees[i].name, empName);

        struct tm dateOfBirth;

        dateOfBirth.tm_mday = dayDob;
        dateOfBirth.tm_mon = monthDob - 1;
        dateOfBirth.tm_year = yearDob - 1900; // Remember, years in the C time library are relative to 1900!

        time_t currentTimeInSeconds;
        time(&currentTimeInSeconds);
        struct tm * currTime = localtime(&currentTimeInSeconds); // Parse from unix time in secs to calendar time.

        employees[i].age = currTime -> tm_year - dateOfBirth.tm_year;

        //  We need to check if we've had our birthday this year.  If we have, keep the value!
        //  Otherwise decrement the value by one!
        if (currTime -> tm_mon < dateOfBirth.tm_mon || 
            currTime -> tm_mon == dateOfBirth.tm_mon && 
            currTime -> tm_mday < dateOfBirth.tm_mday)
            {
                employees[i].age--;
            }
        employees[i].dob = dateOfBirth;
    }
}

void printEmployees(int nEmployees)
{
    setlocale(LC_ALL, "");
    struct lconv *currentLocale = localeconv();

    printf("Printing Employees\n");

    for (int i = 0; i < nEmployees; i++)
    {
        employee currentEmployee = employeesArray[i];
        char dateOfBirthString[30];
        
        //  Format the employees D.O.B ready for printing.
        int successfulChars = strftime(dateOfBirthString, sizeof(dateOfBirthString), 
        "%x", &currentEmployee.dob);

        printf("Employee %d\n", i + 1);
        printf("Name: %s\n", currentEmployee.name);
        printf("Employee Number: %d\n", currentEmployee.employeeNo);
        printf("Salary: %.2f %s\n", currentEmployee.salary, currentLocale -> int_curr_symbol);
        printf("Date of Birth: %s\n", dateOfBirthString);
        printf("Age: %d\n", currentEmployee.age);
    }
}
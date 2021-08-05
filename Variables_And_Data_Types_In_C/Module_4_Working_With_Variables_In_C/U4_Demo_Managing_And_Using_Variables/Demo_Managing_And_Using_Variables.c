#include <stdio.h> //  For printf
#include <locale.h> // For locale

/*
    In this demo, we'll explore defining variables with different
    scopes, read and write values to variables, and create conditions
    and expressions using relational and logical operators.


    In this demo, we'll create an app that takes in an incoming salary,
    calculates the tax to pay and outputs the net salary from this.
*/

//  Function prototypes. Let's bundle the functionality of tax and net 
//  salary calculation into a single function for code reusability. 
float CalculateTaxBand(float salary);
float CalculateTax(float salary, float applicableTax);
float CalculateNetSalary(float salary, float taxableIncome);

//  Here we have the tax bands. These will be the checks
//  which determine the tax and net salary. In this instance, we'll store
//  these as global variables. These can be accessed anywhere from within the
//  app. We'll define these variables as constant. We shouldn't change these
//  during runtime!
float const minimumBasicRateBand = 0;
float const maximumBasicRateband = 12000;
float const basicRate = 0.10f; // 10% tax - Lower income rate.

float const minimumHigherRateBand = 12000;
float const maximumHigherRateBand = 50000;
float const higherRate = 0.20f; // 20% tax - Mid tier income rate.

float const minimumMaxRateBand = 50000;
float const maximumMaxRateBand = 100000;
float const maxRate = 0.40f;

int main(void)
{
    //  These variables will exist in local scope. We'll use these to handle
    //  the user input, tax and net salary calculation.
    float userSalary;
    float taxRateApplied;
    float netSalary;
    float totalTaxesPaid;

    //  Set the locale for currency.
    setlocale(LC_ALL, "");
    struct lconv *currentLocale = localeconv();

    //  Take in the user's salary which we'll use to identify their tax band.
    printf("Please Provide Your Salary: ");;
    scanf("%f", &userSalary);

    if (userSalary < 0)
    {
        printf("\nInput Was Invalid.\n");
        return -1;
    }

    taxRateApplied = CalculateTaxBand(userSalary);
    printf("\nApplied Tax Rate Is: %.2f%%\n", taxRateApplied * 100);

    totalTaxesPaid = CalculateTax(userSalary, taxRateApplied);
    printf("\nTaxable Income Is: %s%.2f\n", currentLocale -> currency_symbol, totalTaxesPaid);

    netSalary = CalculateNetSalary(userSalary, totalTaxesPaid);
    printf("\nNet Salary Is: %s%.2f\n", currentLocale -> currency_symbol, netSalary);

    return 0;
}

float CalculateTaxBand(float salary)
{
    if (salary < maximumBasicRateband) 
        return basicRate;

    else if (salary < maximumHigherRateBand)
        return higherRate;

    else
        return maxRate;
}


float CalculateTax(float salary, float applicableTax)
{
    return salary * applicableTax;
}

float CalculateNetSalary(float salary, float taxableIncome)
{
    return salary - taxableIncome;
}


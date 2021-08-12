#include <stdio.h>
#include <stdbool.h>

/*
    In this demo, we'll recap our operators learning by building a simple 
    program that modifies employee salary with a bonus/pay increase 
    following a particularly good year of sales.

    If an employee earns less than £30,000, then they are entitled to a
    1.15% pay increase!
*/

float arithmeticOperation(float val1, float val2, char operator);

int main(void)
{
    //  Zero size array. Determined at runtime. We'll do this to calculate
    //  the exact size of our array at runtime. 
    float salaries[] =  { 10000.00f, 20000.00f, 30000.00f, 40000.00f, 
                          50000.00f, 60000.00f, 70000.00f, 80000.00f, 
                          90000.00f, 100000.00f
                        };

    //  To find the total number of employees at runtime, divide the total
    //  size of the array by the typed size of one element.
    int numberOfEmployees = sizeof(salaries) / sizeof(salaries[0]);

    int bonus = 1000;
    float salaryIncrease = 1.15f;

    for (int i = 0; i < numberOfEmployees; i++)
    {
        float salary = salaries[i];
        
        printf("EMPLOYEE %d\n", i);
        printf("SALARY %.2f\n", salary);

        float salaryWithBonus= arithmeticOperation(salary, bonus, '+');
        printf("Employee Salary W/ Bonus: %.2f\n", salaryWithBonus);

        if (salary < 30000.00f)
            printf("Employee %d Is Entitled To A Salary Increase!\n", i);

        //  Ternary conditional to apply salary if salary less than 30000, otherwise
        //  return the salary with just the bonus.
        float finalSalary = (salaryWithBonus < 30000) ? 
                            arithmeticOperation(salaryWithBonus, salaryIncrease, '*') :
                            salaryWithBonus;
        ;
        printf("Final Employee Salary: %.2f\n", finalSalary);
        printf("***************************************\n");
    }

    return 0;
}

float arithmeticOperation(float val1, float val2, char operator)
{
    float result = 0;

        switch(operator)
        {
            case '+':
                result = val1 + val2;
                break;
            
            case '-':
                result = val1 - val2;
                break;

            case '*':
                result = val1 * val2;
                break;
            
            case '/':
                result = val1 / val2;
                break;

            case '%':
                result = (int) val1 % (int) val2;
                break;

            default:
                printf("Invalid Operator\n");
                result = -1;
                break;
        }
    return result;
        
}
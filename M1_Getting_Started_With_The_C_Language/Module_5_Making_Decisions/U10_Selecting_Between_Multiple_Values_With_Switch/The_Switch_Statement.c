/* The switch statement can be used to compare 
an integer value against a finite set of values. For example, 
you might have defined a set of options by a series of numbers
and you want to perform an operation based on the user input. 

The same behaviour can be achieved using if-else ladders, but C
offers the switch statement which allows such comparisons to be
expressed more clearly. 

The switch looks something like this:

switch(n):
  case value1: 
    // Statements for case 1
    break;
  
  case value2:
    // Statements for case 2
    break
  
  default:
    // Statements to execute if none of the above
    // cases are satisfied.
    break;
  
  The switch is very similar to an if-else ladder, but works
  using cases. Each case has an attatched value which the 
  argument of the switch keyword is compared against.

  This switch keyword can only take in a value that is an
  integral type (i.e. int, char etc...). It CANNOT be a
  floating point number or a whole string, and it CANNOT
  be used to evaluate logical or comparative expressions.

  So this is not allowed:

  char userInput[20]
  scanf("%.19s")
  switch(user) 
  {
    case "Tim":
      printf("Hi Tim");
      ...
    ...
  }

  And neither is this:

  int value = 22
  switch (value > 20 && value < 30)
  {
    ...
  }

  If you want that kind of behaviour, use an If-else
  ladder!

  If the argument matches the case value, then the statements
  that follow the ":" are executed, and then we hit the "break"
  keyword that allows us to break out of the switch! Using this
  keyword is optional, but often VERY important! 
  
  If we don't use break in our switch statement cases, then
  every case will trigger, executing it's embedded statements
  until either a break is eventually hit, or the switch finishes
  causing what is known as a "fall through".

  If we make it to the end of the switch and no case has been hit,
  then our "default" case will fire and it's enclosed statements
  will run. This acts very similar to an "else" statement in
  an if-else ladder.
*/

#include <stdio.h>  /* For console IO */
#include <windows.h> /* Get The BEEP! */
int main(void) 
{
  Beep(1200, 300);
  printf("Welcome to the BIOS boot up...\n");
  printf("*********************************\n");

  printf("Please Select From The Following Options:\n");
  printf("1. Enter BIOS Options\n");
  printf("2. Hardware Settings\n");
  printf("3. Delete All Files\n");

  printf("Please Enter A Value: ");
  int userSelection = 0;
  scanf("%d", &userSelection);
  printf("\n");

  switch (userSelection)
  {
    case 1:
      printf("Welcome To BIOS Options!\n");
      break;
    
    case 2:
      printf("Welcome To Hardware Settings!\n");
      break;

    case 3:
      Beep(100, 2000);
      printf("It Looks Like You're Trying To Delete Your Operating System!\n");
      printf("Would You Like Some Help With That!?\n");
      break;
    
    default:
      printf("Invalid Selection\n");
      break;
  }
}
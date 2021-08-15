/* In programming, scope refers to the current context that our code
is being executed in. In simple terms, that's how our code is running
(is it global or local? Is it being executed as part of a function, 
conditional statement or something like a for loop (covered later)?)

All of this determines what variables we have access to and 
how long their lifespan is in memory!

In C, we can initalise variables in both our main function and
conditional blocks such as if statements!

However, it's important to know we can only access variables from inside their
scope! Otherwise we get a compile error! For example:

int main(void) 
{
  if (condition)
  {
    int myVariable;
    //  Code after variable is inside the scope of the if condition.
    //  Can only be accessed here! Outside the if statement, the variable has
    //  gone 'out of scope' and is essentially at the end of its
    //  life!
  }
  //  Code after variable declaration inside main. Scope is
  //  now the "main" function! We cannot access "myVariable" from here!
  //  It is said to be "out of scope"!
}

If we declare a variable in our main function, the variable is said to
have "global" scope. That is, it lasts for the entire runtime of the
program and can be accessed from anywhere within our file. 

A variable declared inside the body of an if statement, a for loop
condition, or inside a function is said to have local scope. 
Refering to that variable inside it's associated curly braces 
will refer to the local variable 
*/

#include <stdio.h>  /* For console IO */

int main(void) 
{
  int globalVar = 55;

  if (1) // Always true for testing!
  {
    printf("Global Variable Value is: %d\n", globalVar);

    int localVar = 2;
    printf("Local Variable Value is: %d\n", localVar);
  }

  //  Uncomment the line below and you'll see this is not allowed! 
  //  localVar is out of scope and as such, can't be used anymore!
  //  printf("Whoops! Local Variable Has Gone Out Of Scope!", localVar);
}
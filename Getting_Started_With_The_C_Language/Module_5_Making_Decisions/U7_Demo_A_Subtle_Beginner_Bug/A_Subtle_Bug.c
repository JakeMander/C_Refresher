/* Can you notice the subtle bug in the below program? 
Run it and see what happens! Then check the answer below!
*/

#include <stdio.h>  /* For console IO */

int main(void) {
    int n = 12;

    if (n = 64)
    {
        printf("%d is equal to 64!", n);
    }
}




/* ANSWER:
The bug is that we have used the '=' assignment operator,
not the '==' equality operator in the if condition! 

But why is this running okay without any errors?

Because it's still a perfectly valid statement in C!

Essentially what happens is:
- 64 is assigned to the variable, n.
- The if statement then evaluates 64.
- 64 is a number that is NOT 0. In C, that evaluates to
  TRUE!
- As our if evaluates to true execute the code block!
- As n is now set to 64, print that!
*/
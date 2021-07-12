/*  
    In this example, we implement a nice simple swap function.

    Here, we want to be able to provide two variables from our main
    method then switch the values stored in each varaibles memory
    location over to the other! We'll print the values out to show
    a swap has occured.

    But wait... There's a bug in this code.

    Run the program and see what happens! What could be causing this?

    If we debug the function we'll see that:
    -   We pass in 10 (var x) and 20 (var y).
    -   10 (x) gets assigned to temp.
    -   20 (y) gets assigned to the variable that was holding 10,
        overwriting it's value.
    -   The 10 stored in temp (which we're keeping because we wrote over
        x's original value) is written to the variable that was holding 
        20, overwriting that value.

    A now holds 20 and B holds 10. The swap logic has worked!

    But if we keep stepping through the program, we'll see that x
    and y in our global scope have not changed! Why have the values
    not been carried over!?

    ...We'll look at this problem in more detail in the next tutorial!
*/

#include <stdio.h> // Gives us printf


//  The swap function! Take in two values, store one in a temporary variable, 
//  swap one value, and then assign the remaining value stored in the temp
//  to the other variable!
void Swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
int main(void) 
{
    int x = 10;
    int y = 20;

    printf("Inital Values: \n x = %d, y = %d \n\n", x, y);

    Swap(x, y);

    printf("Value After Swap: \n x = %d, y = %d \n\n", x, y);

    return 0;
}
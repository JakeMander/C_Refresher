/* The following program demonstrates how we can nest conditonal
logic to perform more finely tuned operations based on a number
of nested condtions. For example, if a vehicle is a car, we might
then want to check what make it is and perform an operation on that.
We could do this using nested if statements like so:

int main (void)
{
  char vehicle[] = "Car"
  char model[] = "Ford"
}
*/

#include <stdio.h>  /* For console IO */
#include <string.h> /* For strcmp */
int main(void) 
{
  char vehicle[20] = "Car";
  char model[20] = "Ford";

  if (strcmp(vehicle, "Car") == 0)
  {
    printf("Vehicle Is A Car!\n");
    //  IMPORTANT! Avoid going any deeper with your nesting! This is indicative
    //  of poor code design and makes code difficult to read! Always try
    //  to break your conditional logic into their own functions or 
    //  own if blocks. 
    if (strcmp(model, "Ferrari") == 0)
    {
      printf("You've got a Ferrari! Nice!\n");
    }

    else if (strcmp(model, "Peaguot") == 0)
    {
      printf("You've got a Peaguot! Nice!\n");
    }

    else if (strcmp(model, "Ford") == 0)
    {
      printf("You've got a Ford! Nice!\n");
    }

    else 
    {
      printf("Hmmmm. I Don't Recognise That Car!\n");
    }
  }

  else 
  {
    printf("Vehicle Is Not A Car!\n");
  }
}
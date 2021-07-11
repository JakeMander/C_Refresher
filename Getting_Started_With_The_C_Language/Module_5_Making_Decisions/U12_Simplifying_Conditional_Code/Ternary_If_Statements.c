/* We can make simple if-else statements more simply using
   syntax known as the "ternary" operator! This is represented 
   by a block of conditional logic followed by the following
   operators:

   '?' = Then - If the statement is true, then return the statement
   that follows.

   ':' = Else - If the preceeding statement was false, then return
   the statement that follows the colon.

   In essence, we can convert the following:

   if (number1 > number2)
   {
      maxNumber = number1
   }

   else
   {
     maxNumber = number2
   }

   Into:
   maxNumber = (number1 > number2) ? number1 : number2

   So what happens? 
   
   We compare number 1 and see if it's greater than number
   2. If that's true, then return the value following ? and assign it
   to "maxNumber" else return the value following the : and assign it
   to "maxNumber".
*/

#include <stdio.h>  /* For console IO */
#include <string.h> /* For strcpy */
int main(void) 
{
  int hour24HourClock = 22;
  char greeting[50];

  /* We can chain ternary's together! Here we use string copy
     (remember, we can't assign strings directly in C) to 
     select greeting as our detination for whatever string
     value we compute as part of our ternary statement!

     First we check to see if our clock value is less than 12.
     If it is, we return good morning as our value to copy to
     greeting, otherwise we need to check if it's afternoon or
     night!

     In the event the clock time is greater than 6, the else if
     fired, which then triggers another ternary! Here, we check
     if our clock is less than 6PM! If it is, we wish the user
     a good afternoon! Otherwise, our final else if fired which
     returns "Good evening" because that's our only remaining
     time of the day!

     You need to be careful with ternary operators though! 
     Whilst having shorthand if's makes writing code easy peasy,
     ternary conditions are a lot harder to make sense of than 
     traditional if-else laddders, particularly when you start
     nesting lots of ternary statements together!
    */

  strcpy(greeting, (hour24HourClock < 12) ?
  "Good Moning" : (hour24HourClock < 18) ? 
  "Good Afternoon" : "Good Evening"
  );
  printf("%s\n", greeting);
}
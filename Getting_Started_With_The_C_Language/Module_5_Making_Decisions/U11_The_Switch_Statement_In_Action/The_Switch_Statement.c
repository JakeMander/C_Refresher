// Let's have a look at another switch example!

#include <stdio.h>  /* For console IO */
int main(void) 
{
  printf("Please Enter An Integer Number:\n");
  int userSelection = 0;
  scanf("%d", &userSelection);
  printf("\n");

  switch (userSelection)
  {
    case 1:
      printf("You Entered 1!\n");
      break;
    
    case 2:
      printf("You Entered 2!\n");
      break;

    case 10:
      printf("You Entered 10!\n");
      break;
    
    case 64:
      printf("You Entered 64!\n");
      break;
    
    default:
      printf("You entered a number that wasn't 1, 2, 10 or 64\n");
      break;
  }
}
//  The following demonstrates how we can nest for loops 
//  together to sequence iterations together. In this example,
//  we use two for loops to print both rows and columns of a 
//  multiplication table. 

#include <stdio.h> // Gives us printf
#include <string.h> // Gives us strlen

int main(void) 
{
    char userInput[20];

    printf("%s", "Please Enter User Input To Underline: ");
    scanf("%19s", userInput);

    printf("%s", "\nOutputting!\n");

    //  Output the saved user input.
    printf("\n%s\n", userInput);

    // Store the length.
    int stringLength = strlen(userInput);

    //  Output the underline.
    for (int i = 0; i < stringLength; i++)
    {
        //  When we're dealing with single characters, putchar is a much
        //  more efficient approach to outputting it to the console than
        //  printf! It doesn't need to mess about with 
        putchar('-');
    }
    putchar('\n');

    //  Now Let's Print a Box! 
    
    //  We'll need to add 4 extra stars! 
    //  This is because we'll add one space of padding between the
    //  left and right borders of the box! So for each side:
    //  -   1 star fills the paddging gap on the top and bottom.
    //  -   1 star connects the horizontal and vertical lines together.
    int boxStringLength = stringLength + 4;
    for (int i = 0; i < boxStringLength; i++)
    {
        //  When we're dealing with single characters, putchar is a much
        //  more efficient approach to outputting it to the console than
        //  printf! It doesn't need to mess about with 
        putchar('*');
    }
    putchar('\n');
    printf("* %s *", userInput);
    putchar('\n');

    for (int i = 0; i < boxStringLength; i++)
    {
        //  When we're dealing with single characters, putchar is a much
        //  more efficient approach to outputting it to the console than
        //  printf! It doesn't need to mess about with 
        putchar('*');
    }
    putchar('\n');
    return 0;
}
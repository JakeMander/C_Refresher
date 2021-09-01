#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/*
    In this demo we'll recap some of the basics of structures that we've 
    covered including:

    - Declaring structures.
    - Initializing structures.
    - Accessing structure members.
    - Inspecting structure memory layout.

    In this example, we'll be building an app that declares and initializes a 
    structure and displays it's layout in memory.

    We'll use the "Grade" structure we've defined in our previous examples as
    the demo struct we'll use to demonstrate how memory is allocated for 
    structures.
*/

typedef struct Grade 
{
    char letter;
    int rank;
} Grade;

int main(int argc, char* argv[])
{
    // Declare and initialize a Grade structure variable.
    const Grade studentGrade = {'A', 96};

    // Read values from the struct's members. 
    printf("\n\nLetter:\t\t\t\t\t%c\n", studentGrade.letter);
    printf("Rank:\t\t\t\t\t%d\n", studentGrade.rank);

    // Get byte size of struct members and total byte of struct.
    const size_t letterByteSize = sizeof(studentGrade.letter);
    const size_t rankByteSize = sizeof(studentGrade.rank);

    printf("\n\nSize of studentGrade.letter is:\t\t\t%zu\n", letterByteSize);
    printf("Size of studentGrade.rank is:\t\t\t%zu\n", rankByteSize);

    const size_t studentGradeByteSize = sizeof(studentGrade);
    printf("Total Size of studentGrade in bytes:\t\t%zu\n", studentGradeByteSize);


    // Calculate necesssary padding via sizes of struct members.
    const size_t totalPaddingInGradeStruct = studentGradeByteSize - (letterByteSize + rankByteSize);
    printf("Total padding of Grade structure in bytes: \t%zu\n\n", totalPaddingInGradeStruct);

    printf("Address of Letter Member: \t\t\t%p\n", &studentGrade.letter);
    printf("Address of Rank Member:\t\t\t\t%p\n", &studentGrade.rank);

    const size_t letterOffset = offsetof(struct Grade, letter);
    const size_t rankOffset = offsetof(struct Grade, rank);
    const size_t padding = rankOffset - (letterOffset + letterByteSize);

    printf("Letter Byte Offset is: \t\t\t\t%8zu\n", letterOffset);
    printf("Rank Byte Offset Is: \t\t\t\t%8zu\n\n", rankOffset);
    printf("------------------------------------------------------\n");
    printf("|   Letter: %zu   |   Padding: %zu   |   Rank: %zu   |\n", letterOffset, padding, rankOffset);
    printf("------------------------------------------------------\n\n");
    return 0;
}
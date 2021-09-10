#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define NUMBER_OF_FAMOUS_PEOPLE 4

typedef enum countries
{
    GERMANY,
    USA,
    ITALY
} countries;

//  Array that binds to the order of the enums. Therefore the numerical values
//  of the enums correspond to the strings. So countriesStrings[GERMANY] is
//  equal to countriesStrings[0] which gives us "Germany".
char *countriesStrings[3] = {"Germany", "USA", "Italy"};

struct famousPerson
{
    char name[35];
    char knownFor[35];
    char *countryOfResidence;
    struct tm *born;
    struct tm *died;
};

/*  
    Function Prototypes

    CreateFamousPerson: Returns a malloced reference to a person struct.
    Saves on repeated code whilst allowing us to return a pointer to
    a struct that doesn't go out of scope.

    CreateLifespanTime: Returns a malloced reference to a tm struct that
    contains the month and year of a famous person's death/birth. By
    doing this, we save on repeated code whilst being able to create
    a reference to a struct that doesn't go out of scope at the end
    of the function call.

    PrintFamousPerson: Function to print out the details of a famous person.
    Recieves a pointer so as not to copy the struct value.

    PrintFamousPeople: Function to iterate over a provided array of famous
    people and print out each person's details. 

    FreeMemory: Clear up all the memory that was dynamically allocated during
    the creation of a famous person.
*/
struct famousPerson* CreateFamousPerson();
struct tm* CreateLifespanTime(int YYYY, int MM);

void PrintFamousPerson(struct famousPerson *personToPrint);
void PrintFamousPeople(struct famousPerson **peopleToPrint, int numberOfFamousPeople);

void FreeMemory(struct famousPerson **people, int numberOfPeople);

int main (int argc, char *argv)
{

    struct famousPerson *johannesGutenberg = CreateFamousPerson();
    struct famousPerson *elisabetCStanton = CreateFamousPerson();
    struct famousPerson *galileoGalelei = CreateFamousPerson();
    struct famousPerson *martinLuther = CreateFamousPerson();
    
    char* country = countriesStrings[GERMANY];
    strcpy(johannesGutenberg -> name, "Johannes Gutenberg");
    strcpy(johannesGutenberg -> knownFor, "Modern Printing Press");
    johannesGutenberg -> countryOfResidence = countriesStrings[GERMANY];

    johannesGutenberg -> born = CreateLifespanTime(1400, 1);
    johannesGutenberg -> died = CreateLifespanTime(1468, 2);

    strcpy(elisabetCStanton -> name, "Elisabet C Stanton");
    strcpy(elisabetCStanton -> knownFor, "Women's Rights");
    elisabetCStanton -> countryOfResidence = countriesStrings[USA];
    elisabetCStanton -> born = CreateLifespanTime(1815, 11);
    elisabetCStanton -> died = CreateLifespanTime(1902, 10);

    strcpy(galileoGalelei -> name, "Galileo Galelei");
    strcpy(galileoGalelei -> knownFor, "Physics");
    galileoGalelei -> countryOfResidence = countriesStrings[ITALY];
    galileoGalelei -> born = CreateLifespanTime(1564, 2);
    galileoGalelei -> died = CreateLifespanTime(1642, 1);

    strcpy(martinLuther -> name, "Martin Luther");
    strcpy(martinLuther -> knownFor, "The Reformation");
    martinLuther -> countryOfResidence = countriesStrings[GERMANY];
    martinLuther -> born = CreateLifespanTime(1483, 11);
    martinLuther -> died = CreateLifespanTime(1546, 2);

    struct famousPerson *listOfFamousPeople[NUMBER_OF_FAMOUS_PEOPLE] = {johannesGutenberg, elisabetCStanton, galileoGalelei, martinLuther};
    PrintFamousPeople(listOfFamousPeople, NUMBER_OF_FAMOUS_PEOPLE);

    printf("Shuffling Famous People...\n\n");

    struct famousPerson *temp = NULL;

    //  Store Elisabeth C Stanton...
    temp = listOfFamousPeople[1]; 

    //  Place Martin Luther in the place of ECS.
    listOfFamousPeople[1] = listOfFamousPeople[3];

    //  Overwrite Martin Luther's old addres with Johannes Gutenberg.
    listOfFamousPeople[3] = listOfFamousPeople[0];

    //  Finally, place ECS at the top where JG was previously.
    listOfFamousPeople[0] = temp;

    PrintFamousPeople(listOfFamousPeople, NUMBER_OF_FAMOUS_PEOPLE);
    FreeMemory(listOfFamousPeople, NUMBER_OF_FAMOUS_PEOPLE);
}

struct tm* CreateLifespanTime(int YYYY, int MM)
{   
    if (MM <= 0)
    {
        return NULL;
    }
    
    //  Assign the recieved month and year function to the struct as these are
    //  the only values we're interested in for our famousPerson's date
    //  members.
    struct tm *newDateRef = (struct tm*) malloc(sizeof(struct tm));
    newDateRef -> tm_year = YYYY - 1900;
    newDateRef -> tm_mon = MM - 1;

    return newDateRef;
}

struct famousPerson* CreateFamousPerson()
{
    struct famousPerson *newPersonRef = (struct famousPerson*) malloc(sizeof(struct famousPerson));
    return newPersonRef;
}

void PrintFamousPerson(struct famousPerson *person)
{
    char dateBornString[35];
    char dateDiedString[35];

    //  Convert the person's born and died time's to a readable string
    //  format (YYYY MM) and store in the buffers.
    strftime(dateBornString, sizeof(dateBornString), "%B %Y", person->born);
    strftime(dateDiedString, sizeof(dateDiedString), "%B %Y", person->died);

    printf("Index 1:\n Name: %s,\n Known For: %s,\n Country of Residence: %s,\n Date of Birth: %s,\n Date of Death: %s\n", 
    person -> name,
    person -> knownFor, 
    person -> countryOfResidence,
    dateBornString,
    dateDiedString);
}

void PrintFamousPeople(struct famousPerson **people, int numberOfPeople)
{
    for (int i = 0; i < numberOfPeople; i++)
    {    
        PrintFamousPerson(people[i]);
        printf("\n");
    }
}

//  Make sure we clear all the dynamic memory we used to set up all our
//  famous people! THAT INCLUDES THE MEMORY WE USED TO MAKE THE MEMBER
//  FIELDS OF THEIR BIRTH AND DEATH DATES!
void FreeMemory(struct famousPerson **people, int numberOfPeople)
{
    for (int i = 0; i < numberOfPeople; i++)
    {
        struct famousPerson *person = people[i];

        char name[50];
        
        strcpy(name, person -> name);
        free(person -> born);
        free(person -> died);
        free(person);
        printf("%s Has Been Cleared From The Heap\n", name);
    }
}
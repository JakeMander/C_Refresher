#include <stdlib.h>
#include <stdio.h>

/*
    Structures are absolutely essential in C when it comes to working with
    memory and data.

    In simple terms, structures (or "structs") are essentially user defined types.

    Structures are groupings of other types that form an abstraction of an 
    idea, an object or a entity that represents something that plays a role in
    the business logic of your code.

    These type groupings can consist of either types that form part of the C
    language (i.e. integer, float double), or they may be other structure types
    defined by you or another programmer.

    The name "structure" lends itself rather well to the concepts purpose. Why?

    Because they form 'housing' for other data types!

    Structs in C:

    - Creating custom data types.
        - Essential for defining businesss language and forming the domain 
          language around the problem your code is aiming to solve.

    - Allows for composition of data types 
        - Structures allow you to combine multiple data types together. They 
          are powerful means of combining built-in types and other user-defined
          types into a single entity that can be easilly reasoned about.

    This makes them useful for:

    - Constructing objects and modelling data.
        - For example, let's say we're building an admin system for a school. 
          If we want to represent a "student" in a C school app, we'll most
          likely create a Student structure to represent that in our app as
          a business logic concept.

          The student could then contain data we need including, age, contact
          details, grades, attendance and other useful information that we can
          logically group together and thus easilly access and track.

    - Data hiding.     
        - C is not an object oriented programming language, so the concept of 
          "encapsulation" does not apply in the OOP sense.

          However, structs can be useful in hiding away internal logic and 
          abstactions which can be used to create libraries of code. Structures
          are useful for hiding away internal logic within your program, as 
          well as exposing an API for your library consumers to use.

          The concept of hiding away critical internal logic and calculation 
          from portions of code or third parties who have no need to access 
          them is of critical importance in programming. 

          Allowing someone to have full access to the important internal logic 
          that forms the bulk of your calculations in code and libraries 
          exposes your code to modifications that can break other portions 
          of your code, or produce results that are invalid. 

          Instead, you should hide away this logic away from other consumers 
          and instead, provide an API that allows programmers to access the 
          results  of such calculations or the ability to process values in a 
          clear and safe way. 

    - Business logic.
        - Structures provide the foundation for describing and reasoning about 
          the business logic of your problem domain. Structures put names to 
          different entities within the problem domain and essentially set out 
          how each entity  will interact with one another in the context of 
          your application.

    - Memory management.
        - Structuresa are vital in memory management. In this section, we'll 
          explore in greater depth how we can manage the memory of structures 
          and how to manage memory using structures.

    
    As mentioned previously, one of the core benefits of using structures is the 
    ability to group types together into a logical grouping.

    For example, let's say in our problem domain we want to represent a "Person"
    entity who will be using our app. We could use a C structure to model this!

    Typically, we might want to assocaite the following attributes with a 
    "Person" type:

    struct Person
    - Name (char *)
    - Age (int)
    - Weight (double)

    Notice how we have a nice logical grouping of multiple different types 
    (these are called members). Each member describes an aspect of a person.

    If we really wanted to, we could give our struct function pointers to 
    provide the behaviour we'd associate with a person such as waving, sitting
    or standing!

    We'll explore the code behind implementing such behaviour in greater depth
    in the next unit!
    
        

*/
int main(void)
{

}
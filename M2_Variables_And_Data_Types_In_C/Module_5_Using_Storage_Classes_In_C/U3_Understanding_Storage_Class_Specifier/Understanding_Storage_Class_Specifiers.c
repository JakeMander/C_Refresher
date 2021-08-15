#include <stdlib.h>
#include <stdio.h> // For printf

/*
    Now we know what storage classes are and what the define, let's have a look
    at the specifiers used by them.
*/

//  Prototype for "static" demo.
int staticFuncOkay();
int staticFuncInfiniteLoop();

int main (void)
{
    /* 
        According to the C18 standard, there are 6 storage class types 
        available.

        These Are:
            -   typedef.
                -   Provides the ability to assign an alternative name to an
                    existing data type so you can then use that name as a type
                    when declaring variables.

            -   _Thread_local (Introduced in C11)
                -   Sets the lifespan of a variable to the lifespan of a given
                    thread. Note that this class is not fully supported in all 
                    compilers!

            -   auto, register, static, extern
                -   The most commonly used storage classes. Will be detailed 
                    individually. 
                
        To start with, let's have a look at using the Typedef specifier:
    */

    //  Struct without typedef
    struct person {
        char name[50];
        char address[100];
    };

    //  Notice how we have to call the struct keyword to initalise a value of
    //  the person struct type.
    struct person p1 = { "John", "Main Road"};

    printf("%s\n", p1.name);

    //  To simplify the initalization of a person struct, we can use
    //  typedef to explicitly bind a name to the struct datatype we 
    //  wish to create.
    typedef struct personTwo {
        char name[50];
        char address[100];
    } personTwo;

    personTwo p2 = { "Bob", "High Street"};
    printf("%s\n", p2.name);
    
    /*  
        Remember, when we define a struct, we are actually defining a new 
        datatype of "struct [name]" with multiple member variables. 

        With typedef, we essentially assign a new alias to our struct
        of type struct ["name"], so we can simplify the call by
        using the new typedef alias and initalising the object as normal.
    */

   /*
        Let's have a look at the "auto" keyword next. 

        Auto is essentially the default storage class for local variables.

        For example, the example below is equivalent to:
        
        int autoNumber = 3;

        All variables defined inside a function, loop or conditional statement
        use "auto" as it's storage class.

        What does this mean? It means the variable is stored on the stack.
        Therefore the memory used for that variable is automatically
        allocated and deallocated when required or no longer used.
   */
   auto int autoNumber = 1;
   printf("AutoNumber: %d\n", autoNumber);

   /*
        Next up, let's look at the "register" storage class.

        When we use the "register" storage class, we tell the executable
        to store that variable as part of a register in the CPU, not in
        memory.

        In doing so, theoretically  the variable can be accessed in a more 
        performant way, but in doing so we can no longer reference the variable
        using pointers...

        Why? Because pointers point to memory addresses not registers!

        The register keyword can be used in function declerations to declare
        function parameters.

        In reality, using register very rarely increases performance owing to 
        how compilers optimise memory management and variable lifespan for you.
        Therefore, use register with care!
   */

    register char letter = 'Z';
    printf("ASCII Value Of The Variable 'Letter' Stored In The Register: %d\n", letter);
    printf("Char Value Of The Variable 'Letter' Stored In The Register: %c\n", letter);

    /*  
        Typically, with printf we need to access non-char array variables with a pointer.
        With a variable defined as "register" storage class, doing so is invalid as we
        reference a CPU register not a memory address. For example, the following is
        invalid:
    */
    
    // printf("ASCII Value Of The Variable 'Letter' Stored In The Register: %d\n", &letter);

    /*
        Next up, let's look at the static storage class.

        If we use the "static" keywork with a variable, we tell C to store that variable
        in the heap section of memory. In doing so, the variable is stored in memory for 
        the entire lifetime of the program and can be accessed from anywhere in the 
        program.

        Static variables can be declared as either global or local variable which creates
        a single copy of the variable which is to be shared in the app.

        What this means is, once a static variable is initalised, it cannot be reinitialised
        (i.e. if a static variable is in a loop that increments the value, it will not be
        reinitialized to it's original value, it is incremented!). Once a static variable
        is initialized, any further attempts to reinitalize the variable will result
        in the current stored value being returned (demonstrated below). 

        Finally, it's important to note that static variables are the first variables to be
        compiled during the compilation process. This means that they are the first variables
        that can be accessed in your code.

        Functions declared as static will override the default storage class behaviour of
        "extern" (explained next). This means the function will be globally accessible,
        but will require it's definition to be made in the same file. 
    */

   int staticDemoResult = 10;
   
   do {
      staticDemoResult = staticFunc(); // Exists loop! Because local is static, value is modifiable!
      // staticFuncInfiniteLoop() // Infinite Loop! Local is non-static! Value is always 5! 
   } while (staticDemoResult); // Will keep going while value is > 0 (i.e. true);
   puts("");



   /*
        Finally, we'll look at "extern".

        The extern storage class allows you to make variables accessible in other
        files when imported to another file. The extern storage class also allows
        you to make a variable global in scope. 

        Typically, extern will be used to declare functions and variables that
        need to be accessible in other files.

        It does this by implicitly telling the C compiler that the value of
        a variable in the current file will be declared later in another
        file, and that definition of the value and allocation of memory
        should be deferred until the linker (that's the component in the C
        compilation process that links all the object files together ready
        to form an executable binary) runs. By doing this, the compiler is happy
        that we haven't just forgotten to assign a value to our variable. 

        Variables that implement the extern storage class can only be declared
        (i.e. telling the compiler "this variable exists"), not defined 
        (i.e. telling the compiler "this variable exsits, has this value
        and needs some memory assigning") unless that variable is defined as 
        a "const".

        Why is this? Because the purpose of extern is to defer definition in
        this particular file because the expectation is it will be defined
        elsewhere.

        Attempting to assign any value to a variable defined as extern inside
        a file will result in a compiler error. Why? Because in eseence, you
        are attempting to assign a value to a variable who is waiting to have
        it's memory assigned!

        As mentioned previously, extern is the default storage class for
        functions defined in a C file. As such, the "extern" keyword does
        not need to be implicitly added at the start of a function 
        heading. 

        It's useful to note that extern is useful when we create global state
        using variables defined in C header files. 

        But first a note.

        Typically in C and C++ we group like functionality into single files.
        Doing this makes programs more strcutred and splits code out into more
        maintainable pieces. 
        
        But remember, code execution runs top to bottom. So what happens when a 
        function at the top of our code depends on a function that lives below
        it?
        
        Well we end up with a compile-time error because the function is 
        attempting to call a function that the compiler doesn't yet know
        exists!
        
        To get around that, programmers split their code implmentation and
        decleration for like functionality into two files. The header file
        (.h) and the source file (.c / .cpp).

        The header contains all the function protypes and variable declerations 
        we need  in the implementation of our code and is imported into the 
        source file.
        
        By doing this, the file now has all of the function and variable declerations
        it needs to know about placed right at the top of the file which the compiler
        then reads! As the compiler now has access to this, it can pre-emptively 
        determine which functions are going to be in the file and will no
        longer throw exceptions for functions that are present in the file, but just
        live somewhere that it hasn't yet read.

        By using extern in header files, we can declare global variables that we 
        intend to be used across multiple files, but intend to define in a source
        file somewhere in our code. 

        Now technically speaking, not using extern will result in the value of
        our variable, in most cases, globally accessible to other files.

        However, because our variable is not external, the C compiler and linker
        simply pass the values back to the file importing the header by value.

        Because of this, we can end up with multiple instances of a global variable
        which can cause bugs if multiple files depend on a reference to one global
        variable.

        By using extern, we explcitly instruct the C linker to insert the reference to
        the variable by reference which means all files importing the C header file 
        containing our extern linked variable all have access to the same memory address
        when accessing the variable.  

        Generally speaking, it is inadvisable to create global state in applications
        as it can result in lot's of "spooky" behaviour for other developers when
        the project grows and multiple parts of the program start editing the same
        variable that lots of other components have a dependency on.

        Functions are a good starting point in preventing global state! Pass 
        around functions that are strict in the parameters they expect and
        return a new value of manipulate the values you pass in. This 
        makes it much easier to diagnose problems and ensures that 
        modification of values is tightly controlled through functions!

        Also, consider creating what you need in your main file, and passing it where
        it needs to go from there! 
        

   */
    
    return 0;
}

int staticFunc() {
    //  Local static variable - lifetime is for duration of program.
    //  Each call to this function will use the last value of the
    //  variable!
    static int staticVar = 5;
    printf("%d", staticVar);

    staticVar = staticVar - 1;

    return staticVar;
}

int staticFuncInfiniteLoop() {
    //  NOT STATIC! Value is local and thus reinitalized to 5 each call!
    int nonStaticVar = 5;
    printf("%d\n", nonStaticVar);

    nonStaticVar = nonStaticVar - 1;

    return nonStaticVar;
}
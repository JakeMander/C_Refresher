/* 
    Setup: 
    C can be a bit of a pain to set up. The GNU compiler will normally work
    fine. If you're using the MS Cl compiler, then you may need to open your
    project via the "code" command in the CLI so that the project opens with
    the correct PATH and project dependencies installed. Otherwise you might
    run into a few errors. Alternatively, just use another IDE (i.e CLion, Codeblocks).  
    
    If you're stuck in VS Code just follow the intructions here:
    
    https://code.visualstudio.com/docs/cpp/config-msvc
    
    The other issue you might run into is the program closing immediately.
    This is normal behaviour for an environment that isn't set up to pause 
    on program compleition. Ther are two solutions for this:
    
    1. Run the .exe file directly through the CLI.
    2. Import "stdio.h" and use the "getchar()" function to pause the program
        until the user enters an input.  
      
    The general gist here is, this is what a C Program looks like. 

    Overview:
    "main" acts as the entry point to the program. C is a procedural language and built around 
    functions. "main" is the function that starts the program off. Void is a parameter,
    or a function input. Typically, main will take in arguments passed in from the command
    line. By defining a parameter here, we can take in input from the command line
    and use it in our program. It's not vitally important to know this at this stage however.

    Notice how our function starts with "int". That's the return type. It's what
    we explicitly want our function's return value to be a type of. In the main function,
    this value is passed back to the OS to determine if everything ran okay. 0 means everything
    ran fine. Anything other than 0 is an error!
*/

int main(void)
{
    return 0;
}
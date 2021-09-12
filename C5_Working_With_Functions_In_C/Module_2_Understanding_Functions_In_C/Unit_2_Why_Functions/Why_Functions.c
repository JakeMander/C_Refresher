/*
    So why use functions?

    If we think back to the very start of our C learning, it was explained that
    every C program starts in the "main" function. It is the "entry point" of
    every C application.

    Without functions, all of the functionality of your program would end up
    crammed into this one function. This would be incredibly messy and 
    confusing for both yourself and other programmers.

    Instead, unless your C program is very small (about 50 lines or so) you
    should ideally think about breaking up your C program into smaller, more
    managable blocks of code contained inside functions!

    By doing so, you can define pieces of your program in a more managable fashion.
    This makes testing and debugging your program much easier.

    You may have already come across other languages that implement "classes" or
    "modules". In C, there are no such constructs to contain like behaviour and 
    functionality.

    Instead, the C language relies on functions as the main currency of 
    code-reuse and modularity.  

    Without proper use of functions, you abandon the proper seperation of 
    concerns in your program. This will ultimately result in spaghetti code
    that is hard to follow, test, debug, manage and maintain.

    Code like this lacks quality!

    Instead, by splitting our code into multiple, smaller functions we are 
    actively pursuing seperation of concerns, thus making our code more 
    manageable and modular. A big benefit of this is code becomes a lot
    easier to test!

    When a program is split into small blocks of code that each address one
    issue, problem or task, our code becomes incredibly easy to test!

    If a C program or application is easy to test, you can be confident that 
    your C code and it's API's are well defined in terms of modularity.

    When code bases are split into smaller functions, blocks of code are
    easier to test in isolation! This helps achieve 100% test coverage across
    projects. This is something that all programs should aim to achieve!

    To help us learn about functions, our friends at Wired Brain Coffee have
    reached out to us again asking for help! Once again, they've having
    problems with the coding style and modularity of the code that helps
    run their coffee machines, and they're asking for help again!

    Out task is to help make Wired Brain Coffee'sm code easy to read, manage
    and maintain! To do this, we'll be creating a C library for 
    Wired Brain Coffee to work with!

*/
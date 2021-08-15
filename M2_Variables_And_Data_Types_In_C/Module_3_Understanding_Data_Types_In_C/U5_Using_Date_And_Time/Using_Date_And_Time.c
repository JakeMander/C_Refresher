#include <stdlib.h>
#include <stdio.h>   //  For printf
#include <time.h>   // For date/time handling.
#include <locale.h> // For locale.

/*
   In this tutorial, we'll look at how C handles date, time,
   and localization.
*/

int main(void)
{
    /*
        Once the time.h header is imported, a range of functions,
        constants, types and macros will become available.

        To start with, we'll look at some of the types
        provided by the time.h library.

        First of, let's look at the "tm" struct type. 
        
        This contains the properties that make up a datetime including 
        seconds, minutes, days, months years etc. etc.

        We can use tm to build a datetime value by populating the properties
        we need. 

        We also have the time_t type which can be used to store
        time values i a usable format. Typically this will work
        alongside the time() function. time_t will store the time
        as a calendar time (i.e. year/month/day/hour).

        Alternatively, clock_t is another time type which can be
        used to store a time value.
        
        This however DOES NOT USE CALENADAR TIME. It represents a clock time.
        A clock time is based on the cycles of a systems processor and is 
        reprsented by  a long value.

        Time.h also provides the timespec struct which stors an interval
        of time broken down into seconds and nanoseconds.

        Next up, let's take a look at some of the functions defined
        by time.h

        We have:

        time_t time (time_t *destTime) 
            Returns (time_t) - the time in seconds in unix time (or the 
            number of seconds since midnight on 1st Jan 1970)).

            Parameters - 
                *destTime: A pointer to a time_t object where the seconds
                value will be stored (the function does return this anyway so 
                you can use NULL here ).

            Use when you want the current time in a UNIX format.


        double difftime (time_t timeEnd, time_t timeStart);
            Returns (double) - The difference in times (in seconds) between
            the two parameters provided.

            Parameters - 
                timeEnd (time_t) - A time_t value representing the end time to 
                compare the difference between.
                
                timeStart (time_t) - A time_t value representing the start time to 
                compare the difference between.

            Use when you want calculate the difference in seconds between two
            times.

        struct tm * localtime (const time_t *sourceTime)

            Returns (struct tm) - A structure that represents the time provided
            in the parameter broken down into it's individual time parts. 

            Parameters -
                timer (const time_t *) - A pointer to a value of type time_t that
                has a time value to convert.

            Use when you want to break down the time passed in as the parameter into
            it's consituent parts (i.e. seconds, minutes, hours, days, weeks etc. etc.)


        size_t strftime (char *strDest, size_t maxsize, const char *format, const struct
        tm *timeptr)

        Returns (int) - The function returns the number of characters copied to the 
        array pointed to by the ptr parameter. If the length of the output string is
        greater than the specified maximum size passed in via the parameter, then 
        0 is returned and the contents of the array pointed to by ptr are 
        indeterminate (i.e. the fuction couldn't run properly, so the value of the 
        array will be whatever leftover values were stored in that memory location
        when used by the system).

        Parameters -
            strDest - A pointer to the dsetination array where the created C string
            containin the new formatted time string will be cpied to.

            maxSize - The maximum number of characters to be copied to ptr INCLUDING
            the null-character

            format - The C string containing any combination of regular characters
            and special format specifiers. The format specifiers are placed by the
            function to the corrrspsonding values to represent the time specified in
            timeptr.

            timeptr - Pointer to a tm struct that contains a calenda time broken
            down into it's components. 

        Use when you want to build a string from a given time and date string format
        using the format specifiers used by C's time library:
        https://www.cplusplus.com/reference/ctime/strftime

        In essence, you pass in a reference to the array you want to write to, pass in 
        the max size you want the output string to be (icluding the null terminator),
        a defined format you want your output string to be, and how your time values
        will be formatted, and a reference to the time struct that will be used to 
        populate the time format and build the final string.

        The function copies the constructed string to the array passed in as the parameter
        and returns the number of characters that were copied across

        int timespec_get(struct timespec* time_spec, int base); (Available in the C11 spec)

        Returns - The value of "base" if successful. Zero otherwise.

        Parameters -
        time_spec(struct timespec*) - A pointer to a struct that is set to the time in seconds 
        and nanoseconds since the start of the epoch (Jan 1 1970 @ midnight).

        base (int) - TIME_UTC or another nonzero integer value indicating the time base.
        (i.e. UTC+1, UTC-1, UTC+2, UTC-2)

        This function gets the current calendar time in given time base and stored it in the
        given time spec parameter. 

        Now let's take a look at an example of getting the current time and formatting it
        using what we now know.
    */

   //   Return the current time in seconds since 1970 @ 00:00.
   //   Null pointer as we don't want to assign the value to
   //   ant other variables other than the one we return the value to.
    time_t timeInSeconds = time(NULL);

    /* 
        We now need to let C convert the time in seconds sinxe 1970
        to a much more useful calendar time of it's consitutent parts.
        We can do this by using localtime() to convert our time_t
        value into a struct of all the calendar values extracted
        from the seconds.
    */
    struct tm *ptm = localtime(&timeInSeconds);

    /*
        Here we format our output from the ptm tm struct!

        We essentially extract all of the time components using
        the struct's built in member properties. 

        But why do we need to add 1900 on to the year?

        Well the tm struct treats the retrieved system time relative
        to 1900. So in actuallity, 2021 - 1900 (121) is actually 
        being stored in the year property. 

        To account for this, we need to add 1900 to give us 2021!
        (As of the year this tutorial was written).
    */
    printf("The Time Is: %02d/%02d/%04d  %02d:%02d:%02d\n",
    ptm -> tm_mday, ptm -> tm_mon, ptm -> tm_year + 1900,
    ptm -> tm_hour, ptm -> tm_min, ptm -> tm_sec);

    //  Remember we can also use strftime
    char buffer[80];
    strftime(buffer, sizeof(buffer), "The Current Datetime is: %c", ptm);
    printf("\n%s\n", buffer);

    /*  
        Now let's explore how to make our apps able to use different
        locale's so we can handle things such as number format and 
        currency using other country's symbols and formats.

        To do this we can use the locale.h library.

        Here we have a range of useful components such as:

        Types:
            -   struct lconv - Bundles together properties such as a cultre's 
                currency symbol, how a currency is formatted, and where the
                decimal point is in a numeric value.

        Functions 
            - char * setlocale(int category, cont char *locale) - Sets a number of 
            variables used by the locale.h file to values that match the locale
            represented by the provided string (locale). Category is a macro 
            of an integer value that defines either a specific locale detail
            to change (if a specific category is provided) or to set all of
            the variables in the locale header to the respective culture provided
            by "locale" if the LC_ALL Macro is provided.

            - struct lconv * localeconv(void) - Returns a pointer to a struct lconv
            for the current locale (i.e. whatever was set in the setlocale call).

            Now let's run a quick demo to see locale in action:
    */

    puts("\nLocale Demo");

    //  Set all locale values to whatever the system's locale is currently set
    //  to (An empty locale parameter is provided, the default environment variables
    //  currently used by the OS will be used - These will be GB on my system!)
    setlocale(LC_ALL, "");

    //  Get a pointer to a locale struct populated with the values used 
    //  by the locale set by setLocale.
    const struct lconv* const currentlocale = localeconv();

    printf("In the current locale, the default currency symbol is: %s\n", 
    currentlocale -> int_curr_symbol);
    return 0;
}
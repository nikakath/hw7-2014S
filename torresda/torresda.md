Using macros to debug!!!
------------------------

In case the assertion fails (the condition is false), the macro will print a very detailed error message, including the file name, function name and line number, and then, it will terminate the program. 

/* Crash the process */
#define __CRASH()    (*(char *)NULL)

/* Generate a textual message about the assertion */
#define __BUG_REPORT( _cond, _format, _args ... ) \


Found at:
---------
http://www.rt-embedded.com/blog/archives/macros-in-the-c-programming-language/
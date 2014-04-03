Sets the flags to be given to the C compiler, in this case just '-Wall', which 
displays all warnings:
'''
CFLAGS = -Wall
'''

Declares 'clean' to be a phony target, meaning that make will always run the recipie when given the clean command (instead of checking to see if there is a file named clean that needs to be updated)
'''
.PHONY : clean
'''

The default rule, consisting of a target followed its prerequisites and then the recipie for the target:
'''
stopwatch : stopwatch.o
        $(CC) $(CFLAGS) -o stopwatch stopwatch.o
'''

Another rule, this time concerning the prerequisite for the default rule:
'''
stopwatch.o : stopwatch.c
        $(CC) $(CFLAGS) -c stopwatch.c
'''

Instructions for what to do when the 'clean' command is called:
'''
clean :
        -rm -f *.o *~
'''

References:
[Managing Projects with GNU Make, Third Edition](http://oreilly.com/catalog/make3/book/index.csp)
[GNU Make](https://www.gnu.org/software/make/manual/make.html)
[Markdown Cheatsheet](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet#links)

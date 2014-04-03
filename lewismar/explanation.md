### Makefile Explanation

Display all warnings with
CFLAGS = -Wall

Normally, there would need to be a rule within the makefile for how to compile qrencode.o. Make is smart and does this for me, so I don't need to include the rule.


Creates encoding and/or decoding from their *.c files.

First, it tells make to use _gcc_ with the _-Wall_ flag. 
If told to make all files, it makes both encoding and decoding. A rule is given for creating a .o file from a .c file, and then a suffix-free executable from a .o file.

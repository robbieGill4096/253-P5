#------------------------------------------------------------------------------
#
# Makefile --- Demonstrate how to rebuild *.o files if a *.h file changes
#
# Note:  This approach uses gcc -MM and a dependency file
#
# Operation
#    1. The first dependency for target all is rules.d, and make will bring
#	this file up-to-date first.
#    2. The rule for building rules.d ensures the file will be rebuilt if any
#       C source, header or the Makefile itself changes.  Note the use of
#	gnu make's wildcard function to generate a list of names of C source
#	and header files.
#    3. The recipe for rules.d invokes the gcc compiler with its -MM option
#	causing gcc to write a list of Makefile rules to stdout rather than
#	compiling anything.  Each of these rules is in the form of:
#		something.o: something.c someHeaderFile.h anotherHeader.h
#    4. The include statement is a directive not a rule.  It causes make to
#	read the contents of rules.d, the true dependencies for each *.o
#    5. The executable program contains a dependency upon each of the *.o
#   	files which make will update (using the rules included from
#	the rules.d file) before linking the objects.
#
# WARNINGS
#	The use of gcc's -MM option, gnumake's wildcard function, and gnumake's
#	include directive are significant dependencies upon the gnu toolchain.
#	Verify these features exist in your toolchain before committing your
#	project's build to them.
#
# Author(s)
# 09/05/18 Epoch............................................................jrc
#
#------------------------------------------------------------------------------

#-------Define names of all the object files in this project
	OBJS = smash.o history.o commands.o

#-------Define the name of the resulting released product
	EXE = smash

#-------Define options passed by make to the compiler
	CFLAGS = -Wall -std=c99

#-------Define target "all" for building the executable(s)
all:	rules.d $(EXE)

rules.d: Makefile $(wildcard *.c) $(wildcard *.h)
	gcc -MM $(wildcard *.c) >rules.d

#-------Include the rules for rebuilding each *.o file
-include rules.d

#-------Rule for linking the executable product
$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

#-------Rule for cleaning build and emacs artifacts
clean:
	rm -f $(OBJS) $(EXE) *.d  *~

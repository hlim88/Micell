#############################################################################
#
#  Compiler commands
#
#############################################################################
CC_COMMAND = gcc
CFLAGS    = -g

CLIBS = -lm

SYS_INC_PATHS  = /usr/local/include
INCFLAGS       = -I$(PWD)/include -I$(SYS_INC_PATHS)
LIBFLAGS       = -L/usr/local/lib $(CLIBS)

CC             = $(CC_COMMAND) $(CFLAGS) $(INCFLAGS)
CC_LOAD        = $(CC_COMMAND) $(CFLAGS)

##################################################################3
#
# Default make rules
#
##################################################################3
.c.o:
	$(CC) -c $*.c

##################################################################3
#
# Default make rules
#
##################################################################3
FILES = main.o evolve.o pdotpn0.o qdotpn0.o pdotpn2.o qdotpn2.o util.o\
        sv0.o sv2.o

tb: $(FILES)
	$(CC_LOAD) $(FILES) $(LIBFLAGS) -o $@


clean:
	rm -f *.o *.sdf tb


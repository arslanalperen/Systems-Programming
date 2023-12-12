CC = gcc
CFLAGS = -g -Wall -O2 -std=c99
DOXYGEN = doxygen
DOXYGEN_FLAGS = -s -g
OBJ := $(wildcard *.o)
SRC := hello.c hello-multi.c cmdline_args.c
EXE := $(SRC:.c=)

all: $(EXE) doc

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

%: %.o
	$(CC) -o $@ $< $(CFLAGS)

doc: $(SRC)
	if [ ! -f Doxyfile ]; then $(DOXYGEN) $(DOXYGEN_FLAGS); fi
	$(DOXYGEN) Doxyfile

clean:
	rm -f *.o $(EXE)
	rm -rf doc
# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=g++
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
LIBS=-I$(CPT_PATH) -L$(CPT_PATH) -lcpt


all: scattering wheatstone Problem1

scattering: scattering.cpp
	$(CC) $^  $(LIBS) -o scattering

wheatstone: wheatstone.cpp
	$(CC) $^  $(LIBS) -o wheatstone

Problem1: Problem1.cpp
	$(CC) $^  $(LIBS) -o Problem1

clean:
	rm -rf *o scattering wheatstone Problem1

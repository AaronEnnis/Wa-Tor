## Authors: Aaron Ennis (C00190504) & Lorcan Bermingham (C00196903)
## Date: 10/05/17
## Makefile using g++

CC=g++
CFLAGS=-g -c -Wall -std=c++11
LDFLAGS=
LIBFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
SOURCES=main.cpp Grid.h Grid.cpp Fish.h Fish.cpp Shark.h Shark.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main
BINDIR=/usr/bin
DOXYGEN = doxygen
INDEX_SRC = docs/html/index.html
INDEX = firefox $(INDEX_SRC)

ALL: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBFLAGS) $(DEBUGFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@ $(LIBFLAGS) $(DEBUGFLAGS)

CLEAN:
	rm *.o $(EXECUTABLE)

INSTALL:
	sudo cp -u $(EXECUTABLE) $(BINDIR)

UNINSTALL:
	sudo rm $(BINDIR)/$(EXECUTABLE)

DOC: 
	$(DOXYGEN) Doxyfile
	$(INDEX)
DOC: ALL

DEBUG: DEBUGFLAGS = -g -O0
DEBUG: ALL

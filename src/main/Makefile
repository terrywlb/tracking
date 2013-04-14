ROOT_DIR=./../..
HDR_DIR=/hdr
HEADERS=$(ROOT_DIR)$(HDR_DIR)

SOURCES=main.cpp
OBJECTS=$(SOURCES:.cpp=.o)

CC=g++
CFLAGS=-c -I$(HEADERS) $(shell pkg-config --cflags opencv) -g

$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES)
    
: 
	make $(OBJECTS)
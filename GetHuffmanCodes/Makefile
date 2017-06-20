CC=g++
CFLAGS=-c -Wall
SOURCES=main.cpp BinaryNode.cpp Test.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=GetHuffmanCodes

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	-find . -name '*.o' -exec rm -r {} \;
	-rm -f $(EXECUTABLE)

test:
	$ ./GetHuffmanCodes

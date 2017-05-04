CC=g++
CFLAGS=-c -Wall
SOURCES=main.cpp Test.cpp BinaryTreeNode.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=HeapPointers

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	-find . -name '*.o' -exec rm -r {} \;
	-rm -f $(EXECUTABLE)

test:
	$ ./HeapPointers

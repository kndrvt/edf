CC = g++
CFLAGS = -g -Wall -std=c++17
TARGET = prog_02200166_621
OBJECTS = main.o task.o tinyxml.o tinystr.o tinyxmlerror.o tinyxmlparser.o
FILENAME="input.xml"

all: $(TARGET)
	

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC)  $(CFLAGS) -c $< -o $@

run:
	./$(TARGET) $(FILENAME)

clean:
	rm -f *.o $(TARGET)
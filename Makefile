CC = g++
CFLAGS = -g -Wall -std=c++17
TARGET = EDF
OBJECTS = main.o task.o tinyxml.o tinystr.o tinyxmlerror.o tinyxmlparser.o

all: $(TARGET)
	

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC)  $(CFLAGS) -c $< -o $@

run:
	./$(TARGET)

clean:
	rm -f *.o $(TARGET)
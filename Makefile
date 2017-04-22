CC=g++ 
CCFLAGS=-std=c++11 -lsfml-graphics -lsfml-window -lsfml-system
LDFLAGS=
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
TARGET=AI

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS) $(CCFLAGS)

%.o: %.c %.h
	$(CC)  -c $< $(CCFLAGS)

%.o: %.c
	$(CC)  -c $< $(CCFLAGS)

clean:
	rm -f *.o $(TARGET)

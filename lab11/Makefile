CC=g++
CFLAGS=-c -std=c++17 -g
LDFLAGS=-lncurses -ltinfo
SOURCES=main.cpp Console.cpp Window.cpp GameWindow.cpp Maze.cpp Coordinate.cpp Explorer.cpp ShopWindow.cpp EndWindow.cpp Gen.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=amazing

all: $(SOURCES) $(EXECUTABLE) 

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:	
	rm -f *.o $(EXECUTABLE) 
	touch *

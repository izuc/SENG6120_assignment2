CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=TowerHanoi.cpp Disc.cpp TowerDemo.cpp
value_typeS=$(SOURCES:.cpp=.o)
EXECUTABLE=TowerDemo

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(value_typeS)
	$(CC) $(LDFLAGS) $(value_typeS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core
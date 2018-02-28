all: PA5

# Set CFLAGS to allow Debug and issue all warnings.
CFLAGS = -g -Wall -std=c++11


PA5: main.o
	g++ $(CFLAGS) main.o grid.o doodlebug.o ant.o organism.o -o PA5

main.o: grid.o organism.o ant.o doodlebug.o
	g++ $(CFLAGS) -c main.cpp -o main.o

doodlebug.o: ant.o
	g++ $(CFLAGS) -c Doodlebug.cpp -o doodlebug.o

ant.o: organism.o
	g++ $(CFLAGS) -c Ant.cpp -o ant.o

organism.o: grid.o
	g++ $(CFLAGS) -c Organism.cpp -o organism.o

grid.o:
	g++ $(CFLAGS) -c Grid.cpp -o grid.o


clean:
	rm -f *.o
	rm -f PA5
	rm -f -r html latex

docs:
	doxygen
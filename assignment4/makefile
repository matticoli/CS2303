all: qSim

# Set CFLAGS to allow Debug and issue all warnings.
CFLAGS = -g -Wall -std=c++11


qSim: main.o
	g++ $(CFLAGS) main.o event.o tellerevent.o customerevent.o eventqueue.o sortedeventqueue.o customerqueue.o -o qSim

main.o: eventqueue.o sortedeventqueue.o customerqueue.o customerevent.o tellerevent.o
	g++ $(CFLAGS) -c main.cpp -o main.o


customerqueue.o: eventqueue.o
	g++ $(CFLAGS) -c CustomerQueue.cpp -o customerqueue.o


sortedeventqueue.o: eventqueue.o
	g++ $(CFLAGS) -c SortedEventQueue.cpp -o sortedeventqueue.o


eventqueue.o: event.o
	g++ $(CFLAGS) -c EventQueue.cpp -o eventqueue.o


customerevent.o: event.o
	g++ $(CFLAGS) -c CustomerEvent.cpp -o customerevent.o


tellerevent.o: event.o
	g++ $(CFLAGS) -c TellerEvent.cpp -o tellerevent.o


event.o:
	g++ $(CFLAGS) -c Event.cpp -o event.o

clean:
	rm -f *.o
	rm -f qSim
	rm -f -r html latex

docs:
	doxygen
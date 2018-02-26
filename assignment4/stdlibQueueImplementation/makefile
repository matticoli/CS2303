all: qSim

# Set CFLAGS to allow Debug and issue all warnings.
CFLAGS = -g -Wall -std=c++11


qSim: main.o
	g++ $(CFLAGS) main.o event.o tellerevent.o customerevent.o eventqueue.o sortedeventqueue.o tellerqueue.o -o qSim

main.o: eventqueue.o sortedeventqueue.o tellerqueue.o customerevent.o tellerevent.o
	g++ $(CFLAGS) -c main.cpp -o main.o


tellerqueue.o: eventqueue.o
	g++ $(CFLAGS) -c TellerQueue.cpp -o tellerqueue.o


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
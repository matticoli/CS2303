## Program summary
This program simulates the serving of customers at a bank using a shared queue
for all tellers, and then using an individual queue for each teller.

the implementation in /customQueueImplementation utilizes custom queue and
priority queue implementations (EventQueue and SortedEventQueue classes)

The implementation in /stdlinQueueImplementation utilizes the standard library
queue and priority queue data structures while maintaining the class structure
of the original program

##### Execution Progression
The main function calls runSim() with the given command line arguments, which in
turn initializes the necessary Object model and runs the simulation. The simulation
will be generated and run twice with the given parameters, once using a shared queue
and once using separate queues for each teller.

## Compiling and Running
From within the source directory, compile and run using the following commands:
  ```
  make all
  ./qSim [#customers] [#tellers] [simulationTime] [averageServiceTime] <seed>
      #customer number of customers
      #tellers number of tellers
      simulationTime duration of simulation in minutes (not realtime)
      averageServiceTime averate serving time per customer (in minutes)
  ```

Alternatively, the directory can be imported as a makefile project into eclipse.
After importing, the project can be built with `ctrl+b` and run with `ctrl+f11`
(or with the corresponding `build` and `run` buttons on the toolbar)

## Development issues
The most difficult part of developing this program was transferring the knowledge
of Java and Object Oriented programming I had to work in C++. While the underlying
design concepts are consistent, many of the implementation details vary
not only syntactically, but in the structure of certain language constructs (e.g.
virtual methods and operator overloading in place of using the instanceof operator
or the Comparable interface in Java). When implementing the standard library version
of the program, it took some research to figure out how to get the priority queue
to work correctly on a custom object, although the operator overloading functionality
is interesting and I actually like it better than Java's method-based approach to
object comparison. It allows objects to be used as naturally as primitives.

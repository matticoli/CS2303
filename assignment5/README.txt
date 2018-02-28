## Program summary
This program simulates a NxN grid of Organisms that will act in different ways. Ants
will move to empty adjecent cells, duplicating into an adjecent cell after every 3
moves. Doodlebugs will eat adjecent ants, move into empty cells, breed every 8 turns
or die if they do not eat after 3 moves.



##### Execution Progression
The main function creates an instance of the Grid class and puts Ants and Doodlebugs
in it based on the command line parameters. It then processes the move conditions
for each organism in the grid until a termination condition is met.

## Compiling and Running
From within the source directory, compile and run using the following commands:
  ```
  make all
./PA5 gridSize #doodlebugs #ants #time_steps seed pause
    gridSize - Side length of grid
    #doodleBugs - Number of Doodlebugs at start
    #ants - Number of ants at start
    #time_steps Max number of time steps
    seed - Random number generator seed
    pause - Whether or not to pause and print after each round
  ```
If no parameters are specified, the program will run with the following default parameters
```
./PA5 20 5 100 1000
```

Alternatively, the directory can be imported as a makefile project into eclipse.
After importing, the project can be built with `ctrl+b` and run with `ctrl+f11`
(or with the corresponding `build` and `run` buttons on the toolbar)

## Development issues
This project was very easy in principle and strongly resembles the basic functionality
of GridWorld from the AP Computer Science curriculum. The most difficult part was figuring
out how to structure the class hierarchy and the visibility for the inheritance. The primary
obstacle that I ran into was largely due to being unfamiliar with C++'s standard library.
In Grid::moveAll() - I was originally using a vector instead of a queue and had not realized
that the push_back method behaves differently from the insert method in that it will extend
the size of the vector by 1, leaving any existing null pointers in the vector instead of
inserting objects into the allocated space. This issue carried over into the methods
to get adjacent cells since selecting a random item from the vector to return could result in
a nullptr, leading to seg faults in areas of the code that assumed the nullptr checks
within the methods to get a cell were sufficient.
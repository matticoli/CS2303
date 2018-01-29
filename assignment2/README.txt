## Program summary
This program simulates Conway's game of life within a finite grid.
##### Execution Progression
Command line arguments are passed to the main function, which instantiates the
necessary variables to keep track of the game state and calls several helper
functions to progress the simulation, optionally pausing/printing as requested.

## Running
From within the source directory, compile and run using the following commands:
  ```
  make all
  ./life rows cols generations inputFile [print] [pause]
  ```
- _rows_: Number of rows in simulation grid
- _cols_: Number of columns in simulation grid
- _generations_: Max number of generations to simulate
- _inputFile_: Text file with starting configuration (x for live, o for empty)
  - example:
    ```
    xoxx
    ox
    ```
- _print_: `y` or `n` whether to print out every generation
- _pause_: `y` or `n` whether to pause between every generation

## Development issues
The most difficult part of this assignment was loading the data from the file
into a useable grid. C's file management system is very bare-bones, and there is
no easy way to obtain diagnostics on a text file (such as dimensions) without
iterating through it line-by-line or char-by-char. There were multiple considerations
when doing this, particularly the orientation (how to interpret columns/rows, which
dimension is x or y) and the bounds of the array, and how to make sure the bounds
of the file work with this. This is particularly nasty because out-of-bounds errors,
and certain string processing errors will crash the program providing no useful information
past the wonderful "Segmentation fault" message. Without knowledge of `gdb` or IDE-based
debug tools, it is rather painful to track down the source of the seg faults without
bulk-commenting out chunks of code and tracing/guessing.

After resolving this initial problem however, the array processing involved with
the logic portion of the assignment proved relatively straightforward.

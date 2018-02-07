## Program summary
This program defines a structure for storing employee data and implements/tests
multiple operations on arrays of employees

##### Execution Progression
The main function calls each of the functions in mystruct.c to generate several
custom and randomized employees. It then generates arrays of random employees
and performs each of the copy procedures, printing out the corresponding memory
locations and data to show that they function as intended.

## Compiling and Running
From within the source directory, compile and run using the following commands:
  ```
  make all
  ./structest
  ```

Alternatively, the directory can be imported as a makefile project into eclipse.
After importing, the project can be built with `ctrl+b` and run with `ctrl+f11`
(or with the corresponding `build` and `run` buttons on the toolbar)

## Development issues
The most difficult part of developing this program was ensuring that the data
being moved around was done so in a manner that corresponds to the indended functionality.
For example, when shallow-copying an array of employees, the memory locations of the
actual employee structs needed to match in the original and duplicate arrays. Similarly,
for the deep copy, the memory locations needed to differ but the data itself needed to
remain consistent. It was also important to ensure that the correct amount of memory
was allocated for these copies. i.e. a shallow copy only requires enough memory for the
array of pointers, but the deep copy requires enough memory to hold the entire struct
adjecent to each index. Another obstacle was ensuring that there were no memory leaks during
the execution of the program. Correctly freeing an array of structs required some
insight into how the memory is allocated.

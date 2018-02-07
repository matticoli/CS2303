## Program summary
This program contains equivalent implementations of several string.h functions

##### Execution Progression
The main function calls each of the re-implemented string methods and runs tests
to verify that they function the same as the equivalent functions in string.h

## Compiling and Running
From within the source directory, compile and run using the following commands:
  ```
  make all
  ./ctest
  ```

Alternatively, the directory can be imported as a makefile project into eclipse.
After importing, the project can be built with `ctrl+b` and run with `ctrl+f11`
(or with the corresponding `build` and `run` buttons on the toolbar)

## Development issues
The most difficult part of developing this program was ensuring that the functionality
of the duplicate functions exactly matched those of the corresponding built-in functions.
This proved challenging since the test cases had to be tailored based on the restrictions
of the built in functions, and a few of the omitted test cases had resulted in Segmentation
faults that proved to be features of the original functions, and not bugs unique
to the custom implementation.

/* Game of Life
 * @author CS2303 Staff
 * @author Mikel Matticoli
 */

#include <stdio.h>
#include <stdlib.h>
#include "twoD.h"

// Function declarations (See definitions for docstrings)
int getAdjecentLifeCount(char **grid, int rows, int cols, int x, int y);
void playOne (unsigned int rows, unsigned int columns, char **old, char **new);
int loadStartGrid(FILE *input, char **dest, int rows, int columns);


/** Main function.
 * @param argc Number of words on the command line.
 * @param argv Array of pointers to character strings containing the
 *    words on the command line.
 * @return 0 if success, 1 if invalid command line or unable to open file.
 *
 */
int main(int argc, char **argv) {
	printf("============\nGame of Life\n============\n");

	char *inputFileName; // Name of file containing initial grid
	FILE *input; // Stream descriptor for file containing initial grid
	int rows; // Number of rows in the grid
	int columns; // Number of columns in the grid
	int gens; // Number of generations to produce
	int doPrint = 0; // 1 if user wants to print each generation, 0 if not
	int doPause = 0; // 1 if user wants to pause after each generation, 0 if not
	char **gridA, **gridB, **gridC; // A 2D array to hold the pattern

	// See if there are the right number of arguments on the command line
	if ((argc < 5) || (argc > 7)) {
		// If not, tell the user what to enter.
		printf("Usage:\n");
		printf("  ./life rows columns generations inputFile [print] [pause]\n");
		return EXIT_FAILURE;
	}

	/* Save the command-line arguments.
	   Also check if print and/or pause arguments were entered,
	   and if so, what they were.
	*/
	switch(argc) {
		case 7:
			// Set doPause to 1 if y entered, else 0
			doPause = argv[6][0] == 'y';
		case 6:
			// Set doPrint to 1 if y entered, else 0
			doPrint = argv[5][0] == 'y';
		default:
			rows = atoi(argv[1]); // Convert from character string to integer.
			columns = atoi(argv[2]);
			gens = atoi(argv[3]);
			inputFileName = argv[4];
	}

	// If generations input is zero, negative, or invalid
	if(gens <= 0) {
		printf("Nothing to do - generations argument must be >= 0\n");
		return EXIT_FAILURE;
	}

	// Open the input file (in read mode)
	input = fopen(inputFileName, "r");
	if (!input) {
		printf("Unable to open input file: %s\n", inputFileName);
		return EXIT_FAILURE;
	}

	// Initialize the 2D arrays for current, previous, and pre-previous gens
	gridA = make2Dchar(rows, columns);
	gridB = make2Dchar(rows, columns);
	gridC = make2Dchar(rows, columns);

	// Load the starting grid from input file into 2D char array
	if(!loadStartGrid(input, gridA, rows, columns)) {
		// If it doesn't load successfully, throw an error
		// (The function has already printed out an error message)
		return EXIT_FAILURE;
	}

	// Print the start state
	printf("Start:\n");
	print2Dchar(gridA, rows, columns);

	// Run simulation
	for(int gen = 0; gen < gens; gen++) {
		// Remove pre-previous grid from memory
		free2Dchar(gridC, rows);
		// Shift the current and previous back, and init new current grid
		gridC = gridB;
		gridB = gridA;
		gridA = make2Dchar(rows, columns);
		// Update gridA (new current) based on gridB (previous)
		playOne(rows, columns, gridB, gridA);
		// If doPrint arg was 'y'
		if(doPrint || gen == gens-1) {
			// Print out the current generation
			printf("\nGen %d:\n", gen + 1);
			print2Dchar(gridA, rows, columns);
		}
		// If current matches previous (steady state)
		if(match2Dchar(gridA, gridB, rows, columns)) {
			// Print out the final generation if it hasn't been already
			if(!doPrint && gen < gens - 1) {
				printf("\nGen %d:\n", gen + 1);
				print2Dchar(gridA, rows, columns);
			}
			// Print result and terminate
			printf("Reached steady state after %d generations\n", gen + 1);
			return EXIT_SUCCESS;
		// If current matches pre-previous (oscilation state)
		} else if(match2Dchar(gridA, gridC, rows, columns)) {
			// Print out the final generation if it hasn't been already
			if(!doPrint && gen < gens - 1) {
				printf("\nGen %d:\n", gen + 1);
				print2Dchar(gridA, rows, columns);
			}
			// Print result and terminate
			printf("Reached oscilation state after %d generations\n", gen + 1);
			return EXIT_SUCCESS;
		}

		// If doPause arg was 'y', wait for user input before continuing
		if(doPause) {
			// If pausing but not printing
			if(!doPrint) {
				// Print out gen number so the program doesn't look frozen
				printf("\nGen %d:\n", gen + 1);
			}
			// Wait for user input
			getchar();
		}
	}
	// Whoopee we made it
	return EXIT_SUCCESS;
}

/*!
   Loads a starting grid from the given input file into a char array
   @param input The input file
   @param dest The char array to load the file into
	 				**Must be of size rows x columns
					**Will be overwritten
	 @param rows Number of rows in array (file must have smaller/equal dimensions)
	 @param columns Number of columns in array (file must have smaller/equal dimensions)
   @return 1 if loaded successfully, else 0
*/
int loadStartGrid(FILE *input, char **dest, int rows, int columns) {
	char **init = make2Dchar(rows, columns); // Initial char array to load file into
	int x = 0, // Current row index in array
			y = 0,// Current column index in array
			yMax = 0;// Highest column index so far (for centering)
	char c = ' ';// char buffer for reading from file
	/* Invariants:
		- Pre: next char in input file buffer is newline, 'x', other char, or EOF
		- Post: char from file has been added to corresponding location in init[][]
		or position indeces have been updated or file buffer reached EOF
		or input dimensions exceed dimension args, program will error and terminate
	*/
	while(1) {
		// Get the next char from the file
		c = fgetc(input);
		// If we've hit the end of the file
		if(c == EOF) {
			// break out of the loop
			break;
		// If we've hit a newline
		} else if(c == '\n') {
			// Update max column index if applicable
			yMax = (y > yMax) ? y : yMax;
			// Move down a row and go back to the first column
			x += 1;
			y = 0;
			// Done with this iteration of the loop, start reading in next line of file
			continue;
		// If the input file state is taller or wider than the argumented dimensions
		} else if (y + 1 > columns || x + 1 > rows) {
			// Print error and return failure code so main() knows to exit with failure
			printf("Invalid input: Given dimensions %dx%d are not large enough to accomodate element at location %d,%d\n", rows, columns, x + 1, y + 1);
			return 0;
		}
		// If none of the above conditions are met, put the char in the array
		init[x][y] = c;
		// NOTE: This can result in non-'x' or 'o' chars ending up in the array if
		// input is malformed. This is handled below

		// Next column
		y++;
	}

	/* And now to center it: */

	// Calculate offsets to center input state in grid of argumented dimensions
	int xOffset = (rows - (x - 1)) /2;// row offset
	int yOffset = (columns - yMax) /2;// column offset

	/* Invariants: (nested loop)
		- Pre: x and y correspond to position in destination array, which will be offset
		from the source array by >=0 locations in the x and/or y directions
		- Post: char at index x,y in destination has been initialized to 'x' if there's
		a corresponding organism at the offset location in the source array, else 'o'
	*/
	for(x = 0; x < rows; x++) {
		for(y = 0; y < columns; y++) {
			// If pos x,y falls within bounds of offset array
			if(x - xOffset >= 0 && y - yOffset >=0) {
				// Set the corresponding value in the destination array
				char c = init[x - xOffset][y - yOffset];
				dest[x][y] = (c=='x') ? 'x' : 'o';
				// This ensures that only 'x' or 'o' will appear in the destination array
				// All non-x characters from input file are treated as 'o'
			} else {
				// Fill empty space created by offset
				dest[x][y] = 'o';
			}
		}
	}
	// Clean up the input arr now that it has been centered in the destination arr
	free2Dchar(init, rows);

	// Success!
	return 1;
}

/*!
   Simulate one round of game of life
   @param rows Number of rows in grid
   @param columns Number of columns in grid
   @param old previous generation
	 @param new current generation (being generated)
*/
void playOne (unsigned int rows, unsigned int columns, char **old, char **new) {
	/* Invariants:
		Pre - old and new are 2D char arrays of size rows x columns, old represents
		the previous generation and new is initialized blank,
		x, y, corresponds to a cell in both grids
		Post - Corresponding cell in new has been set based on old, reflecting game rules
	*/
	for(int x = 0; x < rows; x++) {
		for(int y = 0; y < columns; y++) {
			// Get count of adjecent live cells
			int neighbors = getAdjecentLifeCount(old, rows, columns, x, y);
			// If currently selected cell is a live cell
			if(old[x][y] == 'x') {
				switch(neighbors) {
					case 2:
					case 3:
						// Survival
						new[x][y] = 'x';
						break;
					case 0:
					case 1:
					case 4:
					case 5:
					case 6:
					case 7:
					case 8:
					default:
						// DEATH!
						new[x][y] = 'o';
						break;
				}
			// Else, current cell is empty and will either
			// birth (if it has neighbores) or remain empty
			} else if(neighbors == 3) {
				// Birth
				new[x][y] = 'x';
			} else {
				// Empty
				new[x][y] = 'o';
			}
		}
	}
}  // playOne

/*!
   Counts adjecent cells of a given cell
   @param grid the current game state
   @param rows Number of rows in grid
	 @param cols Numbe rof columns in grid
	 @param x Row index of current cell in grid
	 @param y Column index of current cell in grid
   @return Return number of living cells adjecent to current cell
*/
int getAdjecentLifeCount(char **grid, int rows, int cols, int x, int y) {
	// Define simple function for bounds check to improve readability
	// Note: annotations omitted to prevent malformed docs
	/*
	   Determines whether position x,y is within bounds of grid
	   param x x-pos passed to parent function
	   param y y-pos passed to parent function
	   return Return 1 if in bounds, else 0
	*/
	int inBounds(int x, int y) {
		return (x >= 0 && y >= 0  && x < rows && y < cols);
	}
	int count = 0; // Count of adjecent live cells
	// Each of these adds 1 (for live cell) or 0 (for empty/ out of bounds) to count
	// for an adjecent cell position
	count += inBounds(x-1, y-1) && grid[x-1][y-1] == 'x';
	count += inBounds(x-1, y) && grid[x-1][y] == 'x';
	count += inBounds(x-1, y+1) && grid[x-1][y+1] == 'x';
	count += inBounds(x, y-1) && grid[x][y-1] == 'x';
	count += inBounds(x, y+1) && grid[x][y+1] == 'x';
	count += inBounds(x+1, y-1) && grid[x+1][y-1] == 'x';
	count += inBounds(x+1, y) && grid[x+1][y] == 'x';
	count += inBounds(x+1, y+1) && grid[x+1][y+1] == 'x';

	return count;
} // getAdjecentLifeCount

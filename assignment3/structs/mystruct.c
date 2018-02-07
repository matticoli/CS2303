/** mystruct.c
 * @author Mike Ciaraldi
*/


#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "mystruct.h"

#define THIS_YR 2018 // Macro for current year (max value for random years)

// Helper function prototypes
int randInt(int max);
char *randStr(int length);
char randChar();

/** Allocates an Employee struct and fills in its fields
 * @param birth Year the emploee was born.
 * @param start Year the employee started with the company.
 * @param name String containing employee's name
 * @return Pointer to Employee struct, newly allocated from the heap.
 */
struct Employee* makeEmployee(int birth, int start, const char *name) {
	// Alloc memory for new employee
	struct Employee *e = malloc(sizeof(struct Employee));
	// Set props from parameters
	e -> birth_year = birth;
	e -> start_year = start;
	strcpy(e -> name, name);
	return e; // Return pointer to new employee
}

/** Prints out information on a given Employee
 * @param e Pointer to employee to be printed
 */
void printEmployee(struct Employee *e) {
	// Print location and fields for employee in one line
	printf("%p\t%s\tBorn: %d\tStarted: %d\n",
			e, e -> name, e -> birth_year, e -> start_year);
}

/** Generates random Employee
 *	@return pointer to new employee
 */
struct Employee* randEmployee() {
	// Calls helper functions and passes random data into makeEmployee
	return makeEmployee(randInt(THIS_YR), randInt(THIS_YR), randStr(10));
}

/** Generates array of random employees of given length
 * @param count Length of random Employee array
 * @return array of random Employees
 */
struct Employee** randCompany(int count) {
	// Allocate new array of employees
	struct Employee** arr = malloc(sizeof(struct Employee) * count);

	// If unable to allocate memory, return null ptr
	if(arr == NULL) return NULL;

	// Iterate through each employee in array, and set the employee pointer
	// to the location returned by randEmployee call
	for(int i = 0; i < count; i++) {
		arr[i] = randEmployee();
	}
	// return the array
	return arr;
}

/** Prints out an array of Employees
 * @param company Employee array to print
 * @param count length of Employee array
 */
void printCompany(struct Employee **company, int count) {
	// Print out location of company array
	printf("Company %p\n", company);
	// Iterate through each employee in company array and print
	for(int i = 0; i < count; i++) {
		printEmployee(company[i]);
	}
}

/** Shallow copies an array of Employees
 * @param company Employee array to print
 * @param count length of Employee array
 * @return shallow copy of company array
 */
struct Employee **shallowCopyCompany(struct Employee **company, int count) {
	// Allocate memory for an array of pointers
	// NOTE: This does not leave empty space for the full struct at each index!
	struct Employee **dupe = malloc(sizeof(struct Employee *) * count);
	// Copy each pointer over
	for(int i = 0; i < count; i++) {
		dupe[i] = company[i];
	}
	// Return the new array
	return dupe;
}

/** Deep copies an array of Employees
 * @param company Employee array to print
 * @param count length of Employee array
 * @return deep copy of company array
 */
struct Employee **deepCopyCompany(struct Employee **company, int count) {
	// Allocate memory for an array of Employees
	// NOTE: This MUST leave empty space for the full struct at each index!
	struct Employee **dupe = malloc(sizeof(struct Employee *) * count);
	// For each Employee
	for(int i = 0; i < count; i++) {
		// Make a new employee with data from old one and put it in the dupe array
		struct Employee *e = company[i];
		dupe[i] = makeEmployee(e->birth_year, e->start_year, e->name);
	}
	// Return new array
	return dupe;
}

/** Frees memory from Employee array
 * @param company Employee array to print
 * @param count length of Employee array
 */
void fireEveryone(struct Employee **company, int count) {
	// For each employee in the company array
	for(int i = 0; i < count; i++) {
		// Free the memory held by the struct
		free(company[i]);
	}
	// Free the memory held by the array of pointers to structs
	free(company);
}

/** Returns a random int between 0 and max (inclusive)
 * @param max The max value of the random int (inclusive)
 * @return Random int between 0 and max
 */
int randInt(int max) {
	// Generates rand int bt 0 and max (inclusive)
	return rand() % (max + 1);
}

/** Returns a random string of given length
 * @param length length of random string to generate
 * @return Random string of length length
 */
char *randStr(int length) {
	// Create string buffer for random string
	char *s = malloc(sizeof(char) * (length + 1));
	// If malloc fails, return null ptr
	if(s == NULL) return NULL;
	// Add (length) random characters to string buffer
	for(char *c = s; c - s < length; c++) {
		*c = randChar();
	}
	// Append null terminator
	*(s + length) = '\0';
	return s;
}

/** Returns a random char between a and z (lowercase, inclusive)
 * @return Random character between a and z (lowercase, inclusive)
 */
char randChar() {
	// Generates random ascii value corresponding to a-z and casts to char
	return (char)(rand() % ('z' - 'a') + 'a');
}

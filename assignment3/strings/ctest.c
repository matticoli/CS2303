#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// string.h covers the C-style string functions.
#include "mystring.h"

/** ctest.c
 * Program to demonstrate character arrays and
 * dynamically-allocated memory.
 * @author Mike Ciaraldi
 * Add your own @author line below.
 * @author Mikel Matticoli
 */

const int MAX_CHARS = 20; // Maximum number of characters in array

// Local Function Prototypes
void testLen1(char *s);
void testLen2(char *s);
void testStrCpy(char *cpyTo, char *cpyFrom);
void testStrCat(char *cpyTo, char *cpyFrom);
void testStrnCpy(char *cpyTo, char *cpyFrom, size_t n);
void testStrnCat(char *cpyTo, char *cpyFrom, size_t n);
void testStrndup(char *cpyFrom, size_t n);

int main()
{
	char a1[MAX_CHARS + 1]; // Character array--initially empty
	char a2[] = "Hello"; // Character array--unsized but initialized
	char a3[MAX_CHARS + 1]; // Character array--we will underfill it
	char* p1 = "Hello"; // Pointer to constant string
	char* p2 = NULL;           // Will be a pointer to dynamically-allocated string
	char* p3 = "Hi"; // Pointer to another constant string
	int copy_limit;     // Maximum characters to copy.

	strcpy(a3, "Hello, one more time."); // Initialize underfilled character array

	/* Print the pointers.
     Note: this example prints
     the values of the pointers themselves, not the targets.
	 */
	printf("Initial state:\n");
	printf("Pointers: a1 = %p, a2 = %p, a3 = %p\n", a1, a2, a3);
	printf("          p1 = %p p2 = %p\n", p1, p2);

	strcpy(a1, p3); // Initialize character array

	printf("a1 = %s\n", a1);
	printf("a2 = %s\n", a2);
	printf("a3 = %s\n", a3);

	// Note that strlen() returns size_t, which is typedef'd to
	//   unsigned long, so we need to print it with %ld instead of just %d.
	printf("For string /%s/, strlen() returns %ld\n", p1, strlen(p1));
	//printf("For string /%s/, mystrlen1() returns %ld\n", p1, mystrlen1(p1));

	// Duplicate a string, using strdup(), then print
	printf("\nBefore calling strdup(), pointer a2 = %p, contents = %s\n", a2, a2);
	p2 = strdup(a2);
	printf("Duplicated string: \n");
	printf("Pointer p2 = %p, contents = %s\n", p2, p2);

	// Duplicate a string, using my function, then print
	printf("\nBefore calling mystrdup1(), pointer a2 = %p, contents = %s\n", a2, a2);
	p2 = mystrdup1(a2);
	printf("Duplicated string: \n");
	printf("Pointer p2 = %p, contents = %s\n", p2, p2);


	// Be sure there is a terminator character in the last element of the array
	a1[MAX_CHARS] = '\0';

	// Concatenate two character arrays, then print.
	strcpy(a1, p3); // Reset character array
	strcat(a1, a2);
	printf("Using strcat() to concatenate a2 to the end of a1\n");
	printf("a1 = %s\n", a1);

	// Concatenate two character arrays safely, then print.
	strcpy(a1, p3); // Reset character array
	a1[MAX_CHARS] = 'A'; // Remove terminator, to prove strncat() puts it back in.
	copy_limit = MAX_CHARS - strlen(a1); // How much space is left?
	printf("Using strncat() to concatenate to the end of a1, with copy_limit = %d\n",
			copy_limit);
	if (copy_limit > 0) strncat(a1, a3, copy_limit);
	printf("a1 = %s\n", a1);

	printf("\nTesting mystrlen1\n================");
	// Calculate length of string using mystrlen1
	testLen1(a1);
	testLen1(a2);
	testLen1(a3);
	testLen1(p1);
	testLen1(p2);
	testLen1(p3);

	printf("\nTesting mystrlen2\n================");
	// Calculate length of string using mystrlen1
	testLen2(a1);
	testLen2(a2);
	testLen2(a3);
	testLen2(p1);
	testLen2(p2);
	testLen2(p3);

	/*
		NOTE: All destination buffers are sized sufficiently to avoid seg faults.
	 	All omitted cases also resulted in seg faults on string.h equivalents
	*/

	// Test mystrcpy
	printf("\nTesting mystrcpy\n================\n");
	char *cpyFrom = p1; //"Hello"
	char *cpyFrom2 = "Goodbye";
	printf("\nDest buffer same size as source string");
	char *cpyTo = malloc(sizeof(char) * 6); // chars in cpyFrom including \0
	testStrCpy(cpyTo, cpyFrom);
	printf("\nDest buffer longer than source string");
	char *cpyTo2 = malloc(sizeof(char) * 20); // buffer is larger than source
	testStrCpy(cpyTo2, cpyFrom);
	testStrCpy(cpyTo2, cpyFrom2);

	// Test mystrcat
	printf("\nTesting mystrcat\n================\n");
	testStrCat(cpyTo2, cpyFrom);
	testStrCat(cpyTo2, cpyFrom2);

	// Test mystrncpy
	printf("\nTesting mystrncpy\n================\n");
	printf("\nn = 5\nlength of src == n");
	free(cpyTo);
	cpyTo = malloc(sizeof(char) * 6); // chars in cpyFrom including \0
	testStrnCpy(cpyTo, cpyFrom, 5);

	printf("\nlength of src > n");
	free(cpyTo2);
	cpyTo2 = malloc(sizeof(char) * 20);
	testStrnCpy(cpyTo2, cpyFrom2, 5);

	printf("\nlength of src < n");
	testStrnCpy(cpyTo2, p3, 5);

	// Test mystrncat
	printf("\nTesting mystrncat\n================\n");
	printf("\nn = 5\nlength of src == n");
	testStrnCat(cpyTo2, cpyFrom, 5);

	printf("\nlength of src > n");
	testStrnCat(cpyTo2, cpyFrom2, 5);

	printf("\nlength of src < n");
	testStrnCat(cpyTo2, p3, 5);

	// Testing mystrndup
	printf("\nTesting mystrndup\n================\n");
	printf("\nn = 5\nlength of src == n");
	testStrndup(cpyFrom, 5);

	printf("\nlength of src > n");
	testStrndup(cpyFrom2, 5);

	printf("\nlength of src < n");
	testStrndup(p3, 5);
	return 0;
}

void testLen1(char *s) {
	// Print string and length from system and custom functions
	printf("\nLength of string \"%s\" is %ld\n", s, mystrlen1(s));
	printf("Test %s\n",
			(strlen(s) == mystrlen1(s) ?// If custom and system calls match
			"Passed" : // Print "Passeed"
			"Failed"));// Else print "Failed"
}

void testLen2(char *s) {
	// Print string and length from system and custom functions
	printf("\nLength of string \"%s\" is %ld\n", s, mystrlen2(s));
	printf("Test %s\n",
			(strlen(s) == mystrlen2(s) ?// If custom and system calls match
			"Passed" : // Print "Passeed"
			"Failed"));// Else print "Failed"
}

void testStrCpy(char *cpyTo, char *cpyFrom) {
	printf("\nSource str: \"%s\"\t Dest str before: \"%s\"\t", cpyFrom, cpyTo);
	mystrcpy(cpyTo, cpyFrom);
	printf("Dest str after: \"%s\"\n", cpyTo);
}

void testStrCat(char *cpyTo, char *cpyFrom) {
	printf("\nSource str: \"%s\"\t Dest str before: \"%s\"\t", cpyFrom, cpyTo);
	mystrcat(cpyTo, cpyFrom);
	printf("Dest str after: \"%s\"\n", cpyTo);
}


void testStrnCpy(char *cpyTo, char *cpyFrom, size_t n) {
	printf("\nSource str: \"%s\"\t Dest str before: \"%s\"\t", cpyFrom, cpyTo);
	mystrncpy(cpyTo, cpyFrom, n);
	printf("Dest str after: \"%s\"\n", cpyTo);
}

void testStrnCat(char *cpyTo, char *cpyFrom, size_t n) {
	printf("\nSource str: \"%s\"\t Dest str before: \"%s\"\t", cpyFrom, cpyTo);
	mystrncat(cpyTo, cpyFrom, n);
	printf("Dest str after: \"%s\"\n", cpyTo);
}

void testStrndup(char *cpyFrom, size_t n) {
	printf("\nSource str [%p]: \"%s\"\t", cpyFrom, cpyFrom);
	char *cpyTo = mystrndup(cpyFrom, n);
	printf("Dest str [%p]: \"%s\"\n", cpyTo, cpyTo);
}

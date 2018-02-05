/** mystring.c
 * @author Mike Ciaraldi
 * My own versions of some of the C-style string functions
 * @author Mikel Matticoli
 * Extended for CS2303 Assignment 3
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
// Have to #include stdlib.h because it is needed to use malloc()
#include "mystring.h"

/** Duplicates a C-style string.
 @param src Pointer to string to be copied
 @return Pointer to freshly-allocated string containing a duplicate of src
         or null if no memory is available
*/
char* mystrdup1(const char* src) {
  int length; // Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  length = mystrlen1(src) + 1;  // Leave space for the terminator
  newstr = (char*) malloc(length); // Must cast!

  // If no memory was available, return null pointer immediately
  if (newstr == 0) return (char *) 0;

  // Otherwise, copy the string and return pointer to new string
  strcpy(newstr, src);
  return newstr;
}

/** Duplicates a C-style string.
 @param src Pointer to string to be copied
 @return Pointer to freshly-allocated string containing a duplicate of src
         or null if no memory is available
*/
char* mystrdup2(const char* src) {
  int length; // Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  length = mystrlen2(src) + 1;  // Leave space for the terminator
  newstr = (char*) malloc(length); // Must cast!

  // If no memory was available, return null pointer immediately
  if (newstr == 0) return (char *) 0;

  // Otherwise, copy the string and return pointer to new string
  strcpy(newstr, src);
  return newstr;
}

/** Calculates the length of the string s, excluding the terminating null byte ('\0')
  @param s Pointer to string to get length of
  @return size_t number of bytes in string s
  */
size_t mystrlen1(const char* s) {
  size_t len;
  for(len = 0; s[len] != '\0'; len++);
  return len;
}

/** Calculates the length of the string s, excluding the terminating null byte ('\0')
  @param s Pointer to string to get length of
  @return size_t number of bytes in string s
  */
size_t mystrlen2(const char* s) {
  const char *c;
  for(c = s; *c != '\0'; c++);
  return c - s;
}

/** Copies the string pointed to by src, including the terminating null byte ('\0'),
  to the buffer pointed to by dest.  The strings may not over‐lap, and the
  destination string dest must be large enough to receive the copy.  Beware of buffer overruns!
  @param dest Pointer to the string that is being copied to
  @param src Pointer to the string that is being copied from
  @return dest Pointer to destination string
  */
char *mystrcpy(char *dest, const char *src) {
  const char *srcC = src;// Copy of src pointer to be incremented
  char *destC;// Copy of destination pointer to be incremented
  // Copy each character, stopping at the null terminator
  for(destC = dest; *srcC != '\0'; *destC++ = *srcC++);
  *destC = *srcC;// Now copy over the null terminator
  return dest;// Return ptr to start of destination string
}

/** Copies at most n chars of the string pointed to by src, plus a null terminator,
  to the buffer pointed to by dest.  The strings may not over‐lap, and the
  destination string dest must be large enough to receive the copy.  Beware of buffer overruns!
  @param dest Pointer to the string that is being copied to
  @param src Pointer to the string that is being copied from
  @param n Max number of chars from src to copy before null terminating dest string
  @return dest Pointer to destination string
  */
char *mystrncpy(char *dest, const char *src, size_t n) {
  const char *srcC = src;// Copy of src pointer to be incremented
  char *destC;// Copy of destination pointer to be incremented
  // Copy each character, stopping at the null terminator or copy limit (n)
  for(destC = dest; (destC - dest < n) && *srcC != '\0'; *destC++ = *srcC++);
  *destC = '\0';// Now add a null terminator
  return dest;// Return ptr to start of destination string
}

/** Appends the string pointed to by src, including the terminating null byte ('\0'),
  to the string pointed to by dest.  The strings may not over‐lap, and the
  destination string dest must be large enough to receive the copy.  Beware of buffer overruns!
  @param dest Pointer to the string that src is being appended to
  @param src Pointer to the string that is being appended
  @return dest Pointer to destination string
  */
char *mystrcat(char *dest, const char *src) {
  mystrcpy(dest + mystrlen2(dest), src);
  return dest;
}

/** Appends at most n chars of the string pointed to by src, plus a null terminator,
  to the string pointed to by dest.  The strings may not over‐lap, and the
  destination string dest must be large enough to receive the copy.  Beware of buffer overruns!
  @param dest Pointer to the string that src is being appended to
  @param src Pointer to the string that is being appended
  @param n Max number of chars from src to append before null terminating dest string
  @return dest Pointer to destination string
  */
char *mystrncat(char *dest, const char *src, size_t n) {
  mystrncpy(dest + mystrlen2(dest), src, n);
  return dest;
}

/** Duplicates a C-style string.
 @param src Pointer to string to be copied
 @return Pointer to freshly-allocated string containing a duplicate of src
         or null if no memory is available
*/
char* mystrndup(const char* src, size_t n) {
  char* newstr; // Pointer to memory which will hold new string

  newstr = (char*) malloc(sizeof(char) * (n + 1)); // Must cast!

  // If no memory was available, return null pointer immediately
  if (newstr == 0) return (char *) NULL;

  // Otherwise, copy the string and return pointer to new string
  strncpy(newstr, src, n);
  return newstr;
}

/** mystring.h
 * @author Mike Ciaraldi
 * My own versions of some of the C-style string functions
*/

// Function prototype(s):
char* mystrdup1(const char* src);
char* mystrndup(const char* src, size_t n);
size_t mystrlen1(const char* s);
size_t mystrlen2(const char* s);
char *mystrcpy(char *dest, const char *src);
char *mystrcat(char *dest, const char *src);
char *mystrncpy(char *dest, const char *src, size_t n);
char *mystrncat(char *dest, const char *src, size_t n);

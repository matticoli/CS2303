/** mystruct.h
 * @author Mike Ciaraldi
 * Sample structs
*/

// Struct definition:

// Maximum number of characters in an employee name
#define MAX_NAME (99)

struct Employee {
	int birth_year; // Year the employee was born
	int start_year; // When employe started with the company.
	char name[MAX_NAME + 1];
};

// Function prototype(s):
struct Employee *makeEmployee(int birth, int start, const char* name);
void printEmployee(struct Employee *e);
struct Employee* randEmployee();
struct Employee** randCompany(int count);
void printCompany(struct Employee **company, int size);
void fireEveryone(struct Employee **company, int count);
struct Employee **shallowCopyCompany(struct Employee **company, int count);
struct Employee **deepCopyCompany(struct Employee **company, int count);

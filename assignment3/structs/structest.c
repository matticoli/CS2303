#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mystruct.h"

int main(int atgc, char *argv[]) {
	// Randomize the seed for rand()
	srand(time(0));

	// Generate some employees using makeEmployee
	printf("Custom Employees\n");
	struct Employee *e, *f, *g;
	e = makeEmployee(1952, 1999, "Mike Ciaraldi");
	f = makeEmployee(2001, 2018,
		"Someobnoxiouslylongfirstname Someobnoxiouslylonglastname");
	g = makeEmployee(0, 23, "Very Old");

	printEmployee(e);
	printEmployee(f);
	printEmployee(g);

	// Generate some random employees
	printf("\nRandom Employees\n");
	printEmployee(randEmployee());
	printEmployee(randEmployee());
	printEmployee(randEmployee());

	// Generate random company
	printf("\nRandom Company\n");
	#define COMPANY_SIZE 10
	struct Employee **company = randCompany(COMPANY_SIZE);
	printCompany(company, COMPANY_SIZE);

	// Shallow copy
	printf("\nShallow Copy\n");
	struct Employee **dupe = shallowCopyCompany(company, COMPANY_SIZE);
	printCompany(dupe, COMPANY_SIZE);

	// Deep copy
	printf("\nDeep Copy\n");
	struct Employee **deepDupe = deepCopyCompany(company, COMPANY_SIZE);
	printCompany(deepDupe, COMPANY_SIZE);

	// Free memory
	fireEveryone(company, COMPANY_SIZE);
	free(dupe);
	printf("\nAnd Now They're Gone\n");

	return 0;
}

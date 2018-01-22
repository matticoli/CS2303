/*
 * helloworld.c  -- Mikel Matticoli
 */

#include <stdio.h>

/**
  *  Get the start weekday of a given year (0=Sunday 6=Saturday)
  * @param year The year to get the first day of
  * @return An int, 0-6, corresponding to the starting day of the given year
*/
int getYearStartDay(int year);

/**
  *  Prints a formatted calendar for the given year starting on the
  * given weekday (0-6 for Sunday-Saturday)
  * @param year The year of the calendar to print
  * @param startDay The day of the week that the given year starts on
*/
void printCalendar(int year, int startDay);

/**
  *  Prints a formatted calendar for the given month (1-12) of the given
  * starting on the given weekday (0-6 for Sunday-Saturday)
  * @param year The year of the calendar to print
  * @param month The month of the calendar to print
  * @param startDay The day of the week that the given year starts on
  * @param numDays The number of days in the given month
  * @return Returns the first day of the next month
*/
int printMonth(int year, int month, int startDay, int numDays);

/**
  *  Gets the name of a given month
  * @param month The number corresponding to the month (1-12)
  * @return Return string denoting calendar month
*/
char *monthName(int month);

/**
  *  Gets number of days in a given month
  * @param month The month to get the number of days of
  * @param leapYear 1 if leapYear, else 0
  * @return Number of days in the given month
*/
int daysInMonth(int month, int leapYear);

/**
  *  Prompts user for year and prints out formatted calendar
  * @param args command line arguments
  * @return "Return of the function"
*/
int main() {
  int year; // Year inputted by user
  printf("Enter a year: ");
  scanf("%d", &year);
  int startDay = getYearStartDay(year); // Start day of inputted year
  printCalendar(year, startDay);
}

int getYearStartDay(int year) {
    // Zeller's congruence: https://en.wikipedia.org/wiki/Zeller%27s_congruence
     int y, m;
     y = year - (13 / 12);
     m = 1 + (12 * (13 / 12)) - 2;
     return ((1 + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7);
}

void printCalendar(int year, int startDay) {
  int daysThisMonth = 0; // Loop variable used to store number of days in each month
      // Declared here to avoid reallocation
  // Iterate through months
  // Precondition: year=the year to print, startDay=starting weekday of given year
  for(int month = 1; month <= 12; month++) {
    daysThisMonth = daysInMonth(month, ( (year % 4 == 0) && (year % 100 != 0 || (year % 400 == 0)) ));
    startDay = printMonth(year, month, startDay, daysThisMonth);
  }
}

int printMonth(int year, int month, int startDay, int numDays) {
  // Print month/year and weekdays
  printf("\n\r\t%s %d\n  Su  Mo  Tu  We  Th  Fr  Sa\n\r",
      monthName(month), year);
  int currentDayOfMonth = 1; // Keep track of current calendar day
  int currentDayOfWeek = 0; // Keep track of current calendar day

  // Print space for weekdays in previous month
  for(int i = 0; i < startDay; i++) {
    printf("%4s", "");
    currentDayOfWeek++;
  }
  // Cycle through days in each month
  for(int i = 1; i <= numDays; i++) {
    printf("%4d", currentDayOfMonth);
    // If it's a Saturday, start the next week
    if(currentDayOfWeek % 6 == 0 && currentDayOfWeek != 0) {
      currentDayOfWeek = 0;
      printf("\n\r");
    } else {
      currentDayOfWeek++;
    }
    currentDayOfMonth++;
  }
  printf("\n\r");

  return currentDayOfWeek;
}

char *monthName(int month) {
  switch(month) {
    case 1:
      return "January";
    case 2:
      return "February";
    case 3:
      return "March";
    case 4:
      return "April";
    case 5:
      return "May";
    case 6:
      return "June";
    case 7:
      return "July";
    case 8:
      return "August";
    case 9:
      return "September";
    case 10:
      return "October";
    case 11:
      return "November";
    case 12:
      return "December";
    default:
      return ""; // This should never happen
  }
}

int daysInMonth(int month, int leapYear) {
  switch(month) {
    case 1: // January
    case 3: // March
    case 5: // May
    case 7: // July
    case 8: // August
    case 10: // October
    case 12: // December
      return 31;
    case 2: // February
      return leapYear ? 29 : 28;
    case 4: // April
    case 6: // June
    case 9: // September
    case 11: // November
      return 30;
    default:
      return 0; // This should never happen
  }
}

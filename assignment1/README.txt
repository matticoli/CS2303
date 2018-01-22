#Calendar Print

##Program Overview:

This program will prompt the user to input a year, then output a formatted calendar for that year.


##To Run:

From a terminal, navigate to the directory containing PA1.c, then run the following commands:
```
gcc PA1.c -o PA1
./PA1
```


## Development Roadblocks:
The primary roadblocks during development were nuances with data being passed between functions. Design details such as having the `printMonth()` function return the end date to be passed to the subsequent call of `printMonth()` from within `printCalendar()`. The most complex portion of the program was obtaining the first weekday of the year given the year number, but this was facilitated by the mathematical formula provided by Zeller's congruence.

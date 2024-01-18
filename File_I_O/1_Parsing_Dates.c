/*
Complete main() to read dates from input, one date per line. Each date's format must be as follows: March 1, 1990. Any date not following that format is incorrect and 
should be ignored. Use the substring() function to parse the string and extract the date. The input ends with -1 on a line alone. Output each correct date as: 3-1-1990.

Ex: If the input is:

March 1, 1990
April 2 1995
7/15/20
December 13, 2003
-1

then the output is:

3-1-1990
12-13-2003

Use the provided GetMonthAsInt() function to convert a month string to an integer. If the month string is valid, an integer in the range 1 to 12 inclusive is returned, 
otherwise 0 is returned. Ex: GetMonthAsInt("February") returns 2 and GetMonthAsInt("7/15/20") returns 0.
*/
#include <stdio.h>
#include <string.h>

int GetMonthAsInt(char *monthString) {
	int monthInt;

	if (strcmp(monthString, "January") == 0) {
		monthInt = 1;
	}
	else if (strcmp(monthString, "February") == 0) {
		monthInt = 2;
	}
	else if (strcmp(monthString, "March") == 0) {
		monthInt = 3;
	}
	else if (strcmp(monthString, "April") == 0) {
		monthInt = 4;
	}
	else if (strcmp(monthString, "May") == 0) {
		monthInt = 5;
	}
	else if (strcmp(monthString, "June") == 0) {
		monthInt = 6;
	}
	else if (strcmp(monthString, "July") == 0) {
		monthInt = 7;
	}
	else if (strcmp(monthString, "August") == 0) {
		monthInt = 8;
	}
	else if (strcmp(monthString, "September") == 0) {
		monthInt = 9;
	}
	else if (strcmp(monthString, "October") == 0) {
		monthInt = 10;
	}
	else if (strcmp(monthString, "November") == 0) {
		monthInt = 11;
	}
	else if (strcmp(monthString, "December") == 0) {
		monthInt = 12;
	}
	else {
		monthInt = 0;
	}

	return monthInt;
}

int main(void) {

    // TODO: Read dates from input, parse the dates to find the ones
    //       in the correct format, and output in m-d-yyyy format
    char input[50];
    char month[20];
    int day, year;

    int inputDone = 0;
    // Read dates from input until -1 is encountered
    while (!inputDone) {
        fgets(input, 49, stdin);

		if (strcmp(input, "-1") == 0) 
		{
			inputDone = 1;
		}
		else if (sscanf(input, "%s %d, %d", month, &day, &year) == 3)
		{
			printf("%d-%d-%d\n", GetMonthAsInt(month), day, year);
		}
    }
    return 0;
}

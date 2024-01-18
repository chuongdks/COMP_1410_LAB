/*
Write a program that reads movie data from a CSV (comma separated values) file and output the data in a formatted table. The program first reads the name of the CSV file from the user. The program then reads the CSV file and outputs the contents according to the following requirements:

    Each row contains the title, rating, and all showtimes of a unique movie.
    A space is placed before and after each vertical separator ('|') in each row.
    Column 1 displays the movie titles and is left justified with a minimum of 44 characters.
    If the movie title has more than 44 characters, output the first 44 characters only.
    Column 2 displays the movie ratings and is right justified with a minimum of 5 characters.
    Column 3 displays all the showtimes of the same movie, separated by a space.

Each row of the CSV file contains the showtime, title, and rating of a movie. Assume data of the same movie are grouped in consecutive rows.

Hints: Use the fgets() function to read each line of the input text file. When extracting texts between the commas, copy the texts character-by-character until a comma is reached. A string always ends with a null character ('\0').

Ex: If the input of the program is:

movies.csv

and the contents of movies.csv are:

16:40,Wonders of the World,G
20:00,Wonders of the World,G
19:00,Journey to Space ,PG-13
12:45,Buffalo Bill And The Indians or Sitting Bull's History Lesson,PG
15:00,Buffalo Bill And The Indians or Sitting Bull's History Lesson,PG
19:30,Buffalo Bill And The Indians or Sitting Bull's History Lesson,PG
10:00,Adventures of Lewis and Clark,PG-13
14:30,Adventures of Lewis and Clark,PG-13
19:00,Halloween,R

the output of the program is:

Wonders of the World                         |     G | 16:40 20:00
Journey to Space                             | PG-13 | 19:00
Buffalo Bill And The Indians or Sitting Bull |    PG | 12:45 15:00 19:30
Adventures of Lewis and Clark                | PG-13 | 10:00 14:30
Halloween                                    |     R | 19:00

*/
#include <stdio.h>
#include <string.h>

#define MAX_TITLE_LENGTH 44
#define MAX_RATING_LENGTH 5
#define MAX_SHOWTIMES_LENGTH 100

#define MAX_ITEMS 20

int main() {
    char fileName[25];
    scanf("%s", fileName);

    FILE *file = fopen(fileName, "r");
    if (file == NULL) 
    {
        printf("Could not open file %s\n", fileName);
        return -1;
    }

    char str[100] = {'\0'};

    char time[MAX_SHOWTIMES_LENGTH] = {'\0'};
    char title[MAX_TITLE_LENGTH] = {'\0'};
    char rating[MAX_RATING_LENGTH * 4] = {'\0'};

    char currentTime[MAX_SHOWTIMES_LENGTH] = {'\0'};
    char currentTitle[MAX_TITLE_LENGTH] = {'\0'};
    char currentRating[MAX_RATING_LENGTH * 4] = {'\0'};

    // read file line by line --> Assign them to 'time', 'title' and 'rating' then compare 'currentTitle' with the recent 'title' variable being assigned to 
    int count = 0;
    while (fgets(str, sizeof(str), file) != NULL && count < MAX_ITEMS) 
    {
        // remove trailing newline from str
        int length = strlen(str);
        if (str[length-1] == '\n') 
        {
            str[length-1] = '\0';
        }

        // extract fields from str separated by tabs
        char *token = strtok(str, ",");
        strcpy(time, token);
        token = strtok(NULL, ",");
        strncpy(title, token, 44);
        token = strtok(NULL, ",");
        strcpy(rating, token);

        //If 'currentTitle' is not the same as 'title' being assigned to (that means 2 different movie Title) and currentTitle is not empty, 
        //then print out the 'current' info and copy the 'new' movie info to the 'current' movie info variable
        if (strcmp(currentTitle, title) != 0) 
        {
            if (strcmp(currentTitle, "") != 0) 
            {
                printf("%-44s | %5s | %s\n", currentTitle, currentRating, currentTime);
            }
            strcpy(currentTitle, title);
            strcpy(currentRating, rating);
            strcpy(currentTime, time);
        } 
        //If 'currentTitle' the same as 'title' being assigned to then use strcat to add another showtime 'time' variable
        else 
        {
            strcat(currentTime, " ");
            strcat(currentTime, time);
        }

        //increase item count when move to next line
        count++;
    }
    if (strcmp(currentTitle, "") != 0) 
    {
        printf("%-44s | %5s | %s\n", currentTitle, currentRating, currentTime);
    }

    fclose(file);

    return 0;
}


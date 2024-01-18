/*
Given a set of text files containing synonyms for different words, complete the main program to output the synonyms for a specific word. Each text file contains synonyms for the word specified in the file’s name, and the synonyms within the file are grouped according to the synonyms' first letters, separated by an '*'. The program reads a word and a letter from the user and opens the text file associated with the input word. The program then stores the contents of the text file into a two-dimensional array of char* predefined in the program. Finally the program searches the array and outputs all the synonyms that begin with the input letter, one synonym per line, or a message if no synonyms that begin with the input letter are found.

Hints: Use the malloc() function to allocate memory for each of the synonyms stored in the array. A string always ends with a null character ('\0'). Use ASCII values to map the row index of the array to the first letter of a word when storing the synonyms into the array. Ex: Index 0 to an 'a', index 25 to a 'z'. Assume all letters are in lowercase.

Ex: If the input of the program is:

educate c

the program opens the file educate.txt, which contains:

brainwash
brief
*
civilize
coach
cultivate
*
develop
discipline
drill
*
edify
enlighten
exercise
explain
*
foster
*
improve
indoctrinate
inform
instruct
*
mature
*
nurture
*
rear
*
school
*
train
tutor
*

then the program outputs:

civilize
coach
cultivate

Ex: If the input of the program is:

educate a

then the program outputs:

No synonyms for educate begin with a.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_LETTERS 25

int main(void) {
    char word[20];
    char letter;
    
    // Get user input
    printf("Enter a word: ");
    scanf("%s", word);

    printf("Enter a letter: ");
    scanf(" %c", &letter); // Note the space before %c to consume the newline character

    // Convert the letter to lowercase
    //letter = tolower(letter);

    // Form the filename based on the input word
    char filename[30];
    strcat (filename, word);
    strcat (filename, ".txt");
    FILE *file = fopen(filename, "r");

    // Check if the file exists
    if (file == NULL) 
    {
        printf("Could not open file %s.\n", filename);
        return -1;
    }

    // Initialize a 2D array of char* to store synonyms
    char* synonyms[NUM_LETTERS][100] = {NULL};

    // Read the file and store synonyms in the array
    char str[100];
    int index = 0;
    int synonymFound = 0;
    
    while (fgets(str, sizeof(str), file) != NULL) 
    {
        //if the synonym word is found
        if (str[0] == letter)
        {
            //index 0 to 'a', index 25 to 'z'
            index = letter - 'a'; //a - a = 0; e - a = 4;etc
            synonymFound = 1;
            if (str[0] == '*') 
            {
                index++;
            } 
            else
            {
                // Allocate memory for the synonym
                synonyms[index][0] = (char*)malloc(strlen(str) + sizeof(char));
                strcpy(synonyms[index][0], str);
                printf("%s", synonyms[index][0]); 
            }
        }
    }

    //If synonym is not found
    if (!synonymFound)
    {
        printf("No synonyms for %s begin with %c.\n", word, letter);
    }

    // Close the file
    fclose(file);

    // Free allocated memory
    for (int i = 0; i < NUM_LETTERS; i++) 
    {
        if (synonyms[i][0] != NULL) 
        {
            free(synonyms[i][0]);
        }
    }

    return 0;
}

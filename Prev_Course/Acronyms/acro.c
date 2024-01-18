/*
An acronym is a word formed from the initial letters of words in a set phrase.

Define a function named CreateAcronym that takes two string parameters: userPhrase and userAcronym. 
Function CreateAcronym() then assigns userAcronym with the acronym of userPhrase. 

Append a period (.) after each letter in the acronym. If a word begins with a lower case letter, 
don't include that letter in the acronym. Then write a main program that reads a phrase from input,
calls CreateAcronym() with the input phrase as one of the arguments, and outputs the resulting acronym.

Assume the input has at most 50 characters and contains at least one upper case letter.

Ex: If the input is: Institute of Electrical and Electronics Engineers
the output should be: I.E.E.E.
Ex: If the input is: Association for computing MACHINERY
the output should be: A.M.

Although the letters ACHINERY in MACHINERY are upper case, those letters are omitted for being a part of the word MACHINERY.

The program must define and call a function:
void CreateAcronym(char userPhrase[], char userAcronym[])

Hint: Use isupper() to check if a letter is upper case.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Define your function here. */
void CreateAcronym(char userPhrase[], char userAcronym[])
{
    int i = 0;
    int userAcronymIndex = 0; //use this var for the userAcronym array, cuz before use int i to update userAcronym inside the loop, the array only update inside the loop
    
    //for index = 0 to the end of the string
    for (i = 0; userPhrase[i] != '\0'; i++)
    {
        //If the current word index is Upper and the previous position is a "spacebar, condition True
        //Or if the index is at the beginning and is an Upper --> condition true
        if ( (isupper(userPhrase[i]) && userPhrase[i - 1] == ' ') || (i == 0 && isupper(userPhrase[i])) )
        {
            userAcronym[userAcronymIndex++] = userPhrase[i];
            userAcronym[userAcronymIndex] = '.';
            userAcronymIndex++;
        }     
    }
    //userAcronym[userAcronymIndex] = '\0'; // Null-terminate the acronym
    printf("\nThe acronym word is: %s", userAcronym);
    printf ("\nThe original word is: %s", userPhrase);
}

int main() {
   /* Type your code here. */
    char word[50] = {'\0'};
    char acronym[50] = {'\0'};

    printf("Enter the word to be convert to an acronym: ");
    scanf("%[^\n]s",word); //use [^\n] so that scanf can detect spacebar

    CreateAcronym(word, acronym);
    return 0;
}
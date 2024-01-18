/*
File in D:\uWindsor\SEMESTER_1\COMP-1410\LECTURE

Write a program that reads a list of words. Then, the program outputs those words and their frequencies. 
The input begins with an integer indicating the number of words that follow. Assume that the list will always contain fewer than 20 words, 
and each word contains fewer than 10 characters.

Ex: If the input is: 
5 hey hi Mark hi mark

the output is: 
hey - 1
hi - 2
Mark - 1
hi - 2
mark - 1

Hint: Use two arrays, one array for the strings and one array for the frequencie
*/

#include <stdio.h>
#include <string.h>

int main(void) {

    /* Type your code here. */
    char wordsList[20][10];
    int counter[20] = {0};
    int n, i, j;

    printf("Enter the number of words: ");
    scanf("%d", &n);

    printf("Enter the words: ");
    for(i = 0; i < n; i++) 
    {
        scanf("%s", wordsList[i]);
    }

    for(i = 0; i < n; i++) 
    {
        counter[i] = 0; 
        //conpare word [0] to word[0 to n] and so on
        for(j = 0; j < n; j++) 
        {
            if(strcmp(wordsList[i], wordsList[j]) == 0) 
            {
               counter[i]++; //increase counter if the next word match the current index word
            }
        }
    }

    printf("Words and their frequencies: \n");
    for(i = 0; i < n; i++) 
    {
        printf("%s - %d\n", wordsList[i], counter[i]);
    }

    return 0;
}

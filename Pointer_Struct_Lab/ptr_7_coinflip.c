/*
Define a function named CoinFlip that returns "Heads" or "Tails" according to a random value 1 or 0. Assume the value 1 represents "Heads" and 0 represents "Tails". 
Then, write a main program that reads the desired number of coin flips as an input, calls function CoinFlip() repeatedly according to the number of coin flips, and outputs
the results. Assume the input is a value greater than 0.

Hint: Use the modulo operator (%) to limit the random integers to 0 and 1.

Ex: If the random seed value is 2 and the input is:
3
the output is:
Tails
Heads
Tails
Note: For testing purposes, a pseudo-random number generator with a fixed seed value is used in the program. The program uses a seed value of 2 during development, 
but when submitted, a different seed value may be used for each test case.

The program must define and call the following function:
void CoinFlip(char* decisionString)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define your function here */ 
void CoinFlip(char* decisionString)
{
    int random = rand() % 2;
    if (random == 1)
    {
        strcpy(decisionString, "Heads");
    }
    else 
    {
        strcpy(decisionString, "Tails");
    }
    printf("%s\n", decisionString);
}

int main(void) {
    /* Add more variables as needed */
    int input = 0;
    
    srand(2);  /* Unique seed */

    /* Type your code here. */
    scanf("%d", &input);
    char str[input];
    for (int i = 0; i < input; i++)
    {
        CoinFlip(str);     
    }
    return 0;
}

/*
void CoinFlip(char* decisionString)
{
    if (*decisionString == '1')
    {
        printf("Heads\n");
    }
    else 
    {
        printf("Tails\n");
    }
}

int main(void) {

    int input = 0;
    char random;
    srand(2);   Unique seed 

    scanf("%d", &input);
    
    for (int i = 0; i < input; i++)
    {
        random = rand() % 2 + '0';
        CoinFlip (&random);
    }
    return 0;
}

*/
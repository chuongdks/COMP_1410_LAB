#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const int MAX_NAME_SIZE = 50;

// Function to swap two characters in an array
void swap(char **a, char **b) 
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}

// Recursive function to generate all permutations using heap algorithm: https://www.baeldung.com/cs/array-generate-all-permutations, dont understand any of this, cant keep track of all the recursion, dew it and just work
void PrintAllPermutations(char **permList, int permSize, char **nameList, int nameSize) 
{
    if (permSize == nameSize) //base case
    {
        // Print the current permutation
        for (int i = 0; i < nameSize; ++i) 
        {
            printf("%s", permList[i]);
            if (i < nameSize - 1) 
            {
                printf(", ");
            }
        }
        printf("\n");
    } 
    else 
    {
        for (int i = permSize; i < nameSize; ++i) //first iteration of this loop wont change anything, only assign the original word like ABC, BAC, CBA, ...
        {
            // Swap elements to create a new permutation
            swap(&nameList[permSize], &nameList[i]);
            permList[permSize] = nameList[permSize]; //assign nameList to permList
            
            // Recursively generate permutations for the remaining elements
            PrintAllPermutations(permList, permSize + 1, nameList, nameSize); //increase permSize until it is equal to nameSize (base case)

            // Usually, we will print the result first and then exit the function, Backtrack - undo the swap for the next iteration
            swap(&nameList[permSize], &nameList[i]);   
        }
    }
}

int main(void) {
    int size;
    int i = 0;
    char name[MAX_NAME_SIZE];
    scanf("%d", &size);
    char *nameList[size];
    char *permList[size];

    for (i = 0; i < size; ++i) {
        nameList[i] = (char *)malloc(MAX_NAME_SIZE);
        scanf("%s", name);
        strcpy(nameList[i], name);
    }

    PrintAllPermutations(permList, 0, nameList, size);

    // Free dynamically allocated memory
    for (i = 0; i < size; ++i) {
        free(nameList[i]);
    }

    return 0;
}

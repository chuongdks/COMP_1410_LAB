#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const int MAX_NAME_SIZE = 50;

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
        for (int i = 0; i < nameSize; ++i) //first iteration of this loop wont change anything, only assign the original word like ABC, BAC, CBA, ...
        {
            int isPermutation = 0;
            // Check if the name is already in the permutation, if nameList and permList are the same, flagged "isPermutation" -> break from j loop and increase int i
            for (int j = 0; j < permSize; j++)
            {
                //
                if (strcmp (nameList[i], permList[j]) == 0)
                {
                    isPermutation = 1;
                    break;
                }
            }

            //
            if (!isPermutation)
            {
                permList[permSize] = nameList[i];
                // Recursively generate permutations
                PrintAllPermutations (permList, permSize + 1, nameList, nameSize);
            }
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

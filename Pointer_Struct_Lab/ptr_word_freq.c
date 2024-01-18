#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    //char string[1000] = {'\0'};
    char string[1000] = "This is a test to Test! to is this is A test to this test! This is a test, to Test to: is this Is A test to this test is This A Test"; //put word manually here
    printf("Original word: ");
    //fgets(string, sizeof(string), stdin);  // read string from user, include the spacebar
    //string[strlen(string)-1] = '\0';
    puts(string);    // display string
    printf ("\n");

    //Use the strtok function to seperate string by the demiliter and put them in an array
    const char* delimiters = " .,-:!";
    char* token;
    //char arrstr[100][20] = {'\0'};
    char *arrstr[100] = {'\0'};
    
    /* Get the first token, if any. */
    token = strtok(string, delimiters); //return a ptr to the 1st token found in string
    /* Get the rest of the tokens, if any. */
    int num = 0, uniqueNum = 0;
    while(token != NULL) 
    {
        arrstr[num] = (char*)malloc(sizeof(char)); //allocate mem for arrstr string ptr
        strcpy(arrstr[num], token); //copy from token to arrstr string array, store each token in an array
        token = strtok(NULL, delimiters); //idk syntax
        //printf( "Token %d = %s\n", num, arrstr[num]); //print out the word in the string array
        num++;
    }

    //Count the word frequency
    int counter[100] = {0};
    for(int i = 0; i <num; i++) 
    {
        // Skip if array index is -1, which mean already counted
        if(counter[i] != -1) 
        {
            counter[i] = 1; //First counter is always 1 because it always counts the first word
            // Compare word [i] to word[i+1 to n] and so on
            for(int j = i + 1; j < num; j++) 
            {
                if (strcmp(arrstr[i], arrstr[j]) == 0) 
                {
                    counter[i]++; // Increase the counter of index i (the one doing the comparing) if match
                    counter[j] = -1; // Then use j index to mark the word as counted to skip it in future iteration
                }
            }
            printf("%s - Frequency: %d - Word Length: %d\n", arrstr[i], counter[i], strlen(arrstr[i]));
        }
        
        //Count the already counted word
        if(counter[i] == -1) {
            uniqueNum++;
        }
    }
   
    //print how many words
    printf("\nHow many words: %d\n", num);
    printf("How many unique words: %d\n", uniqueNum = num - uniqueNum); //unique word = total words - repeated word

    //Free the memory
    for (int i = 0; i < num; i++) 
    {
        free(arrstr[i]);
    }

    return 0;
}

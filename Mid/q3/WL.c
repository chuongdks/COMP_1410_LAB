#include <stdio.h>
#include <string.h>

int main(void) {
	char line[] = "In this c program, we count and show the frequency of words with different lengths.";
	printf("Sentence: \"%s\"\n", line);

	// Declare and initialize an array, wordLength, to keep the word's lengths
	// In the first element of the array, store the total number of words.
	// In each array element with index i, store the count of words with length i.
	int wordLength[8] = {0};                             // (0.5 mark)
	// Start tokenizing the array line using delimiters " .,?!:;"
	char *tokenPtr = strtok (line, " .,?!:;");                    // (0.5 mark)

	while (tokenPtr != NULL) 
	{                           
		//	Update the total number of words in the first element of the array
		wordLength[0]++;                                   // (0.5 mark)
        //	Check the length of the token.
		// 	Update the corresponding element of the array wordLength.
		//	*Note: If the length of the token is equal or greater than 7, you should update the last element of the array wordLength.
        if (strlen (tokenPtr) < 7)                       // (0.5 mark)
		{
			wordLength[strlen (tokenPtr)]++;
		}                      
		else
        {
			wordLength[7]++;
		}                       

		//	Then get the next token.
        tokenPtr = strtok (NULL, " .,?!:;");
	}
	
    // Print out the word frequency table
	printf("Total Number of Words: %d.\n", wordLength[0]);       // (0.5 mark)
	printf("Word Length\tFrequency\n");
	puts("========================");
    
    for (int i = 1; i <= 7; i++) 
	{
        if (i < 7)
        {
			printf("%d\t\t%3d\n", i, wordLength[i]);        
		}
        else
        {
			printf(">=%d\t\t%3d\n", i, wordLength[i]);
		}   
    }
	puts("========================");
}

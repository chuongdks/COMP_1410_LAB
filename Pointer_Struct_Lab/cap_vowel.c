#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Return a newly allocated copy of original
// with the first occurrence of each vowel capitalized
char* CapVowels(char* original) {
   /* Type your code here. */
   char *newString = malloc(sizeof(char));
   int vowelFreq[5] = {0}; //count how many vowel appear, index 0 -> index 5, a -> u
   strcpy(newString, original); //cant use newString = original cuz newString will be char pointer to original
   
   for (int i = 0; i < strlen(newString); i++)
   {
      if (newString[i] == 'a' && !vowelFreq[0]) 
      {
         newString[i] = toupper(newString[i]);
         vowelFreq[0] = 1;
      } 
      else if (newString[i] == 'e' && !vowelFreq[1]) 
      {
         newString[i] = toupper(newString[i]);
         vowelFreq[1] = 1;
      } 
      else if (newString[i] == 'i' && !vowelFreq[2]) 
      {
         newString[i] = toupper(newString[i]);
         vowelFreq[2] = 1;
      } 
      else if (newString[i] == 'o' && !vowelFreq[3]) 
      {
         newString[i] = toupper(newString[i]);
         vowelFreq[3] = 1;
      } 
      else if (newString[i] == 'u' && !vowelFreq[4]) 
      {
         newString[i] = toupper(newString[i]);
         vowelFreq[4] = 1;
      }
   }
   return newString;
}

int main(void) {
   char userCaption[50];
   char* resultStr;
   scanf("%s", userCaption);

   resultStr = CapVowels(userCaption);

   printf("Original: %s\n", userCaption);
   printf("Modified: %s\n", resultStr);
   
   // Always free dynamically allocated memory when no longer needed
  free(resultStr);
   
   return 0;
}

#include <stdio.h>

//Algorithm based on this: https://stackoverflow.com/questions/72083544/how-to-draw-right-side-up-triangle-recursively-with-one-argument
void DrawTriangle(int baseLength) 
{
   int spaces = 9 - baseLength / 2;  // Ensures correct spacing for each line, since baseLength is < 20 so baseLength / 2 = 9 max
   if (baseLength == 1) 
   {
      for (int i = 0; i < spaces; i++) 
      {
         printf("%d", i); //replace with empty space
      }
      printf("*\n");
   } 
   else 
   {
      DrawTriangle(baseLength - 2);
      //Printing after the recursion let u print smaller lines over the bigger lines
      //print the empty spaces
      for (int i = 0; i < spaces; i++) 
      {
         printf("%d", i); //replace with empty space
      }
      //print the line
      for (int i = 0; i < baseLength; i++) 
      {
         printf("*");
      }
      printf("\n");
   }
}

int main(void) {
   int baseLength;
   
   scanf("%d", &baseLength);

   // Ensure baseLength is odd and less than 20
   if (baseLength % 2 == 0 || baseLength > 19) {
      printf("Invalid input. Please enter an odd number less than 20.\n");
      return 1; // Exit with an error code
   }

   DrawTriangle(baseLength);

   return 0;
}

/*
Define a function named SwapValues that takes four integers as parameters and swaps the first with the second, and the third with the fourth values. Then write a main program that reads four integers from input, calls function SwapValues() to swap the values, and prints the swapped values on a single line separated with spaces.

Ex: If the input is:
3 8 2 4 

function SwapValues() returns and the main program outputs:
8 3 4 2

The program must define and call a function:
void SwapValues(int* userVal1, int* userVal2, int* userVal3, int* userVal4)
Function SwapValues() swaps the values referenced by the parameters.
*/
#include <stdio.h>

/* Define your function here */ 
void SwapValues(int* userVal1, int* userVal2, int* userVal3, int* userVal4)
{
    int temp1 = 0, temp2 = 0;
    temp1 = *userVal1;
    *userVal1 = *userVal2;
    *userVal2 = temp1;
    temp2 = *userVal3;
    *userVal3 = *userVal4;
    *userVal4 = temp2;
}
int main(void) {

   /* Type your code here. Your code must call the function.  */
   int input1, input2, input3, input4;
   scanf("%1d %1d %1d %1d", &input1, &input2, &input3, &input4);
   SwapValues(&input1, &input2, &input3, &input4);
   printf("%d %d %d %d\n", input1, input2, input3, input4);
   return 0;
}
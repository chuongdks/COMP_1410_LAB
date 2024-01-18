#include <stdio.h>

/* Define PrintNumPattern() here */
void PrintNumPattern(int num1, int num2) {
    if (num1 < 0) 
    {
        printf("%d ", num1);
        return 1;
    }

    printf("%d ", num1);
    PrintNumPattern(num1 - num2, num2);
    //After reach a negative number, backtrack and reprint all the number
    printf("%d ", num1);
}

int main(void) {
   int num1;
   int num2;
   
   scanf("%d", &num1);
   scanf("%d", &num2);
   PrintNumPattern(num1, num2);
}
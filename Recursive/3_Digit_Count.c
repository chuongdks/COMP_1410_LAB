#include <stdio.h>

/* TODO: Write recursive DigitCount() function here. */
int DigitCount(int n) {
    // Base case: if the number/10 is 0, it has 1 digit
    if (n/10 == 0) 
    {
        return 1;
    }
    return 1 + DigitCount(n / 10); //1 + the return value of the function n /1 10
}

int main(void) {
   int num;
   int digits;

   scanf("%d", &num); 
   digits = DigitCount(num);
   printf("%d", digits);
   return 0;
}

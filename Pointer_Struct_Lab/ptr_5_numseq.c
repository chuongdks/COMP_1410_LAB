/*
Complete the following functions to generate different sequences of numbers:

    int* Fibonacci(int n)
        _ Create an array of integers and size n
        _ Fill in the array with the first n Fibonacci numbers. The Fibonacci sequence begins with 0 and then 1 follows. 
        All subsequent values are the sum of the previous two, ex: 0, 1, 1, 2, 3, 5, 8, 13.
        _ Return the array

    int* Squares(int n)
        _ Create an array of integers and size n
        _ Fill in the array with the squares of 1 to n (inclusive). Ex: 1, 4, 9, …, n2
        _ Return the array

    int* Concatenate(int* array1, int size1, int* array2, int size2)
        _ Create an array of integers and size = size1 + size2
        _ Fill in the array with the elements of array1 followed by the elements of array2
        _ Return the array

main() reads the size of the Fibonacci and the squares sequences and calls the three functions above to create the arrays. 
Then main() calls PrintArray() provided in the template to print the arrays.

Ex: If the input is:
6 4

the output is:
0 1 1 2 3 5 
1 4 9 16 
0 1 1 2 3 5 1 4 9 16 
*/

#include <stdio.h>
#include <stdlib.h>

void PrintArray(int* array, int size) {
   for (int j = 0; j < size; ++j) {
      printf("%d ", array[j]);
   }
}

// Return the first n Fibonacci numbers
// fibonacci(0) = 0, fibonacci(1) = 1, fibonacci(2) = 1
// Ex: n = 5, seq = 0 1 1 2 3
int* Fibonacci(int n) {
   int* seq;
   int j;

   /* Type your code here. */
   seq = (int*)malloc(n * sizeof(int));
   j = 0;
   seq[0] = 0;
   seq[1] = 1;
   for (int i = 2; i < n; i++)
   {
      seq[i] = seq[i-1] + seq[i-2];
   }
   return seq;
}

// Return sequence of squares for 1..n (inclusive)
// Ex: sqrn = 3, seq = 1 4 9
int* Squares(int n) {
   int* seq;

   /* Type your code here. */
   seq = (int*)malloc(n * sizeof(int));
   for (int i = 1; i <= n; i++)
   {
      seq[i] = (i + 1) * (i + 1);
   }
   return seq;
}

// Return an array that is a copy of array1 followed by
// the elements of array2
int* Concatenate(int* array1, int size1, int* array2, int size2) {
   int j;
   int* seq;

   /* Type your code here. */
   int n = 0;
   j = size1 + size2;
   seq = (int*)malloc(j * sizeof(int));
   for (int i = 0; i < size1; i++)
   {
      seq[i] = array1[i];
   }
   for (int i = size1; i < j; i++)
   {
      seq[i] = array2[n];
      n++;
   }
   return seq;
}

int main(void) {

   int fibn;                                 // seq of first fibn Fibonacci numbers
                                             // Ex: fibn = 5, seq = 0 1 1 2 3
   int sqrn;                                 // number of squares starting with 1
                                             // Ex: sqrn = 3, seq = 1 4 9
   scanf("%d %d", &fibn, &sqrn);

   int* fibs;
   int* sqrs;
   int* conc;

   fibs = Fibonacci(fibn);
   PrintArray(fibs, fibn);
   printf("\n");

   sqrs = Squares(sqrn);
   PrintArray(sqrs, sqrn);
   printf("\n");

   conc = Concatenate(fibs, fibn, sqrs, sqrn);
   PrintArray(conc, fibn + sqrn);
   printf("\n");

   return 0;
}

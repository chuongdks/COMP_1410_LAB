#include <stdio.h>
#include <stdlib.h>

typedef struct Time_struct {
   int hours;
   int minutes;
   int seconds;
} Time;

// Allocate and return a Time as per parameters
Time* CreateTime(int hours, int minutes, int seconds) {
   Time* newTime = NULL;
   /* Type your code here. */
   newTime = (Time*)malloc(sizeof(Time));
   newTime->hours = hours;
   newTime->minutes = minutes;
   newTime->seconds = seconds;
   return newTime;
}

// Read integers hours, minutes, seconds;
// create and return a Time using the input values
Time* ReadTime() {
   int hours;
   int minutes;
   int seconds;
   scanf("%d %d %d", &hours, &minutes, &seconds);

   return CreateTime(hours, minutes, seconds);
}

Time* TimeDifference(Time* end, Time* start) {
   Time* diff = NULL;
   Time temp;
   /* TODO: allocate a new Time here */
   diff = (Time*)malloc(sizeof(Time));
   temp = *end;
   /* Type your code here. */
   if(start->seconds > temp.seconds)
   {
      temp.seconds += 60;
      --temp.minutes;
   }

   if(start->minutes > temp.minutes)
   {
      temp.minutes += 60;
      --temp.hours;
   }
   
   // Begin with uncorrected arithmetic
   diff->hours = temp.hours - start->hours;
   diff->minutes = temp.minutes - start->minutes;
   diff->seconds = temp.seconds - start->seconds;

   return diff;
  }

void PrintTime(Time* t) {
   printf("%02d:%02d:%02d", t->hours, t->minutes, t->seconds);
}

int main(void) {
   Time* start = NULL;
   Time* end = NULL;
   Time* difference = NULL;

   start = ReadTime();
   end = ReadTime();
   difference = TimeDifference(end, start);

   printf("Start:\t");
   PrintTime(start);
   printf("\nEnd:\t");
   PrintTime(end);
   printf("\nDifference: ");
   PrintTime(difference);
   printf("\n");

   // Always free dynamically allocated memory when no longer needed
   free(start);
   free(end);
   free(difference);

   return 0;
}

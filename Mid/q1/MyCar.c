#include <stdio.h>
#include <string.h>
// Include FancyCar library		                (0.5 mark)
/**************************/
#include "FancyCar.h"

int main(void) {
   // Declare a FancyCar struct variable		(0.5 mark)
   /**************************/
   FancyCar car;
    
   puts("A Honda, with KPL=9.5, Fuel Capacity=50, Fuel Level=20, and Odometer=1000.");
   // Initialize the car with above information.		(2 marks)
   /**************************/
   car = InitializeFancyCar (car, "Honda", 9.5, 50, 20.0, 1000);

   //Show the car engine status (on or off)			    (0.5 mark)
   /**************************/
   printf("%d\n", car.engineStatus);

   puts("Car tries to drive 10 kilometers when its engine is off!");
   // Drive the car for 10 kilometers.				    (0.5 mark)
   /**************************/
   car = Drive (car, 10);
   
   printf("Current Odometer: %d\n",car.odometer);
   // Turn on the car engine.					        (0.5 mark)
   /**************************/
   car = StartEngine (car);

   //Show the car engine status (on or off)             (0.5 mark)
   /**************************/
   printf("Car engine is now %s\n",car.engineStatus?"On":"Off");
   
   puts("Car drives 100 kilometers when its engine is on.");
   // Drive the car for 100 kilometers.				(0.5 mark)
   /**************************/
   car = Drive (car, 100);
    
   printf("Current Odometer: %d\n",car.odometer);
   // Show the remaining fuel in trunk.				(0.5 mark)
   /**************************/
   printf("Amount of fuel in tank: %5.2f\n",car.fuel);

   puts("Car tries to drive 100 more kilometers.");
   // Drive the car for 100 kilometers.				(0.5 mark)
   /**************************/
   car = Drive (car, 100);
    
   printf("Current Odometer: %d\n",car.odometer);
   
   // Show the remaining fuel in trunk.
   /**************************/
   printf("Amount of fuel in tank: %5.2f\n",car.fuel);
    
   puts("Fill 60 liters of fuel.");
   // Fill 60 liters of fuel.					(0.5 mark)
   /**************************/
   car = AddFuel (car, 60);
    
   printf("Amount of fuel in tank: %5.2f\n",car.fuel);

   // Drive the car for 200 kilometers.				(1 mark)
   puts("Car tries to drive 200 more kilometers.");
   /**************************/
   car = Drive (car, 200);
    
    
   printf("Current Odometer: %d\n",car.odometer);
   printf("Amount of fuel in tank: %5.2f\n",car.fuel);

   // Turn off the car engine					(0.5 mark)
   /**************************/
   car = StopEngine (car);
    
   printf("Car engine is now %s\n",car.engineStatus?"On":"Off");

   //Show the car engine status (on or off)       (0.5 mark)
   /**************************/


   return 0;
}

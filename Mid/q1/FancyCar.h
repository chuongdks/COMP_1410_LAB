#ifndef FANCY_CAR_H
#define FANCY_CAR_H

#include <stdio.h>
#include <string.h>

// Define a struct type with required members      (5 marks)

typedef struct FancyCar_Struct {
    char model[100];
    double kpl; //Kilometer per Liter
    double fuelCapacity;
    double fuel; //amount of fuel in tank
    int odometer;
    int engineStatus;
} FancyCar;

// Function Prototypes.
// No action needed here. These functions must be implemented
// in the corresponding c file, FancyCar.c.

// Car initialization
FancyCar InitializeFancyCar(FancyCar car, char* model, double kpl, double fuelCapacity, 
                              double fuel, int odometer);

// Drive car requested kilometers but check for enough
// fuel and check for positive value
FancyCar Drive(FancyCar car, int kilometersToDrive);

// Add fuel to tank. Check for positive value.
FancyCar AddFuel(FancyCar car, int amtToAdd);

// Set engine status to 1
FancyCar StartEngine(FancyCar car);

// Set engine status to 0
FancyCar StopEngine(FancyCar car);

#endif

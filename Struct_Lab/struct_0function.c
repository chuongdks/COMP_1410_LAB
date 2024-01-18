#include <stdio.h>
//#include "SimpleCar.h"

typedef struct SimpleCar_struct{
    int miles;
} SimpleCar;

SimpleCar InitCar();

SimpleCar Drive(int dist, SimpleCar car);

SimpleCar Reverse(int dist, SimpleCar car);

int GetOdometer(SimpleCar car);

void HonkHorn(SimpleCar car);

void Report(SimpleCar car);


int main() {
    /* Type your code here. */
    int forward = 0, backward = 0;
    SimpleCar bmw;
    int miles;

    scanf("%d", &forward);
    scanf("%d", &backward);

    bmw = InitCar(); //Init 

    HonkHorn(bmw);

    bmw = Drive (forward, bmw); //Since the Drive function return the whole SimpleCar struct, assign the member to the function
    bmw = Reverse (backward, bmw);

    Report (bmw);

    printf ("\nThe car drive for: %d miles", miles = GetOdometer(bmw));
    printf ("\nThe car drive for: %d miles", bmw.miles);
    return 0;
}




SimpleCar InitCar(){
    SimpleCar newCar;
    newCar.miles = 0;
    return newCar;
}

SimpleCar Drive(int dist, SimpleCar car){
    car.miles = car.miles + dist;   
    return car;
}
 
SimpleCar Reverse(int dist, SimpleCar car){
    car.miles = car.miles - dist;   
    return car;
}
   
int GetOdometer(SimpleCar car){
    return car.miles;
}

void HonkHorn(SimpleCar car){
    printf("beep beep\n");
}

void Report(SimpleCar car){
    printf("Car has driven: %d miles\n", car.miles);
}
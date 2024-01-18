/*
Given main(), create the Calculator struct that emulates basic functions of a calculator: add, subtract, multiple, divide, and clear. The struct has one data member called value for the calculator's current value.

Implement the Calculator struct and related function declarations in Calculator.h, and implement the related function definitions in Calculator.c as listed below:

    _ InitCalculator(Calculator c) - initialize the data member to 0.0
    _ Calculator Add(double val, Calculator c) - add the parameter to the data member
    _ Calculator Subtract(double val, Calculator c) - subtract the parameter from the data member
    _ Calculator Multiply(double val, Calculator c) - multiply the data member by the parameter
    _ Calculator Divide(double val, Calculator c) - divide the data member by the parameter
    _ Calculator Clear(Calculator c ) - set the data member to 0.0
    _ double GetValue(Calculator c) - return the data member

Given two double input values num1 and num2, the program outputs the following values:

    1. The initial value of the data member, value
    2. The value after adding num1
    3. The value after multiplying by 3
    4. The value after subtracting num2
    5. The value after dividing by 2
    6. The value after calling the clear() method

Ex: If the input is: 10.0 5.0
the output is:
0.0
10.0
30.0
25.0
12.5
0.0
*/
#include <stdio.h>

//#include "Calculator.h"

typedef struct Calculator_struct {
    double value;
} Calculator;

Calculator InitCalculator ();

Calculator Add (double val, Calculator c);

Calculator Subtract (double val, Calculator c);

Calculator Multiply (double val, Calculator c);

Calculator Divide (double val, Calculator c);

Calculator Clear (Calculator c );

double GetValue(Calculator c);



int main() {
	Calculator calc = InitCalculator(); //Init the calc member
	double num1;
	double num2;

	scanf("%lf", &num1);
	scanf("%lf", &num2);

	// 1. The initial value
	printf("%.1lf\n", GetValue(calc));

	// 2. The value after adding num1
	calc = Add(num1, calc);
	printf("%.1lf\n", GetValue(calc));

	// 3. The value after multiplying by 3
	calc = Multiply(3, calc);
	printf("%.1lf\n", GetValue(calc));

	// 4. The value after subtracting num2
	calc = Subtract(num2, calc);
	printf("%.1lf\n", GetValue(calc));

	// 5. The value after dividing by 2
	calc = Divide(2, calc);
	printf("%.1lf\n", GetValue(calc));

	// 6. The value after calling the Clear() method
	calc = Clear(calc);
	printf("%.1lf\n", GetValue(calc));

	return 0;
}



Calculator InitCalculator (){
    Calculator newCalc;
    newCalc.value = 0;
    return newCalc;
}

Calculator Add (double val, Calculator c){
    c.value = c.value + val;  
    return c;
}

Calculator Subtract (double val, Calculator c){
    c.value = c.value - val;  
    return c;
}

Calculator Multiply (double val, Calculator c){
    c.value = c.value * val;  
    return c;
}

Calculator Divide (double val, Calculator c){
    c.value = c.value / val;  
    return c;
}

Calculator Clear (Calculator c ){
    c.value = 0; 
    return c;
}

double GetValue(Calculator c){
    return c.value;
}

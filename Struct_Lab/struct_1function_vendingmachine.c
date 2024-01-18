/*
Given two integers as user inputs that represent the number of drinks to buy and the number of bottles to restock, create a VendingMachine variable that performs the following 
operations:

    _ Purchases input number of drinks
    _ Restocks input number of bottles
    _ Reports inventory

VendingMachine.h contains the struct definition and related function declarations. VendingMachine.c contains related function definitions.
A VendingMachine's initial inventory is 20 drinks.

Ex: If the input is: 5 2
the output is: Inventory: 17 bottles
*/

#include <stdio.h>
//#include "VendingMachine.h"

typedef struct VendingMachine_struct {
    int bottles;
} VendingMachine;

VendingMachine InitVendingMachine();
VendingMachine Purchase(int amount, VendingMachine vm);
VendingMachine Restock(int amount, VendingMachine vm);
int GetInventory(VendingMachine vm);
void Report(VendingMachine vm);

int main() {

    /* Type your code here. */
    int purchase = 0, restock = 0;

    scanf("%d", &purchase);
    scanf("%d", &restock);

    VendingMachine vm1;
    vm1 = InitVendingMachine();

    vm1 = Purchase (purchase, vm1);
    vm1 = Restock (restock, vm1);

    Report (vm1);
    return 0;
}

VendingMachine InitVendingMachine(){
    VendingMachine newVM;
    newVM.bottles = 20;
    return newVM;
}

VendingMachine Purchase(int amount, VendingMachine vm){
    vm.bottles = vm.bottles - amount;  
    return vm;
}

VendingMachine Restock(int amount, VendingMachine vm){
    vm.bottles = vm.bottles + amount;
    return vm;
}

int GetInventory(VendingMachine vm){
    return vm.bottles;
}

void Report(VendingMachine vm){
    printf("Inventory: %d bottles\n", vm.bottles);
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//struct product definition
struct Product {
    char name[21];
    double price;//attributes
    int priority;
    char fxc;
    char financing
};

int main(){
    //Declaring product variable called pd
    struct Product pd;

    //Declaring and initializing a product variable called pd2
    struct Product pd2 = {9.99, 2, 'y'};
    printf("pd2 price = %0.2lf\n", _____, pd2.price);
    printf("pd2 priprity = %d\n", _____, pd2.priority);
    printf("pd2 financing = %c", _____, pd2. financing);
return 0;
}
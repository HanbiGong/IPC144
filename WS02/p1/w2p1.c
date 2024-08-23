/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
Full Name  : Hanbi Gong
Student ID#: 111932224
Email      : hgong12@myseneca.ca
Section    : IPC 144

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    double small, medium, large;
    int shirtNum;
    double subTotal;
    double applyTax;
    double ToTal;
    const double TAX = 0.13;
    const char patSize = 'S';
    int subTotal0;
    int applyTax0;
    int ToTal0;


    printf("Set Shirt Prices\n"
        "================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &small);                                        

    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &medium);                                         

    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &large);                                        

    printf("\nShirt Store Price List\n"
        "======================\n");
    printf("SMALL  : $%.2lf\n", small);
    printf("MEDIUM : $%.2lf\n", medium);
    printf("LARGE  : $%.2lf\n", large);

    printf("\nPatty's shirt size is '%c'\n", patSize);
   
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &shirtNum);

    printf("\nPatty's shopping cart...\n");
    printf("Contains : ");
    printf("%d shirts\n", shirtNum);

    subTotal = small * (double)shirtNum;

    subTotal0 = (subTotal + 0.005) * 100;
    subTotal = subTotal0 / 100.0;

    applyTax = subTotal * TAX;
    applyTax0 = (applyTax + 0.005) * 100;
    applyTax = applyTax0 / 100.0;

    ToTal = applyTax + subTotal;
    ToTal0 = (ToTal + 0.005) * 100;
    ToTal = ToTal0 / 100.0;
    
    printf("Sub-total: $%0.4f\n", subTotal);
    printf("Taxes    : $ %0.4lf\n", applyTax);
    printf("Total    : $%0.4lf\n", ToTal);

    return 0;

}
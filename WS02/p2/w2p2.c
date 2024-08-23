/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
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
    const char patSize = 'S', salSize = 'M', tomSize = 'L';
    int patshirtNum, salshirtNum, tomshirtNum;
    const double TAX = 0.13;
    double balance;
    int toonies, loonies, quarters, dimes, nickels, pennies = 0;

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
    scanf("%d", &patshirtNum);
    printf("\nTommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &tomshirtNum);
    printf("\nSally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &salshirtNum);

    double patSubTotal = small * patshirtNum;
    double pattaxAmount = patSubTotal  * TAX + 0.005;
    int pattaxAmount0 = (int)(pattaxAmount * 100);
    double patTax = pattaxAmount0 / 100.0;
    double patTotal = patSubTotal + patTax;

    double tomSubTotal = large * tomshirtNum;
    double tomtaxAmount = tomSubTotal  * TAX + 0.005;
    int tomtaxAmount0 = (int)(tomtaxAmount * 100);
    double tomTax = tomtaxAmount0 / 100.0;
    double tomTotal = tomSubTotal + tomTax;

    double salSubTotal = medium * salshirtNum;
    double saltaxAmount = salSubTotal  * TAX + 0.005;
    int saltaxAmount0 = (int)(saltaxAmount * 100);
    double salTax = saltaxAmount0 / 100.0;
    double salTotal = salSubTotal + salTax;

    double subTotal = patSubTotal + tomSubTotal + salSubTotal;
    double taxTotal = patTax + tomTax + salTax;
    double total = subTotal + taxTotal;

    printf("\n");
    printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, small, patshirtNum, patSubTotal, patTax, patTotal);
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, medium, salshirtNum, salSubTotal, salTax, salTotal);
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, large, tomshirtNum, tomSubTotal, tomTax, tomTotal);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("%33.4lf %9.4lf %9.4lf\n\n", subTotal, taxTotal, total);


    printf("Daily retail sales represented by coins\n"
        "=======================================\n\n");
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");

    balance = subTotal + 0.00001;
    printf("%22.4lf\n", balance);
    toonies = balance / 2;
    balance = balance - (toonies * 2);
    printf("Toonies  %3d %9.4lf\n", toonies, balance);
    loonies = balance / 1;
    balance = balance - (loonies * 1);
    printf("Loonies  %3d %9.4lf\n", loonies, balance);
    quarters = balance / 0.25;
    balance = balance - (quarters * 0.25);
    printf("Quarters %3d %9.4lf\n", quarters, balance);
    dimes = balance / 0.1;
    balance = balance - (dimes * 0.1);
    printf("Dimes    %3d %9.4lf\n", dimes, balance);
    nickels = balance / 0.05;
    balance = balance - (nickels * 0.05);
    printf("Nickels  %3d %9.4lf\n", nickels, balance);
    pennies = balance / 0.01;
    balance = balance - (pennies * 0.01);
    printf("Pennies  %3d %9.4lf\n\n", pennies, balance);

    printf("Average cost/shirt: $%.4lf\n\n", subTotal / (patshirtNum + salshirtNum + tomshirtNum));

    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");

    balance = total + 0.00001;
    printf("%22.4lf\n", balance);
    toonies = balance / 2;
    balance = balance - (toonies * 2);
    printf("Toonies  %3d %9.4lf\n", toonies, balance);
    loonies = balance / 1;
    balance = balance - (loonies * 1);
    printf("Loonies  %3d %9.4lf\n", loonies, balance);
    quarters = balance / 0.25;
    balance = balance - (quarters * 0.25);
    printf("Quarters %3d %9.4lf\n", quarters, balance);
    dimes = balance / 0.1;
    balance = balance - (dimes * 0.1);
    printf("Dimes    %3d %9.4lf\n", dimes, balance);
    nickels = balance / 0.05;
    balance = balance - (nickels * 0.05);
    printf("Nickels  %3d %9.4lf\n", nickels, balance);
    pennies = balance / 0.01;
    balance = balance - (pennies * 0.01);
    printf("Pennies  %3d %9.4lf\n\n", pennies, balance);

    printf("Average cost/shirt: $%.4lf\n\n", total / (patshirtNum + salshirtNum + tomshirtNum));

    return 0;
}
/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
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
#define MAX_ITEM 10
#define MIN_ITEM 1

#include <stdio.h>

int main(void) {
    double Max_Income = 400000.00, Min_Income = 500.00, Min_cost = 100.00;
    double Cost[MAX_ITEM];
    double Income, Sum = 0;
    int Importance[MAX_ITEM];
    int Items, i;
    char Finance[MAX_ITEM];

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");

    do {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &Income);

        if (Income <= 0) {
            printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n\n", Min_Income);
        } else if (Income >= Max_Income) {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n\n", Max_Income);
        }
    } while (Income < Min_Income || Income > Max_Income);
    printf("\n");

    do {
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &Items);

        if (Items < MIN_ITEM || Items > MAX_ITEM){
            printf("ERROR: List is restricted to between %d and %d items.\n", MIN_ITEM, MAX_ITEM);
        }
        printf("\n");

    } while (Items < MIN_ITEM || Items > MAX_ITEM);

    for (i = 0; i < Items; i++) {
    printf("Item-%d Details:\n", i + 1);
    
    do {
        printf("   Item cost: $");
        scanf("%lf", &Cost[i]);

        if (Cost[i] < Min_cost) {
            printf("      ERROR: Cost must be at least $%.2lf\n", Min_cost);
        }
    } while (Cost[i] < Min_cost);

    do {
        printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
        scanf("%d", &Importance[i]);

        if (Importance[i] < 1 || Importance[i] > 3) {
            printf("      ERROR: Value must be between 1 and 3\n");
        }
    } while (Importance[i] < 1 || Importance[i] > 3);

    do {
        printf("   Does this item have financing options? [y/n]: ");
        scanf(" %c", &Finance[i]);

        if (Finance[i] != 'y' && Finance[i] != 'n') {
            printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
        }
    } while (Finance[i] != 'y' && Finance[i] != 'n');

    printf("\n");
}
    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (i = 0; i < Items; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, Importance[i], Finance[i], Cost[i]);
        Sum += Cost[i];
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", Sum);
    printf("Best of luck in all your future endeavours!\n");
    
    return 0;
}

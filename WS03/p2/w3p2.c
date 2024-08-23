/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
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
    const double GRAMS_IN_LBS = 453.5924;
    char Coffe_type1, Coffe_type2, Coffe_type3;
    int Bag_weight1, Bag_weight2, Bag_weight3;
    char Cream_1, Cream_2, Cream_3;

    char strength;
    char cream;
    int dailyServings;

    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");

    printf("Enter the coffee product information being sold today...\n\n");

    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &Coffe_type1);
    printf("Bag weight (g): ");
    scanf(" %d", &Bag_weight1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &Cream_1);

    printf("\nCOFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &Coffe_type2);
    printf("Bag weight (g): ");
    scanf(" %d", &Bag_weight2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &Cream_2);

    printf("\nCOFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &Coffe_type3);
    printf("Bag weight (g): ");
    scanf(" %d", &Bag_weight3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &Cream_3);

    printf("\n");
    printf("---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", Coffe_type1 == 'l' || Coffe_type1 == 'L', Coffe_type1 == 'm' || Coffe_type1 == 'M', Coffe_type1 == 'r' || Coffe_type1 == 'R', Bag_weight1, Bag_weight1 / GRAMS_IN_LBS, Cream_1 == 'y' || Cream_1 == 'Y');
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", Coffe_type2 == 'l' || Coffe_type1 == 'L', Coffe_type2 == 'm' || Coffe_type2 == 'M', Coffe_type2 == 'r' || Coffe_type2 == 'R', Bag_weight2, Bag_weight2 / GRAMS_IN_LBS, Cream_2 == 'y' || Cream_2 == 'Y');
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", Coffe_type3 == 'l' || Coffe_type1 == 'L', Coffe_type3 == 'm' || Coffe_type3 == 'M', Coffe_type3 == 'r' || Coffe_type3 == 'R', Bag_weight3, Bag_weight3 / GRAMS_IN_LBS, Cream_3 == 'y' || Cream_3 == 'Y');

    printf("\n");
    printf("Enter how you like your coffee...\n\n");
    
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &strength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream);
    printf("Typical number of daily servings: ");
    scanf(" %d", &dailyServings);

    printf("\nThe below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", (((strength == 'l' || strength == 'L') && (Coffe_type1 == 'l' || Coffe_type1 == 'L')) || ((strength == 'm' || strength == 'M') && (Coffe_type1 == 'm' || Coffe_type1 == 'M')) || ((strength == 'r' || strength == 'R') && (Coffe_type1 == 'r' || Coffe_type1 == 'R'))), (((1 <= dailyServings && dailyServings <= 4) && Bag_weight1 == 250) || ((5 <= dailyServings && dailyServings <= 9) && Bag_weight1 == 500) || (10 <= dailyServings && Bag_weight1 == 1000)), (((cream == 'y' || cream == 'Y') && (Cream_1 == 'y' || Cream_1 == 'Y')) || ((cream == 'n' || cream == 'N') && (Cream_1 == 'n' || Cream_1 == 'N'))));
    printf(" 2|       %d         |      %d      |   %d   |\n", (((strength == 'l' || strength == 'L') && (Coffe_type2 == 'l' || Coffe_type2 == 'L')) || ((strength == 'm' || strength == 'M') && (Coffe_type2 == 'm' || Coffe_type2 == 'M')) || ((strength == 'r' || strength == 'R') && (Coffe_type2 == 'r' || Coffe_type2 == 'R'))), (((1 <= dailyServings && dailyServings <= 4) && Bag_weight2 == 250) || ((5 <= dailyServings && dailyServings <= 9) && Bag_weight2 == 500) || (10 <= dailyServings && Bag_weight2 == 1000)), (((cream == 'y' || cream == 'Y') && (Cream_2 == 'y' || Cream_2 == 'Y')) || ((cream == 'n' || cream == 'N') && (Cream_2 == 'n' || Cream_2 == 'N'))));
    printf(" 3|       %d         |      %d      |   %d   |\n", (((strength == 'l' || strength == 'L') && (Coffe_type3 == 'l' || Coffe_type3 == 'L')) || ((strength == 'm' || strength == 'M') && (Coffe_type3 == 'm' || Coffe_type3 == 'M')) || ((strength == 'r' || strength == 'R') && (Coffe_type3 == 'r' || Coffe_type3 == 'R'))), (((1 <= dailyServings && dailyServings <= 4) && Bag_weight3 == 250) || ((5 <= dailyServings && dailyServings <= 9) && Bag_weight3 == 500) || (10 <= dailyServings && Bag_weight3 == 1000)), (((cream == 'y' || cream == 'Y') && (Cream_3 == 'y' || Cream_3 == 'Y')) || ((cream == 'n' || cream == 'N') && (Cream_3 == 'n' || Cream_3 == 'N'))));
    printf("\n");
    printf("Enter how you like your coffee...\n\n");

    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &strength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream);
    printf("Typical number of daily servings: ");
    scanf(" %d", &dailyServings);

    printf("\nThe below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", (((strength == 'l' || strength == 'L') && (Coffe_type1 == 'l' || Coffe_type1 == 'L')) || ((strength == 'm' || strength == 'M') && (Coffe_type1 == 'm' || Coffe_type1 == 'M')) || ((strength == 'r' || strength == 'R') && (Coffe_type1 == 'r' || Coffe_type1 == 'R'))), (((1 <= dailyServings && dailyServings <= 4) && Bag_weight1 == 250) || ((5 <= dailyServings && dailyServings <= 9) && Bag_weight1 == 500) || (10 <= dailyServings && Bag_weight1 == 1000)), (((cream == 'y' || cream == 'Y') && (Cream_1 == 'y' || Cream_1 == 'Y')) || (cream == 'n' || cream == 'N')) && (Cream_1 == 'n' || Cream_1 == 'N'));
    printf(" 2|       %d         |      %d      |   %d   |\n", (((strength == 'l' || strength == 'L') && (Coffe_type2 == 'l' || Coffe_type2 == 'L')) || ((strength == 'm' || strength == 'M') && (Coffe_type2 == 'm' || Coffe_type2 == 'M')) || ((strength == 'r' || strength == 'R') && (Coffe_type2 == 'r' || Coffe_type2 == 'R'))), (((1 <= dailyServings && dailyServings <= 4) && Bag_weight2 == 250) || ((5 <= dailyServings && dailyServings <= 9) && Bag_weight2 == 500) || (10 <= dailyServings && Bag_weight2 == 1000)), (((cream == 'y' || cream == 'Y') && (Cream_2 == 'y' || Cream_2 == 'Y')) || (cream == 'n' || cream == 'N')) && (Cream_2 == 'n' || Cream_2 == 'N'));
    printf(" 3|       %d         |      %d      |   %d   |\n", (((strength == 'l' || strength == 'L') && (Coffe_type3 == 'l' || Coffe_type3 == 'L')) || ((strength == 'm' || strength == 'M') && (Coffe_type3 == 'm' || Coffe_type3 == 'M')) || ((strength == 'r' || strength == 'R') && (Coffe_type3 == 'r' || Coffe_type3 == 'R'))), (((1 <= dailyServings && dailyServings <= 4) && Bag_weight3 == 250) || ((5 <= dailyServings && dailyServings <= 9) && Bag_weight3 == 500) || (10 <= dailyServings && Bag_weight3 == 1000)), (((cream == 'y' || cream == 'Y') && (Cream_3 == 'y' || Cream_3 == 'Y')) || (cream == 'n' || cream == 'N')) && (Cream_3 == 'n' || Cream_3 == 'N'));

    printf("\n");
    printf("Hope you found a product that suits your likes!\n");
    return 0;

}



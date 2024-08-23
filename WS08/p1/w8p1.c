/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
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

// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* Num)
{
	int Input = 0;
	do {
		scanf(" %d", &Input);

		if (Input <= 0) {
			printf("ERROR: Enter a positive value: ");
		}
	} while (Input <= 0);

	if (Num != NULL) {
		*Num = Input;
	}

	return Input;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *Num)
{
	double Input = 0;

	do {
		scanf(" %lf", &Input);

		if (Input <= 0) {
			printf("ERROR: Enter a positive value: ");
		}
	} while (Input <= 0);

	if (Num != NULL) {
		*Num = Input;
	}

	return Input;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int ProductNum)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", ProductNum);
	printf("NOTE: A 'serving' is %dg\n\n", NUM_OF_GRAMS);
}

// 4. Get user input for the details of cat food product
CatFoodInfo getCatFoodInfo(int productDetail)
{
    CatFoodInfo Info;

    printf("Cat Food Product #%d\n", productDetail);
    printf("--------------------\n");
    printf("SKU           : ");
    getIntPositive(&Info.Sku_num);
    printf("PRICE         : $");
    getDoublePositive(&Info.Product_price);
    printf("WEIGHT (LBS)  : ");
    getDoublePositive(&Info.Product_weight);
    printf("CALORIES/SERV.: ");
    getIntPositive(&Info.Calories);

    return Info;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku_Num, const double* product_price, const int Calories, const double* Product_weight)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku_Num, *product_price, *Product_weight, Calories);
}

// 7. Logic entry point
void start()
{
	int i = 0;
    CatFoodInfo CatFood[MAX_NUM_PRODUCT];
    openingMessage(MAX_NUM_PRODUCT);

	for (i = 0; i < MAX_NUM_PRODUCT; i++) {
		CatFood[i] = getCatFoodInfo(i+1);
		printf("\n");
	}

	displayCatFoodHeader();

	for (i = 0; i < MAX_NUM_PRODUCT; i++) {
		displayCatFoodData(CatFood[i].Sku_num, &CatFood[i].Product_price, CatFood[i].Calories, &CatFood[i].Product_weight);
	} 
}
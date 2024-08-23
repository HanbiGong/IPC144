/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
Full Name  : 
Student ID#: 
Email      : 
Section    : 

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
int getIntPositive(int* num)
{
	int temp = 0;
	do {
		scanf(" %d", &temp);

		if (temp <= 0) {
			printf("ERROR: Enter a positive value: ");
		}
	} while (temp <= 0);

	if (num != NULL) {
		*num = temp;
	}

	return temp;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* num)
{
	double temp = 0;

	do {
		scanf(" %lf", &temp);

		if (temp <= 0) {
			printf("ERROR: Enter a positive value: ");
		}
	} while (temp <= 0);

	if (num != NULL) {
		*num = temp;
	}

	return temp;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numOfProducts)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", numOfProducts);
	printf("NOTE: A 'serving' is %dg\n\n", NUM_OF_GRAMS);
}

// 4. Get user input for the details of cat food product

CatFoodInfo getCatFoodInfo(const int sequenceNum)
{
	CatFoodInfo catFood;

	printf("Cat Food Product #%d\n", sequenceNum);
	printf("--------------------\n");
	printf("SKU           : ");
	getIntPositive(&catFood.m_sku);
	printf("PRICE         : $");
	getDoublePositive(&catFood.m_price);
	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&catFood.m_weight);
	printf("CALORIES/SERV.: ");
	getIntPositive(&catFood.m_calory);

	return catFood;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const int calory, const double* weight)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calory);
}

// 7. Logic entry point
void start()
{
	CatFoodInfo catFood[MAX_NUM_PRODUCTS] = { {0} };
	int i = 0;
	openingMessage(MAX_NUM_PRODUCTS);

	for (i = 0; i < MAX_NUM_PRODUCTS; i++) {
		catFood[i] = getCatFoodInfo(i+1);
		printf("\n");
	}
	displayCatFoodHeader();
	for (i = 0; i < MAX_NUM_PRODUCTS; i++) {
		displayCatFoodData(catFood[i].m_sku, &catFood[i].m_price, catFood[i].m_calory, &catFood[i].m_weight);
	}
}
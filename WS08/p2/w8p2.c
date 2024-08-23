/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
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

// User-Defined Libraries
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

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
struct CatFoodInfo getCatFoodInfo (int productDetail)
{
    struct CatFoodInfo Info;

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
    printf("\n");

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

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* Pounds, double* Total_kilograms){
    double Conversion_double = (*Pounds) / THE_NUM_POUNDS_IN_KG;
    
    if (Total_kilograms != NULL){
        *Total_kilograms = Conversion_double;}
    
    return Conversion_double;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* Pounds, int* Total_grams){
    int Convertion_int = (*Pounds) / THE_NUM_POUNDS_IN_KG * 1000;
    if (Total_grams != NULL){
        *Total_grams = Convertion_int;}
    
    return Convertion_int;
}

// 10. convert lbs: kg and g
void convertLbs(const double* Pounds, double* Total_kilograms, int* Total_grams){
    if (Total_kilograms != NULL && Total_grams != NULL){
        *Total_kilograms = (*Pounds) / THE_NUM_POUNDS_IN_KG;
        *Total_grams = (*Pounds) / THE_NUM_POUNDS_IN_KG * 1000;}
    
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int Servingsize_grams, const int Total_grams, double* Num_servings){
    double Cal_servings = ((double) Total_grams) / Servingsize_grams;
    if (Num_servings != NULL){
        *Num_servings = Cal_servings;}
    return Cal_servings;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* Product_price, const double* Total_servings, double* Cost_serving){
    double Cal_cost_servings = (*Product_price) / (*Total_servings);
    if (Cost_serving != NULL){
        *Cost_serving = Cal_cost_servings;}
    return Cal_cost_servings;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* Product_price, const double* Num_calories, double* Cost_calorie){
    double Cal_cost_calorie = (*Product_price) / (*Num_calories);
    if (Cost_calorie != NULL){
        *Cost_calorie = Cal_cost_calorie;}
    return Cal_cost_calorie;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(struct CatFoodInfo CatFood) {

    struct ReportData Data;

    Data.Sku = CatFood.Sku_num;
    Data.Price = CatFood.Product_price;
    Data.Weight_lbs = CatFood.Product_weight;
    Data.Calories_serving = CatFood.Calories;

    Data.Weight_kg = convertLbsKg(&Data.Weight_lbs, &Data.Weight_kg);
    Data.Weight_grams = convertLbsG(&Data.Weight_lbs, &Data.Weight_grams);
    Data.Total_servings = calculateServings(NUM_OF_GRAMS, Data.Weight_grams, &Data.Total_servings);
    double Total_Calories = Data.Calories_serving * Data.Total_servings;
    Data.Cost_serving = calculateCostPerServing(&Data.Price, &Data.Total_servings, &Data.Cost_serving);
    Data.Cost_calories_serving = calculateCostPerCal(&Data.Price, &Total_Calories, &Data.Cost_calories_serving);
    return Data;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", NUM_OF_GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData Data, const int Cheapest_product) {
    printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf",
           Data.Sku, Data.Price, Data.Weight_lbs, Data.Weight_kg, Data.Weight_grams, Data.Calories_serving, Data.Total_servings, Data.Cost_serving, Data.Cost_calories_serving);
}
// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo Info){
    printf(
		"Final Analysis\n"
        "--------------\n"
        "Based on the comparison data, the PURRR-fect economical option is:\n");
    printf("SKU:%07d Price: $%5.2lf\n\n", Info.Sku_num, Info.Product_price);
    printf("Happy shopping!\n\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void){
    int i, Cheapest_product = 0;

    struct CatFoodInfo Info[MAX_NUM_PRODUCT] = { {0} };
    struct ReportData Data[MAX_NUM_PRODUCT] = { {0} };

    openingMessage(MAX_NUM_PRODUCT);

 for (i = 0; i < MAX_NUM_PRODUCT; i++) {
        Info[i] = getCatFoodInfo(i+1);
        Data[i] = calculateReportData(Info[i]);
    }
    displayCatFoodHeader();

   for (i = 0; i < MAX_NUM_PRODUCT; i++) {
        displayCatFoodData(Info[i].Sku_num, &Info[i].Product_price, Info[i].Calories, &Info[i].Product_weight);
    }
    double Cheapest = Data[0].Cost_serving;
    for (i = 0; i < MAX_NUM_PRODUCT; i++){
        if (Data[i].Cost_serving <= Cheapest){
            Cheapest = Data[i].Cost_serving;
            Cheapest_product = i;}}
    printf("\n");

    displayReportHeader();

    for (i = 0; i < MAX_NUM_PRODUCT; i++){
        displayReportData(Data[i], Cheapest_product);

        if (Cheapest_product == i){
            printf(" ***\n");}
        else{
            printf("\n");}}
    printf("\n");

    for (i = 0; i < MAX_NUM_PRODUCT; i++){
        if (i == Cheapest_product){
            displayFinalAnalysis(Info[i]);}
    }
}
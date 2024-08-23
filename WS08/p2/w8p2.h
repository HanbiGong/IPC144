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

// ----------------------------------------------------------------------------
// defines/macros
#define MAX_NUM_PRODUCT 3
#define NUM_OF_GRAMS 64
#define THE_NUM_POUNDS_IN_KG 2.20462

// ----------------------------------------------------------------------------
// structures

struct CatFoodInfo {
    int Sku_num;
    double Product_price;
    int Calories;
    double Product_weight;
} ;

struct ReportData {
    int Sku;                   
    double Price;              
    int Calories_serving;    
    double Weight_lbs;         
    double Weight_kg;           
    int Weight_grams;           
    double Total_servings;     
    double Cost_serving;     
    double Cost_calories_serving; 
};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *Num);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *Num);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(int ProductNum);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo (int productDetail);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku_Num, const double* product_price, const int Calories, const double* Product_weight); 

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* Pounds, double* Total_kilograms);

// 9. convert lbs: g
int convertLbsG(const double* Pounds, int* Total_grams);

// 10. convert lbs: kg / g
void convertLbs(const double* Pounds, double* Total_kilograms, int* Total_grams);

// 11. calculate: servings based on gPerServ
double calculateServings(const int Servingsize_grams, const int Total_grams, double* Num_servings);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* Product_price, const double* Total_servings, double* Cost_serving);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* Product_price, const double* Num_calories, double* Cost_calorie);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(struct CatFoodInfo CatFood);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData Repeat_data, const int Cheapest_product);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo CatFood);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start(void);

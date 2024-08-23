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


// ----------------------------------------------------------------------------

#define MAX_NUM_PRODUCT 3
#define NUM_OF_GRAMS 64
#define THE_NUM_US_POUNDS_IN_KG 2.20462

// structures
typedef struct 
{
    int Sku_num;
    double Product_price;
    int Calories;
    double Product_weight;
} CatFoodInfo;


// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *Num);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *Num);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(int ProductNum);

// 4. Get user input for the details of cat food product
CatFoodInfo getCatFoodInfo(int productDetail);

// 5. Display the formatted table header
void displayCatFoodHeader();

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku_Num, const double* product_price, const int Calories, const double* Product_weight); 

// 7. Logic entry point
void start();

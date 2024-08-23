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

#define MAX_NUM_PRODUCTS 3
#define NUM_OF_GRAMS 64
// ----------------------------------------------------------------------------
// structures
typedef struct
{
    int m_sku;
    double m_price;
    int m_calory;
    double m_weight;

} CatFoodInfo;



// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* num);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* num);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numOfProducts);

// 4. Get user input for the details of cat food product
CatFoodInfo getCatFoodInfo(const int sequenceNum);

// 5. Display the formatted table header
void displayCatFoodHeader();

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const int calory, const double* weight);

// 7. Logic entry point
void start();

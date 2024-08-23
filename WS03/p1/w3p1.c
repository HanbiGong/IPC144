/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
Full Name  : Hanbi Gong
Student ID#: 111932224
Email      : hgong12@myseneca.ca
Section    : IPC 144

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const int Product1_Id = 111, Product2_Id = 222, Product3_Id = 111;
    const double Product1_Price = 111.49, Product2_Price = 222.99, Product3_Price = 334.49;
    const char Product1_Tax = 'Y', Product2_Tax = 'N', Product3_Tax = 'N';
    const double Average = (Product1_Price + Product2_Price + Product3_Price) / 3.0 ; 
    const double testValue = 330.99;

    printf("Product Information\n"
        "===================\n");
    printf("Product-1 (ID:%d)\n", Product1_Id);
    printf("  Taxed: %c\n", Product1_Tax);
    printf("  Price: $%.4lf\n\n", Product1_Price);
    printf("Product-2 (ID:%d)\n", Product2_Id);
    printf("  Taxed: %c\n", Product2_Tax);
    printf("  Price: $%.4lf\n\n", Product2_Price);
    printf("Product-3 (ID:%d)\n", Product3_Id);
    printf("  Taxed: %c\n", Product3_Tax);
    printf("  Price: $%.4lf\n\n", Product3_Price);

    printf("The average of all prices is: $%.4lf\n\n", Average );

    printf("About Relational and Logical Expressions!\n"
            "========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n" 
           "2. FALSE: is always represented by integer value 0\n"
           "3. TRUE : is represented by any integer value other than 0\n\n");


    printf("Some Data Analysis...\n"
            "=====================\n");
    printf("1. Is product 1 taxable? -> %d\n\n", (Product1_Tax == 'Y'));
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n", (Product2_Tax != 'Y' && Product3_Tax != 'Y'));
    printf("3. Is product 3 less than testValue ($%.2lf)? -> %d\n\n", testValue, (Product3_Price < testValue));   
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", (Product3_Price > (Product1_Price + Product2_Price)));  
    printf("5. Is the price of product 1 equal to or more than the price difference\n"
           "   of product 3 LESS product 2? ->  %d (price difference: $%.2lf)\n\n", (Product1_Price >= (Product3_Price - Product2_Price)), (Product3_Price - Product2_Price));
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n", (Product2_Price) >= (Average));
    printf("7. Based on product ID, product 1 is unique -> %d\n\n", (Product1_Id == Product2_Id && Product1_Id == Product3_Id));
    printf("8. Based on product ID, product 2 is unique -> %d\n\n", (Product2_Id != Product1_Id && Product2_Id != Product3_Id));
    printf("9. Based on product ID, product 3 is unique -> %d\n\n", (Product3_Id == Product1_Id && Product3_Id == Product2_Id));
            
    return 0;
}
/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P1)
FFull Name  : Hanbi Gong
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
#define MIN_YEAR 2012
#define MAX_YEAR 2022

int main(void)
{
    const int JAN = 1;
    const int DEC = 12;
    int month, year;

    printf("General Well-being Log\n");
    printf("======================\n");

    do {
    printf("Set the year and month for the well-being log (YYYY MM): " );
    scanf("%4d%2d",&year,&month);

    if(year < MIN_YEAR || year > MAX_YEAR ){
    printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
    }

    if(month < JAN || month > DEC ){
    printf("   ERROR: Jan.(1) - Dec.(12)\n");
    }

    }while ((year < MIN_YEAR || year > MAX_YEAR) || (month < JAN || month > DEC));
    printf("\n*** Log date set! ***");
    printf("\n\nLog starting date: %4d-", year);
    if (month == 1){
        printf("JAN-01\n");
    }
    else if (month == 2){
        printf("FEB-01\n");
    }
    else if (month == 3){
        printf("MAR-01\n");
    }
        else if (month == 4){
        printf("APR-01\n");
    }
        else if (month == 5){
        printf("MAY-01\n");
    }
        else if (month == 6){
        printf("JUN-01\n");
    }
        else if (month == 7){
        printf("JUL-01\n");
    }
        else if (month == 8){
        printf("AUG-01\n");
    }
        else if (month == 9){
        printf("SEP-01\n");
    }
        else if (month == 10){
        printf("OCT-01\n");
    }
        else if (month == 11){
        printf("NOV-01\n");
    }
    else{
        printf("DEC-01\n");
    }
    return 0;
}
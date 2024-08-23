/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
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
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3

int main(void) {
    const int JAN = 1;
    const int DEC = 12;
    int month, year, i;
    double Morning_rating, Evening_rating;
    double Morning_sum = 0.0, Evening_sum = 0.0;

    printf("General Well-being Log\n");
    printf("======================\n");

    do {
    printf("Set the year and month for the well-being log (YYYY MM): ");
    scanf("%4d%2d", &year, &month);

    if (year < MIN_YEAR || year > MAX_YEAR) {
    printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
    }

    if (month < JAN || month > DEC) {
    printf("   ERROR: Jan.(1) - Dec.(12)\n");
    }

    } while ((year < MIN_YEAR || year > MAX_YEAR) || (month < JAN || month > DEC));

    printf("\n*** Log date set! ***\n");

    for (i = 1; i <= LOG_DAYS; i++) {
    if (month == 1){
        printf("\n%d-JAN-%02d", year, i);
    }
    else if (month == 2){
        printf("\n%d-FEB-%02d", year, i);
    }
    else if (month == 3){
        printf("\n%d-MAR-%02d", year, i);
    }
    else if (month == 4){
        printf("\n%d-APR-%02d", year, i);
    }
    else if (month == 5){
        printf("\n%d-MAY-%02d", year, i);
    }
    else if (month == 6){
        printf("\n%d-JUN-%02d", year, i);
    }
    else if (month == 7){
        printf("\n%d-JUL-%02d", year, i);
    }
    else if (month == 8){
        printf("\n%d-AUG-%02d", year, i);
    }
    else if (month == 9){
        printf("\n%d-SEP-%02d", year, i);
    }
    else if (month == 10){
        printf("\n%d-OCT-%02d", year, i);
    }
    else if (month == 11){
        printf("\n%d-NOV-%02d", year, i);
    }
    else if (month == 12){
        printf("\n%d-DEC-%02d", year, i);
    }
        printf("\n");

    do {
    printf("   Morning rating (0.0-5.0): ");
    scanf("%lf", &Morning_rating);

    if (Morning_rating < 0.0 || Morning_rating > 5.0) {
    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
    } else {
        Morning_sum += Morning_rating;
    }
    } while (Morning_rating < 0.0 || Morning_rating > 5.0);

    do {
    printf("   Evening rating (0.0-5.0): ");
    scanf("%lf", &Evening_rating);

    if (Evening_rating < 0.0 || Evening_rating > 5.0) {
    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
    } else {
        Evening_sum += Evening_rating;
    }
    } while (Evening_rating < 0.0 || Evening_rating > 5.0);
    }

    printf("\nSummary\n");
    printf("=======\n");
    printf("Morning total rating: %.3lf\n", Morning_sum);
    printf("Evening total rating:  %.3lf\n", Evening_sum);
    printf("----------------------------\n");
    printf("Overall total rating: %.3lf\n", Morning_sum + Evening_sum);
    printf("\n");

    printf("Average morning rating:  %.1lf\n", Morning_sum / LOG_DAYS);
    printf("Average evening rating:  %.1lf\n", Evening_sum / LOG_DAYS);
    printf("----------------------------\n");
    printf("Average overall rating:  %.1lf\n", (Morning_sum / LOG_DAYS + Evening_sum / LOG_DAYS) / 2);
    printf("\n");

    return 0;
}
/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
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

int Number_of_iterations, Counts = 0;
char Loop_types;

int main(void)
{
    printf("+----------------------+\n"
            "Loop application STARTED\n"
            "+----------------------+\n");

do {
    printf("\nD = do/while | W = while | F = for | Q = quit"
           "\nEnter loop type and the number of times to iterate (Quit=Q0): ");
    scanf(" %c%d", & Loop_types , & Number_of_iterations);

    if (Loop_types == 'Q' && Number_of_iterations == 0)
    {
        printf("\n+--------------------+\n"
               "Loop application ENDED\n"
               "+--------------------+\n\n");
    }

else if (Loop_types == 'Q' && Number_of_iterations != 0)
        {
            printf("ERROR: To quit, the number of iterations should be 0!\n");
        }
        else if (Loop_types == 'D' && (Number_of_iterations < 3 || Number_of_iterations > 20))
        {
            printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
        }
        else if (Loop_types == 'W' && (Number_of_iterations < 3 || Number_of_iterations > 20))
        {
            printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
        }
        else if (Loop_types == 'F' && (Number_of_iterations < 3 || Number_of_iterations > 20))
        {
            printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
        }

        else if (Loop_types == 'D' && (Number_of_iterations > 2 || Number_of_iterations < 21))
        {
            printf("DO-WHILE: ");
            do
            {
              printf("D");
              Number_of_iterations --;
            }
            while (Number_of_iterations >= 1);
            printf("\n");
            
        }
        else if (Loop_types == 'W' && (Number_of_iterations > 2 || Number_of_iterations < 21))
        {
            printf("WHILE   : ");
            while (Number_of_iterations >= 1)
            {
                printf("W");
                Number_of_iterations--;
            }
            printf("\n");
        }
        else if (Loop_types == 'F' && (Number_of_iterations > 2 || Number_of_iterations < 21))
        {
            printf("FOR     : ");
            for (Counts = Number_of_iterations; Counts >= 1; Counts--) 
            {
                printf("F");
            }
            printf("\n");
        }
        else if (Loop_types != 'Q' || Loop_types != 'D' || Loop_types != 'F' || Loop_types != 'W')
        {
            printf("ERROR: Invalid entered value(s)!\n");
        }
    } while (Loop_types != 'Q' || (Loop_types == 'Q' && Number_of_iterations != 0));
        
    return 0;
}
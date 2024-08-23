// Copy the below commented "header" section to all your source code files!

/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 1
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
#include <string.h>
#include "core.h"
// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

// 1. To get an integer followed by a newline character
int inputInt()
{
    int Value = 0;
    char Newline = 'X';
    do
    {
        scanf("%d%c", &Value, &Newline);

        if (Newline != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }

    } while (Newline != '\n');

    return Value;
}

// 2. To get the positive integer as a value
int inputIntPositive()
{
	int Value = 0;

	do {
		Value = inputInt();

		if (Value <= 0) {
			printf("ERROR! Value must be > 0: ");
		}
	} while (Value <= 0);

	return Value;
}

// 3. To get the positive integer as a value
int inputIntRange(int Lower_bound, int Upper_bound)
{
	int Value = 0;
	do {
		Value = inputInt();

		if (Value < Lower_bound || Value > Upper_bound) {
			printf("ERROR! Value must be between %d and %d inclusive: ", Lower_bound, Upper_bound);
		}
	} while (Value < Lower_bound || Value > Upper_bound);

	return Value;
}

// 4. To get the input of a character out of a specific range
char inputCharOption(const char listOfChar[])
{
	char Value = '\0';
	int i, flag = 1;

	do {
		scanf("%c", &Value);
		clearInputBuffer();

		for (i = 0; listOfChar[i] != '\0'; i++) {
			if (Value == listOfChar[i]) {
				flag = 0;
			}
		}
		if (flag) {
			printf("ERROR: Character must be one of [%s]: ", listOfChar);
		}
	} while (flag);

	return Value;
}

//5. To get the input of a character out of a specific range
void inputCString(char* cString, int Min_length, int Max_length)
{

    int flag, i, j, Counts;

    do
    {
        char Str[100] = { '\0' };
        flag = 0;
        i = 0;
        j = 0;
        Counts = 0;
        
        scanf("%99[^\n]%*c", Str);

        for (i = 0; i < 100; i++)
        {
            if (Str[i] != '\0'){
                Counts++;
            }
        }

        if (Counts == Min_length && Min_length == Max_length)
        {
            for (j = 0; j <= Counts;j++){
                cString[j] = Str[j];
            }
            cString[j] = '\0';
            flag = 1;
        }
        else
        {
            if (Counts >= Min_length && Counts <= Max_length)
            {
                for (j = 0;j <= Counts;j++)
                {
                    cString[j] = Str[j];
                }
                cString[j] = '\0';
                flag = 1;
            }
        }
        if (flag == 0){
            if (Min_length == Max_length){
                printf("ERROR: String length must be exactly %d chars: ", Min_length);
            }
            else if (Counts > Max_length){
                printf("ERROR: String length must be no more than %d chars: ", Max_length);
            }
            else{
                printf("ERROR: String length must be between %d and %d chars: ", Min_length, Max_length);
            }
        }
    } while (flag == 0);
}



//6. To dispaly the phone number
void displayFormattedPhone(const char *Phone_number)
{
    if (Phone_number == NULL) {
        printf("(___)___-____");
        return;
    }

    int i, Number = 1, Length = 0;
    Length = 0;
    for (i = 0; Phone_number[i] != '\0'; i++) 
    { Length++;
        if (Phone_number[i] < 48 || Phone_number[i] > 57) 
        {
            Number = 0;
        }
    }
    if (Length == 10 && Number) 
    {
        printf("(");
        for (i = 0; i < 3; i++) 
        {
            printf("%c", Phone_number[i]);
        }
        printf(")");
        for (i = 3; i < 6; i++) 
        {
            printf("%c", Phone_number[i]);
        }
        printf("-");
        for (i = 6; i < 10; i++) 
        {
            printf("%c", Phone_number[i]);
        }
    }
    else { printf("(___)___-____"); 
    }
}

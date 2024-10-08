/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
Full Name  : Hanbi Gong
Student ID#: 111932224
Email      : hgong12@myseneca.ca
Section    : NEE

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>

#include "core.h"
// As demonstrated in the course notes: 
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer
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

int inputInt() {
	int num = 0;
	char newLine = 'X';

	do {
		scanf(" %d%c", &num, &newLine);
		if (newLine != '\n') {
			clearInputBuffer();
			printf("Error! Input a whole number: ");
		}
	} while (newLine != '\n');
	
	return num;
}

int inputIntPositive()
{
	int value = 0;

	do {
		value = inputInt();

		if (value <= 0) {
			printf("ERROR! Value must be > 0: ");
		}
	} while (value <= 0);

	return value;
}

int inputIntRange(int Lower_bound, int Upper_bound)
{
	int value = 0;
	do {
		value = inputInt();

		if (value < Lower_bound || value > Upper_bound) {
			printf("ERROR! Value must be between %d and %d inclusive: ", Lower_bound, Upper_bound);
		}
	} while (value < Lower_bound || value > Upper_bound);

	return value;
}

char inputCharOption(const char listOfChar[])
{
	char value = '\0';
	int i;
	int repeat = 1;

	do {
		scanf("%c", &value);
		clearInputBuffer();

		for (i = 0; listOfChar[i] != '\0'; i++) {
			if (value == listOfChar[i]) {
				repeat = 0;
			}
		}
		if (repeat) {
			printf("ERROR: Character must be one of [%s]: ", listOfChar);
		}
	} while (repeat);

	return value;
}

void inputCString(char* Cstring, int minNumChar, int maxNumChar)
{
	char value[1000] = "\0";
	int length = 0;
	int repeat = 1;

	do {
		scanf("%[^\n]s", value);
		clearInputBuffer();
		length = strlen(value);

		

		if (minNumChar == maxNumChar && length != maxNumChar) {
			printf("ERROR: String length must be exactly %d chars: ", maxNumChar);
		}
		else if (length > maxNumChar) {
			printf("ERROR: String length must be no more than %d chars: ", maxNumChar);
		}
		else if (length < minNumChar) {
			printf("ERROR: String length must be between %d and %d chars: ", minNumChar, maxNumChar);
		}
		else {
			repeat = 0;
			strcpy(Cstring, value);
		}
	} while (repeat);
}

void displayFormattedPhone(const char* Cstring)
{
	int length = 0;
	int i;
	int repeat = 1;

	if (Cstring != NULL) {

		length = strlen(Cstring);
		
		if (length == 10) {
			for (i = 0; i < length; i++) {
				if (Cstring[i] < '0' || Cstring[i] > '9') {
					repeat = 1;
					break;
				}
				else {
					repeat = 0;
				}
			}			
		}
	}
	if (repeat) {
		printf("(___)___-____");
	}
	else {
		for (i = 0; i < length; i++) {
			if (i == 0) {
				printf("(%c", Cstring[i]);
			}
			else if (i == 2) {
				printf("%c)", Cstring[i]);
			}
			else if (i == 5) {
				printf("%c-", Cstring[i]);
			}
			else {
				printf("%c", Cstring[i]);
			}
		}

	}

}


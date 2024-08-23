#define _CRT_SECURE_NO_WARNINGS
#include "core.h"
#include <stdio.h>
#include <string.h>
void clearInputBuffer(void)
{
	while (getchar() != '\n')
	{
	}
}

void suspend(void)
{
	printf("<ENTER> to continue...");
	clearInputBuffer();
	putchar('\n');
}

int inputInt()
{
	int temp = 0;
	char newLine = 'x';

	do {
		scanf("%d%c", &temp, &newLine);

		if (newLine != '\n') {
			clearInputBuffer();
			printf("Error! Input a whole number: ");
		}

	} while (newLine != '\n');

	return temp;
}

int inputIntPositive()
{
	int positive = 0;

	do {
		positive = inputInt();

		if (positive < 0) {
			printf("ERROR! Value must be > 0: ");
		}
	} while (positive < 0);	

	return positive;
}

int inputIntRange(int lower, int upper)
{
	int range = 0;

	do {
		range = inputInt();

		if (range < lower || range > upper) {
			printf("ERROR! Value must be between %d and %d inclusive: ", lower, upper);
		}
	} while (range < lower || range > upper);

	return range;
}

char inputCharOption(const char* validChar)
{
	char option = 'x';
	int i = 0;
	int flag = 1;

	do {
		scanf("%c", &option);
		clearInputBuffer();
		for (i = 0; validChar[i] != '\0'; i++) {
			if (option == validChar[i]) {
				flag = 0;
			}
		}

		if (flag == 1) {
			printf("ERROR: Character must be one of [%s]: ", validChar);
		}
	} while (flag);

	return option;
}

void inputCString(char* cString, int min, int max)
{
	int i = 0;
	int flag = 1;
	int length = 0;

	char temp[1000] = "\0";

	do {
		scanf("%[^\n]s", temp);
		length = strlen(temp);
		clearInputBuffer();
		if (max == min && strlen(temp) != max) {
			printf("ERROR: String length must be exactly %d chars: ", max);
		}
		else if (length > max) {
			printf("ERROR: String length must be no more than %d chars: ", max);
		}
		else if (length < min) {
			printf("ERROR: String length must be between %d and %d chars: ", min, max);
		}
		else {
			for (i = 0; i < length; i++) {
				cString[i] = temp[i];
			}
			flag = 0;
		}
	} while (flag);

}

void displayFormattedPhone(const char* cString)
{
	int i = 0;
	int flag = 0;
	int len = 0;

	if (cString != NULL) {
		len = strlen(cString);

		if (len == 10) {
			for (i = 0; i < len; i++) {
				if (cString[i] < '0' || cString[i] > '9') {
					flag = 1;
				}
			}

			if (flag) {
				printf("(___)___-____");
			}
			else {
				for (i = 0; i < len; i++) {
					if (i == 0) {
						printf("(%c", cString[i]);
					}
					else if (i == 2) {
						printf("%c)", cString[i]);
					}
					else if (i == 5) {
						printf("%c-", cString[i]);
					}
					else {
						printf("%c", cString[i]);
					}
				}
			}
		}
		else {
			printf("(___)___-____");
		}
	}
	else {
		printf("(___)___-____");
	}
	
}

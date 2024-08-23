/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 1
Full Name  :Lena Park
Student ID#:127390235
Email      :lpark9@myseneca.ca
Section    :NEE

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>
#include<string.h>

// Clear the standard input buffer
void clearInputBuffer(void); 

// Wait for user to input the "enter" key to continue
void suspend(void);

int inputInt();

int inputIntPositive();

int inputIntRange(int lower_bound, int upper_bound);

char inputCharOption(const char listOfChar[]);

void inputCString(char* Cstring, int minNumChar, int maxNumChar);

void displayFormattedPhone(const char* Cstring);

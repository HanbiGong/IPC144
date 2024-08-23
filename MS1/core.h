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

// !!! DO NOT DELETE THE BELOW LINE !!!
#endif // !CORE_H
/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
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


// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i;
    int flag = 1;
    displayPatientTableHeader();

    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber != 0) {
            displayPatientData(&patient[i], fmt);
            flag = 0;
        }
    }
    if (flag) {
        printf("*** No records found ***");
    }
    printf("\n");
}

// Search for a patient record based on patient number or phone number
// (Copy your code from MS#2)
void searchPatientData(const struct Patient patient[], int max)
{
    int num = -1;

    do {
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");
        num = inputIntRange(0, 2);
        printf("\n");
        if (num == 1) {
            searchPatientByPatientNumber(patient, max);
            suspend();
        }
        else if (num == 2) {
            searchPatientByPhoneNumber(patient, max);
            suspend();
        }
    } while (num != 0);
}


// Add a new patient record to the patient array
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max)
{
    int i;
    int index = -1;
    for (i = 0; i < max && index == -1; i++) {
        if (patient[i].patientNumber == 0) {
            index = i;
        }
    }
    if (index == -1) {
        printf("ERROR: Patient listing is FULL!");
        printf("\n");
    }
    else {
        patient[index].patientNumber = nextPatientNumber(patient, max);

        inputPatient(&patient[index]);
        printf("*** New patient record added ***");
        printf("\n");
    }
    printf("\n");
}

// Edit a patient record from the patient array
// (Copy your code from MS#2)
void editPatient(struct Patient patient[], int max)
{
    int num;
    int index = -1;
    printf("Enter the patient number: ");
    num = inputInt();
    printf("\n");
    index = findPatientIndexByPatientNum(num, patient, max);

    if (index == -1) {
        printf("ERROR: Patient record not found!");
        printf("\n\n");
    }
    else {
        menuPatientEdit(&patient[index]);
    }
}

// Remove a patient record from the patient array
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max)
{
    int num;
    int index = -1;
    char option;

    printf("Enter the patient number: ");
    num = inputInt();
    index = findPatientIndexByPatientNum(num, patient, max);
    printf("\n");
    if (index != -1) {
        displayPatientData(&patient[index], FMT_FORM);
        printf("\n");
        printf("Are you sure you want to remove this patient record? (y/n): ");
        option = inputCharOption("yn");
        if (option == 'y') {
            patient[index].patientNumber = 0;
            printf("Patient record has been removed!");
        }
        else {
            printf("Operation aborted.");
        }        
    }
    else {
        printf("ERROR: Patient record not found!");
    }
    printf("\n\n");
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData* data) {
    int i = 0;
    int j = -1;

    sortAppointment(data->appointments);
    displayScheduleTableHeader(&data->appointments->date, 1);

    for (i = 0; i < data->maxAppointments; i++) 
    {
        if (data->appointments[i].patientNumber != 0) {
            j = findPatientIndexByPatientNum(data->appointments[i].patientNumber, data->patients, data->maxPatient);
            displayScheduleData(&data->patients[j], &data->appointments[i], 1);
        }
    }
    printf("\n");
}

// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData* data) {

    int i = 0;
    int j = -1;
    int year = 0;
    int month = 0;
    int day = 0;

    inputDate(&year, &month, &day);
    printf("\n");
    
    struct Date date = {year, month, day};
    displayScheduleTableHeader(&date, 0);

    for (i = 0; i < data->maxAppointments; i++) {
        if (data->appointments[i].date.year == year) {
            if (data->appointments[i].date.month == month) {
                if (data->appointments[i].date.day == day) {
                    j = findPatientIndexByPatientNum(data->appointments[i].patientNumber, data->patients, data->maxPatient);
                    displayScheduleData(&data->patients[j], &data->appointments[i], 0);
                }
            }
        }
    }
    printf("\n");
}

/// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment* appointment, int maxAppointment,
    struct Patient* patient, int maxPatient) {

    int i = 0;
    int j = -1;    
    int counts = 0;
    int available = 1;
    int year = 0;
    int month = 0;
    int day = 0;
    int hour = 0;
    int min = 0;
    int flag = 1;

    printf("Patient Number: ");
    counts = inputIntPositive();
    j = findPatientIndexByPatientNum(counts, patient, maxPatient);

    if (j == -1) {
        printf("\n*** No records found ***\n");
    }
    else {
        for (i = 0; i < maxAppointment && j == -1; i++)
        {
            if (appointment[i].patientNumber == 0){
                j = i;
            }
        }

        if (j == -1) {
            printf("\nERROR: Appointment timeslot is not available!");
            printf("\n");
        }
        else {
            while (flag) {
                available = 1;
                inputDate(&year, &month, &day);
                inputTime(&hour, &min);

                for (i = 0; i < maxAppointment && available; i++)
                {
                    if (appointment[i].date.year == year && appointment[i].date.month == month && appointment[i].date.day == day && appointment[i].time.hour == hour && appointment[i].time.min == min){
                        printf("\nERROR: Appointment timeslot is not available!\n\n");
                        available = 0;
                    }
                }

                if (available) {
                    appointment[j].patientNumber = counts;
                    appointment[j].date.year = year;
                    appointment[j].date.month = month;
                    appointment[j].date.day = day;
                    appointment[j].time.hour = hour;
                    appointment[j].time.min = min;

                    flag = 0;
                }
            }
                        
            sortAppointment(appointment);
            printf("\n*** Appointment scheduled! ***\n");
            printf("\n");
        }
    }
}

// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment* appointment, int maxAppointment,
    struct Patient* patient, int maxPatient) {

    int i = 0;
    int j = -1;    
    int counts = 0;
    int year = 0;
    int month = 0;
    int day = 0;
    int flag = 1;
    char selection = 'x';

    printf("Patient Number: ");
    counts = inputIntPositive();
    j = findPatientIndexByPatientNum(counts, patient, maxPatient);

    if (j == -1){
        printf("ERROR: Patient record not found!\n\n");
    }
    else {
        inputDate(&year, &month, &day);

        for (i = 0; i < maxAppointment && flag; i++)
        {
            if (appointment[i].patientNumber == counts) {
                if (appointment[i].date.year == year) {
                    if (appointment[i].date.month == month) {
                        if (appointment[i].date.day == day) {
                            printf("\n");
                            displayPatientData(&patient[j], FMT_FORM);
                            printf("Are you sure you want to remove this appointment (y,n): ");
                            selection = inputCharOption("yn");

                            if (selection == 'y'){
                                printf("\nAppointment record has been removed!\n\n");
                                appointment[i].patientNumber = 0;
                                appointment[i].date.day = 0;
                                appointment[i].date.month = 0;
                                appointment[i].date.year = 0;
                                appointment[i].time.min = 0;
                                appointment[i].time.hour = 0;
                            }
                            else {
                                printf("operation aborted!");
                            }
                            flag = 0;
                        }
                    }
                }
            }           
        }
    }
}
//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int num = 0;
    int index = 0;

    printf("Search by patient number: ");

    num = inputInt();
    printf("\n");
    index = findPatientIndexByPatientNum(num, patient, max);
    if (index != -1) {
        displayPatientData(&patient[index], FMT_FORM);
    }
    else {
        printf("*** No records found ***");
        printf("\n");
    }
    printf("\n");
}

// Search and display patient records by phone number (tabular)
// (Copy your code from MS#2)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    char num[PHONE_LEN + 1] = { 0 };
    int i = 0;
    int flag = 1;
    printf("Search by phone number: ");
    inputCString(num, PHONE_LEN, PHONE_LEN);
    printf("\n");
    displayPatientTableHeader();

    for (i = 0; i < max; i++) {
        if (strcmp(num, patient[i].phone.number) == 0) {
            displayPatientData(&patient[i], FMT_TABLE);
            flag = 0;
        }
    }
    if (flag) {
        printf("\n");
        printf("*** No records found ***");
        printf("\n");
    }
    printf("\n");
}

// Get the next highest patient number
// (Copy your code from MS#2)
int nextPatientNumber(const struct Patient patient[], int max)
{
    int i;
    int num = 0;

    for (i = 0; i < max; i++) {
        if (num < patient[i].patientNumber) {
            num = patient[i].patientNumber;
        }
    }
    return num + 1;
}

// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
    int i;
    int index = -1;

    for (i = 0; i < max; i++) {
        if (patientNumber == patient[i].patientNumber) {
            index = i;
        }
    }
    return index;
}

void sortAppointment(struct Appointment* appointments)
{
    struct Appointment temp = { 0 };
    int i = 0;
    int j = 0;

    //Minute
    for (i = 0; i < MAX_APPOINTMENTS; i++) {
        for (j = 0; j < MAX_APPOINTMENTS - 1 - i; j++) {
                if (appointments[j].time.min > appointments[j + 1].time.min) {
                    temp = appointments[j];
                    appointments[j] = appointments[j + 1];                    
                    appointments[j + 1] = temp;
                }
        }
    }

    //Hour
    for (i = 0; i < MAX_APPOINTMENTS; i++) {
        for (j = 0; j < MAX_APPOINTMENTS - 1 - i; j++) {
            if (appointments[j].time.hour > appointments[j + 1].time.hour) {
                temp = appointments[j];
                appointments[j] = appointments[j + 1];
                appointments[j + 1] = temp;
            }
        }
    }

    //day
    for (i = 0; i < MAX_APPOINTMENTS; i++) {
        for (j = 0; j < MAX_APPOINTMENTS - 1 - i; j++) {
            if (appointments[j].date.day > appointments[j + 1].date.day) {
                temp = appointments[j];
                appointments[j] = appointments[j + 1];
                appointments[j + 1] = temp;
            }
        }
    }

    //month
    for (i = 0; i < MAX_APPOINTMENTS; i++) {
        for (j = 0; j < MAX_APPOINTMENTS - 1 - i; j++) {
           
            if (appointments[j].date.month > appointments[j + 1].date.month) {
                temp = appointments[j];
                appointments[j] = appointments[j + 1];
                appointments[j + 1] = temp;
            }
        }
    }

    //year
    for (i = 0; i < MAX_APPOINTMENTS; i++) {
        for (j = 0; j < MAX_APPOINTMENTS - 1 - i; j++) {
           
            if (appointments[j].date.year > appointments[j + 1].date.year) {
                temp = appointments[j];
                appointments[j] = appointments[j + 1];
                appointments[j + 1] = temp;
            }
        }
    }
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    printf("\n");
    inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
// (Copy your code from MS#2)
void inputPhoneData(struct Phone* phone)
{
    int num = 0;
    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");

    num = inputIntRange(1, 4);
    printf("\n");
    if (num == 1) {
        strcpy(phone->description, "CELL");
    }
    else if (num == 2) {
        strcpy(phone->description, "HOME");
    }
    else if (num == 3) {
        strcpy(phone->description, "WORK");
    }
    else if (num == 4) {
        strcpy(phone->description, "TBD");
    }

    if (num >= 1 && num <= 3) {
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputCString(phone->number, 10, 10);
        printf("\n");
    } 
}
void inputDate(int* year, int* month, int* day)
{
    int maxDay = 0;
    printf("Year        : ");
    *year = inputIntPositive();
    printf("Month (1-12): ");
    *month = inputIntRange(1, 12);
    if (*month == 2)
    {
        if (*year % 4 == 0)
        {
            maxDay = 29;
        }
        else
        {
            maxDay = 28;
        }
    }
    else if (*month == 1 || *month == 3 || *month == 5 || *month == 7 || *month == 8 || *month == 10 || *month == 12)
    {
        maxDay = 31;
    }
    else
    {
        maxDay = 30;
    }

    printf("Day (%d-%d)  : ", 1, maxDay);
    *day = inputIntRange(1, maxDay);
}

void inputTime(int* hour, int* min)
{
    int countTime = 1;

    while (countTime)
    {
        printf("Hour (0-23)  : ");
        *hour = inputIntRange(0, 23);
        printf("Minute (0-59): ");
        *min = inputIntRange(0, 59);

        if (*hour >= MIN_HOUR && *hour <= MAX_HOUR && *min % APPOINTMENT_INTERVAL == 0) {
            if (*hour == MAX_HOUR && *min == 30){
                printf("ERROR: Time must be between %d:00 and %d:00 in 30 minute intervals.\n\n", MIN_HOUR, MAX_HOUR);
            }
            else{
                countTime = 0;
            }
        }
        else {
            printf("ERROR: Time must be between %d:00 and %d:00 in %d minute intervals.\n\n", MIN_HOUR, MAX_HOUR, APPOINTMENT_INTERVAL);
        }
    }
}

//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max) {
    int check = 0;
    FILE* data = fopen(datafile, "r");

    if (data != NULL) {
        int repeat = 0; 
        while (check < max && !repeat) {
            int result = fscanf(data, "%d|%15[^|]|%4[^|]|%10[^\n]", &patients[check].patientNumber, patients[check].name, patients[check].phone.description, patients[check].phone.number);

            if (result == EOF ) {
                repeat = 1; 
            }
            else {
                check++;
            }
        }

        fclose(data);
    }
    else {
        fprintf(stderr, "Cannot open the file.\n");
    }

    return check;
}

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max) {
    int check = 0;
    FILE* data = fopen(datafile, "r");

    if (data != NULL) {
        int repeat = 0; 
        while (check < max && !repeat) {
            int result = fscanf(data, "%d,%d,%d,%d,%d,%d", &appoints[check].patientNumber, &appoints[check].date.year, &appoints[check].date.month, &appoints[check].date.day, &appoints[check].time.hour, &appoints[check].time.min);

            if (result == EOF) {
                repeat = 1;
            }
            else {
                check++;
            }
        }
        fclose(data);
    }
    else {
        fprintf(stderr, "Cannot open the file.\n");
    }
    return check;
}


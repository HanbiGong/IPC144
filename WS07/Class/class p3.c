#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
P4

*/

struct Course {
    char sCode[11];
    char sName[21];
    char grade;
};

struct Student{
    int id;
    int name[3];
    int age;
    struct Cousre cs[2];

};


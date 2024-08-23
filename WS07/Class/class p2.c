#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Student{
    int id;
    char name[31];
    int sCode;
    double mark;
};

int main(){
    struct Student st[3];
    int i;

    for (i = 0; i < 3; i++){
        printf("Student %d ID: ", i+1);
        scanf("%d%*c", &st[i].id);
        printf("Student %d Name: ", i+1);
        scanf("%30[^\n]%*c", st[i].name);
        printf("Stduent %d Cource ", i+1);
        scamf("%d%*c", &st[i].sCode);
        printf("Student %d Mark: ", i+1);
        scamf("%lf%*c", &st[i].mark);
        printf("\n");
    }
    printf("\n");
    for (i = 0; i < 3 ; i++){
        printf("ST-%d, ID=%d Name=%s Code=%d Mark=%0.2lf\n");
        i+1 , st[i].id, st[i].name, st[i].sCode , st[i].mark;
    }

    return 0;

}
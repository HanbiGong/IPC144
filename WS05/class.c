#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 5 //Macro Directive
            // ALso know as pre-processor directive
            //works jus like a variable
            //for only constant value -> add

int main(){

    double num, sum = 0 ;
    int i, flg = 0;

    for (i = 0; i < SIZE && flg == 0; i++) {

        printf("Enger Num %d: ", i + 1);
        scanf("%lf", &num);
        if (num < 0){
            printf("Quitting Early\n");
            flg = 1;

        }
        else {
            sum = sum + num;
        }
    }

    printf("Summation = %.2lf\n", sum);
    printf("Average = %.2lf\n", sum/(i-1));  //i-1을 쓴  경우, i=0,1,2,.....
    

   int i;
   double mark, sum =0;

   
   /*

   for(i = 0; i , SIZE; i++){

    printf("Enter Marks %d: ", i + 1);
    scanf("%lf ,& mark");
    if ( mark < 0 || mark > 100 {
        printf("Invalid Mark, Enter Again!...\n");
        i--;
    })
*/
/*
   for (i = 0; i < SIZE; i++){

    do {
        printf("Enter Marks %d, ", i + 1);
        scanf("%lf" ,&mark);
        if (mark < 0 || mark > 100){
            printf("Invalid Mark, Enter Again!...\n");
        }
    }while (mark < 0 || mark > 100};
   
   sum += mark;

   }
   printf("Average = %.2lf", sum / SIZE);
*/
/*
double max = -1;

for (i = 0; i < SIZE; i++){

    do {
        printf("Enter Marks %d, ", i + 1);
        scanf("%lf" ,&mark);
        if (mark < 0 || mark > 100){
            printf("Invalid Mark, Enter Again!...\n");
        }
    }while (mark < 0 || mark > 100};
   
   sum += mark;
   if (i == 0){
    max = mark;
   }
   else {

    if (mark > max){
        max = mark;
    }
   }

   }
   printf("Average = %.2lf", sum / SIZE);*/

   //double marks[5] = { 11,22,34.5,67,89 };

   //printf("1 Element of the array is : %.2lf\n", marks[0]);
   //printf("2 Element of the array is : %.2lf\n", marks[1]);
   //printf("3 Element of the array is : %.2lf\n", marks[2]);

   double marks[SIZE]; sum = 0; min = 101, max = -1;
   int stId[SIZE], i;

   for(i = 0; i < SIZE; i++) {

printf("Enter ST : %d ID: ", i + 1);
scanf("%lf" , &stId[i]);

do {
printf("Enter ST : %d mark: ", i + 1);
scanf("%lf" , &marks[i]);
if (makrs[i] < 0 || makrs[i] > 100){
    print("Invalid Marks, Enger Again !!!\n");
}
} while 
   }

printf("\nYOun Entered...\n");
for (i = 0; i < SIZE; i++ );
printf("ST:%d ID=%d -- mark=0.2lf\n : ", i + 1, stId[i],marks[i])
   

  



    return 0;
}
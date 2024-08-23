#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void){

    /*int age;
    printf ("Enter passenger's Age : ");
    scanf("%d", &age);

    /*if(age >18){
        printf("Adult Pay 10$\n");
    }else {
         printf("Teenager pay 5$\n");   
    }*/


   /* if(age <18){
        printf("Adult Pay 10$\n");
    }else if(age >=18 && age <55){
         printf("Teenager pay 5$\n");   
    }
    else {
        printf("Senior Pay 15$\n");
    }*/

    /*if(age  <= 0 || age > 120){
        printf("AInvalid Age\n");

    }else if(age <18){
         printf("Teenager pay 5$\n");   
    }else if (age <55) {
        printf("Adult Pay 10$\n");
    }else {
        printf("Senior Pay 15$\n");
    }

    int term;
    double loanAmt , rt;
    char type;

    printf("Enter Loan Amount: ");
    scanf("%lf%*c", &loanAmt);
    printf("Enter Loan Amount: ");
    scanf("%c%*c", &type);
    printf("Enter Loan Amount: ");
    scanf("%d%*d", &term);

   /* if(type == 'c') {

        if (term == 1){
            printf("Interest = 6.99%%\n");
        }
        else {
            printf("Interest = 6.99%%\n");
        }*/

/*
        if (type == 'c' && term == 1){


        }
        else if (type == 'c' && term == 5){

    }
    //!(term == 1 || term ==5)

    // !(term == 1 && term += 5) || (type!='c' && type!='h'{
    if(term != 1 && != 5) || (type !='c' && type !='h')){
        printf("Invalid Type or term");
        rt: -1;
    }
    else if (type == 'c' && term == 1){
        printf("Interest = 6.99%%\n");
        rt = 6.99;
    }
    else if (type == 'c' && term == 5){
        printf("Interest = 5.99%%\n");
        rt = 5.99;
    }
     else if (type == 'h' && term == 1){
        printf("Interest = 4.99%%\n");
        rt = 4.99;
    }
    else{
        printf("Interest = 4.75%%\n");
        rt = 4.75;
    }



printf("Interst is : 0.2lf\n", (rt/100/12)*loanAmt)

*/

/*
printf("1. Enter a|A to order Sandwich\n");
printf("2. Enter b|B to order Burger\n");
printf("3. Enter c|C to order Coffee\n");

chart choice

printf("Enter Choice: ");
scanf("%d%*c", &choice);

switch(choice){

    case 'a':
    case 'A': 
    printf("Ordered a Sandwich\n");
    break;

    case 'b':
    case 'B': 
    printf("Ordered a Burger\n");
    break;

    case 'c':
    case C: 
    printf("Ordered a Coffee\n");
    break;
    default:
        printf("Invalid Input\n")
}


*/

    double busFare;
    int age;

    printf("Enger Age :  ");
    scanf("%D%*c, &age");

    printf("Your BusFare = %.2lf\n", busFare);
    

    
    return 0;

}
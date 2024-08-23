#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{ /*int num1;
  float num2;
  double num3;
  char val;

  double number1, number2, result;
  printf("Enter First Number : ");
  scanf("%lf", &number1); 

  printf("Enter Second Number: ");
  scanf("%lf", &number2);

  result = number1+number2;

  printf("NUM1: %lf NUM2: %lf Result is XX%.2lf\n", number1, number2, result );
  printf("NUM1: %lf NUM2: %lf Result is XX%-10.2lf\n", number1, number2, result );

*/

 /*int x = 30;
 int y= 60;

 double result = x / (double)y;

 printf("RESULT = %lf\n", result);*/

  /*int mins;
  double hrs;
  printf("Enter minutes: ");
  scanf("%d", &mins);

  hrs + (double)mins / 60;

  printf("Hrs in %d minutes is : %0.2lf\n", mins, hrs); */

  /*int x = 4;
  double y = 8.99;

  int z = x * y ; */

  double val = 3.467;  // Round is up to 2 demimal places. (3.47)
  /*
  1. If you want to round up to let's say A decimal places
    add 0.(A zeros)5
    As an example, if A is 2 add 0.005, 
                   if A is 3 add 0.0005 to the number
  2. Multiply (result from #1) by 1(A zeros)
                   if A is 2 multiple by 100
                   if A is 3 multiple by 1000
  3. Truncate the demimal values of (above result) by assigning to an int.
  4. Divide the reulst from above (by the same amount you multiplied in #2)
     but maek sure to cast (or add a .) to get a decimal output
  */

/*
val = (val+0.005);
printf("val is %lf\n", val);
val = val *200;
printf("val is %lf\n", val);
int val1 = val;
printf("val1 is %d\n", val1);
val = val1/ 100.0;
printf("rounded value is %lf\n", val);
*/

/*
int val1 = (val+0.005) * 100;
val = val1 / 100.0;

printf("rounded value is %lf\n", val);
*/

int x = 5, y = 2;
int z = x % y;

ptinrf()


  




    return 0;
}
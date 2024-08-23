#include <stdio.h>

int main(void)
{
   /*int x = 7, y;

   y = ++x;
   
   printf("X=%d Y=%d\n", x , y);

   ++x;// prefix operator
   x++;// Postfix operator

    int x = 7, y;

    y = x++;
   
   printf("X=%d Y=%d\n", x , y);*/




   /*int x = 7, y = 8, result;

   //x is greater than 9
   result = x > 9;
   printf("Answer = %d \n", result);*/

   int x = 7, y = 8, z = 6, result;

   //x is greater than 9
   result = x > 9;
   printf("Answer = %d \n", x>9);

   //y is not equal to 10
   printf("Answer = %d \n", y != 10);

   // c greater than 5 and y less than 6
   printf("Answer = %d \n", x > 6 && y < 6); 

   //both x and y has to be less than -7
   printf("Answer = %d \n", x < -7 && y < -7);

   //x has to be greater than 5 or y has to be not les than 10
   printf("Answer = %d \n", x > 5 || !(y < 10));//or
   printf("Answer = %d \n", x > 5 || y >= 10);

   //x-y value should be in between -10 and 11 (not inclusive)
   printf("Answer = %d \n", (x-y)-10< && (x-y) <11 );

   //y-x value shoudl be with less than -10 or greater than 30
   printf("Answer = %d \n", (y-x)< -10 || (y-x) >30);

  // x is not less than 5 and y is not greater than 12
   printf("Answer = %d \n", !(x<5) && y <=12 );

  //x and y values are the same
  printf("Answer = %d \n", x == y );

  // x and y are different
  printf("Answer = %d \n", x != y );
  // x is unique from y and z
  printf("Answer = %d \n", x != y && x ! = z );
  //x is not the same as y but is equal to z
  printf("Answer = %d \n", x != y && x == z );

    return 0;
}
#include <stdio.h>


int main() {
	int x = 7, y = 8, z = 6;
	// x is greater than 9
	printf("Answer = %d \n", x > 9);
	// y is not equal to 10
	printf("Answer = %d \n", y != 10);
	// x greater than 6 and y less than 6
	printf("Answer = %d \n", x > 6 && y < 6);
	// both x and y has to be less than -7
	printf("Answer = %d \n", x < -7 && y < -7);
	// x has to be greater than 5 or y has to be not less than 10
	printf("Answer = %d \n", x > 5 || !(y < 10));
	//Or
	printf("Answer = %d \n", x > 5 || y >= 10);

	// x-y value should be in between -10 and 11 (not inclusive)
	printf("Answer = %d \n", (x-y)>-10 && (x-y) < 11);

	// y-x value should be with less than -10 or greater than 30
	printf("Answer = %d \n", (y-x)< -10 || (y-x) > 30);

	//x is not less than 5 and y is not greater than 12
	printf("Answer = %d \n", !(x < 5) && y <= 12);
	 
	// x and y values are the same
	printf("Answer = %d \n", x == y);
	 
	// x  and y are different
	printf("Answer = %d \n", x != y);
	//x  is unique from y and z
	printf("Answer = %d \n", x != y && x != z);
	
	// x is not the same as y but is equal to z
	printf("Answer = %d \n", x != y && x == z);










	return 0;
}




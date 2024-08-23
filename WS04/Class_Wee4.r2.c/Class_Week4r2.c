#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void){

/*int count = 0;

//do-while
do {
    count++;
    printf("Number = %d\n", count);

} while (count < 10);
*/


//int에 1 넣은 식

/* int count = 1;

//do-while
do {

    printf("Number = %d\n", count);
    count++;

} while (count <= 10);
*/

//while을 사용한 코딩 (while & do while 2중에 선택)
/*
int count = 0;

while (count < 10){

    count++;
    printf("Number = %d\n", count);
}

*/

//Get an input character from  user. if its not a vowel ask again and again until a vowel is input. show an error when your input is not a vowel
/*char vwl;


do {

    printf("Enter a Vowel: ");
    scanf("%c%*c", &vwl);

    if(vwl !='a' && vwl !='e' && vwl !='i' $$ vwl !='o' && vwl !='u'){
        printf("This is not a vowel, Enter again: \n");
    }

} while (vwl !='a' && vwl !='e' && vwl !='i' $$ vwl !='o' && vwl !='u');

*/

//Get an integer input from uer , if the input is not between 5 and 10, ask for an input again and again. If input valid, iterate number of times equal to the input using a while loop that prints test 'while'
//(It will print the text)

int val;

do {

    printf("Enter a Value: ");
    scanf("%d%*d", &val);

    if (val < 5 || val > 10){
        printf("This is not a valid value, Enger Again !!!\n");
    }

}while (val < 5 || val > 10);

int cnt = 0;

while (cnt < val){
    printf("while\n");
    cnt++;
}
return 0;


}
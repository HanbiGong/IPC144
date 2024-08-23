#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{

    //char name[41] = {'a','b','c','\0'}; // character arraya
    char name[41] = "abc"; // 위의 표시형식과 같음, string
   //printf("Ente Name : %s\n", name);
   printf("Enter Name: ");
   scanf("%40[^\n]%*c", name); // string에는 %쓰지말기, 최대 41이니까 40쓰기, [^\n] 이걸 쓰니까 누락됐던 이름이 다 나타남, [^\a]로 등록하면, 이름에 a가 들어가기 전까지 나타남 

   printf("YOU ENTERED : %s\n", name);
   

    return 0;
}
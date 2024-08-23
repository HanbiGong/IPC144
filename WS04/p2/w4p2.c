/*
*****************************************************************************
                          Workshop - #4 (P2)
FFull Name  : Hanbi Gong
Student ID#: 111932224
Email      : hgong12@myseneca.ca
Section    : IPC 144

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int Apples, Oranges, Pears, Tomatoes, Cabbages;
int Apples_pick, Oranges_pick, Pears_pick, Tomatoes_pick, Cabbages_pick;
int Decision;

int main(void)
{    
do{
    printf("Grocery Shopping\n"
            "================\n");
do {
    printf("How many APPLES do you need? : ");
    scanf("%d", & Apples);

    if (Apples < 0)
    {
        printf("ERROR: Value must be 0 or more.\n");
    }
 } while (Apples < 0);
     printf("\n");

do {
    printf("How many ORANGES do you need? : ");
    scanf("%d", & Oranges);

    if (Oranges < 0)
    {
        printf("ERROR: Value must be 0 or more.\n");
    }
 } while (Oranges < 0);
    printf("\n");

 do {
    printf("How many PEARS do you need? : ");
    scanf("%d", & Pears);

    if (Pears < 0)
    {
        printf("ERROR: Value must be 0 or more.\n");
    }
 } while (Pears < 0);
    printf("\n");

 do {
    printf("How many TOMATOES do you need? : ");
    scanf("%d", & Tomatoes);

    if (Tomatoes < 0)
    {
        printf("ERROR: Value must be 0 or more.\n");
    }
 } while (Tomatoes < 0);
     printf("\n");

 do {
    printf("How many CABBAGES do you need? : ");
    scanf("%d", & Cabbages);

    if (Cabbages < 0)
    {
        printf("ERROR: Value must be 0 or more.\n");
    }
 } while (Cabbages < 0);
     printf("\n");

printf("--------------------------\n"
       "Time to pick the products!\n"
       "--------------------------\n\n");
  if(Apples > 0)
  {
    do{ 
        printf("Pick some APPLES... how many did you pick? : ");
        scanf("%d",& Apples_pick);

        if(Apples_pick <= 0)
        {
            printf("ERROR: You must pick at least 1!\n");
        }
        else if(Apples_pick > Apples)
        {
            printf("You picked too many... only %d more APPLE(S) are needed.\n",Apples);
        }
        else
        { Apples -= Apples_pick;
                
        if(Apples == 0) 
        printf("Great, that's the apples done!\n\n");

        else
        printf("Looks like we still need some APPLES...\n");
        }
            
        }while(Apples != 0);
  }

 if(Pears > 0)
  {  
    do{ 
        printf("Pick some PEARS... how many did you pick? : ");
        scanf("%d",& Pears_pick);

        if(Pears_pick <= 0)
        {
            printf("ERROR: You must pick at least 1!\n");
        }
        else if(Pears_pick > Pears)
        {
            printf("You picked too many... only %d more PEAR(S) are needed.\n",Pears);
        }
        else
        { Pears -= Pears_pick;
                
        if(Pears == 0) 
        printf("Great, that's the pears done!\n\n");

        else
        printf("Looks like we still need some PEARS...\n");
        }
            
        }while(Pears != 0);
  }          
 if(Cabbages > 0)
   { 
    do{ 
        printf("Pick some CABBAGES... how many did you pick? : ");
        scanf("%d",& Cabbages_pick);

        if(Cabbages_pick <= 0)
        {
            printf("ERROR: You must pick at least 1!\n");
        }
        else if(Cabbages_pick > Cabbages)
        {
            printf("You picked too many... only %d more CABBAGE(S) are needed.\n",Cabbages);
        }
        else
        { Cabbages -= Cabbages_pick;
                
        if(Cabbages == 0) 
        printf("Great, that's the cabbages done!\n\n");

        else
        printf("Looks like we still need some CABBAGES...\n");
        }
            
        }while(Cabbages != 0);
   }

 if(Oranges > 0)
    {
    do{ 
        printf("Pick some ORANGES... how many did you pick? : ");
        scanf("%d",& Oranges_pick);

        if(Oranges_pick <= 0)
        {
            printf("ERROR: You must pick at least 1!\n");
        }
        else if(Oranges_pick > Oranges)
        {
            printf("You picked too many... only %d more ORANGE(S) are needed.\n",Oranges);
        }
        else
        { Oranges -= Oranges_pick;
                
        if(Oranges == 0) 
        printf("Great, that's the oranges done!\n\n");

        else
        printf("Looks like we still need some ORANGES...\n");
        }
            
        }while(Oranges != 0);
    }
 if(Tomatoes > 0)
    {
    do{ 
        printf("Pick some TOMATOES... how many did you pick? : ");
        scanf("%d",& Tomatoes_pick);

        if(Tomatoes_pick <= 0)
        {
            printf("ERROR: You must pick at least 1!\n");
        }
        else if(Tomatoes_pick > Tomatoes)
        {
            printf("You picked too many... only %d more TOMATO(ES) are needed.\n",Tomatoes);
        }
        else
        { Tomatoes -= Tomatoes_pick;
                
        if(Tomatoes == 0) 
        printf("Great, that's the tomatoes done!\n\n");

        else
        printf("Looks like we still need some TOMATOES...\n");
        }
            
        }while(Tomatoes != 0);
    }

        printf("All the items are picked!\n\n"
               "Do another shopping? (0=NO): ");
        scanf("%d",& Decision);
        printf("\n");
        
        }while(Decision != 0);
    
        if(Decision == 0)
        {
            printf("Your tasks are done for today - enjoy your free time!\n");
        }
    
return 0;
}
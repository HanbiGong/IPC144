/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
Full Name  : Hanbi Gong
Student ID#: 111932224
Email      : hgong12@myseneca.ca
Section    : IPC 144

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_LIVES 10
#define MIN_LIVES 1
#define MAX_GAME_PATH 70
#define MIN_GAME_PATH 10
#define MULTIPLE 5

#include <stdio.h>

struct PlayerInfo
{
    int Lives;
    char Symbol;
    int Treasure;
    int History[MAX_GAME_PATH];
};

struct GameInfo 
{
    int Moves;
    int Length;
    int Bombs[MAX_GAME_PATH];
    int Treasure[MAX_GAME_PATH];
};

int main(void)
{
    struct PlayerInfo Player;
    struct GameInfo Game;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");

    printf("PLAYER Configuration\n");
    printf("--------------------\n");

    printf("Enter a single character to represent the player: ");
    scanf("%c",& Player.Symbol);
    do {
        printf("Set the number of lives: ");
        scanf("%d", &Player.Lives);
         
        if (Player.Lives < MIN_LIVES || Player.Lives > MAX_LIVES) {
         printf("     Must be between %d and %d!\n", MIN_LIVES, MAX_LIVES);
    }
} while (Player.Lives < MIN_LIVES || Player.Lives > MAX_LIVES);
    printf("Player configuration set-up is complete\n\n");

    printf("GAME Configuration\n");
    printf("------------------\n");

    do {
    printf("Set the path length (a multiple of %d between %d-%d): ", MULTIPLE, MIN_GAME_PATH, MAX_GAME_PATH);
    scanf("%d", &Game.Length);

    if (Game.Length % MULTIPLE != 0 || Game.Length < MIN_GAME_PATH || Game.Length > MAX_GAME_PATH) {
        printf("     Must be a multiple of %d and between %d-%d!!!\n", MULTIPLE, MIN_GAME_PATH, MAX_GAME_PATH);
    }
} while (Game.Length % MULTIPLE != 0 || Game.Length < MIN_GAME_PATH || Game.Length > MAX_GAME_PATH);


    do {
    printf("Set the limit for number of moves allowed: ");
    scanf("%d", &Game.Moves);
    
    if (Game.Moves < Player.Lives || Game.Moves > (int)(0.75 * Game.Length)) {
        printf("    Value must be between %d and %d\n",Player.Lives, (int)(0.75 * Game.Length));
    }
} while (Game.Moves < Player.Lives || Game.Moves > (int)(0.75 * Game.Length));
printf("\n");

    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n", MULTIPLE);
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",Game.Length);
    
    int i, j;
    for (i = 0; i < Game.Length; i++)
    {
        if (i % MULTIPLE == 0){
            printf("   Positions [%2d-%2d]: ", i + 1, i + MULTIPLE);
        
            for (j = 0; j < MULTIPLE; j++){
                scanf("%d", &Game.Bombs[i+j]);
            }
        }
    }
    printf("BOMB placement set");
    printf("\n\n");

    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n", MULTIPLE);
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",Game.Length);

    for (i = 0; i < Game.Length; i++)
    {
        if (i % MULTIPLE == 0){
            printf("   Positions [%2d-%2d]: ", i + 1, i + MULTIPLE);

            for (j = 0; j < MULTIPLE; j++){
                scanf("%d", &Game.Treasure[i+j]);
            }
        }
    }
    printf("TREASURE placement set\n\n");
    printf("GAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", Player.Symbol);
    printf("   Lives      : %d\n", Player.Lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    printf("Game:\n");
    printf("   Path Length: %d\n", Game.Length);
    printf("   Bombs      : ");
    for (i = 0; i < Game.Length; i++){
        printf("%d", Game.Bombs[i]);
    }
    printf("\n");

    printf("   Treasure   : ");
    for (i = 0; i < Game.Length; i++){
        printf("%d", Game.Treasure[i]);
    }
    printf("\n\n");

    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n\n");

    return 0;
}

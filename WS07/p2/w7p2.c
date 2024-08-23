/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
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
    struct PlayerInfo Player = { 0 };
    struct GameInfo Game = { 0 };

    int Repeat, MoveRepeat, RangeRepeat ;
    int Userposition ;
    const char Mark_Undiscovered = '-' , Mark_Bomb = '!', Mark_Treasure = '$', Mark_BombAndTreasure = '&', Mark_NotBombandTreasure = '.';

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
    
    for (i = 0; i < Game.Length; i++) {
    Player.History[i] =  Mark_Undiscovered;
    }

    do{
        Repeat = 0;

        printf("  ");
    for (i = 0; i < Game.Length; i++){
        printf("%c", Player.History[i]);
    }
    printf("\n");

    printf("  ");
    for (i = 0; i < Game.Length; i++){
        if ((i + 1) % 10 == 0){
            printf("%d", (i + 1) / 10);
        }
        else {
            printf("|");
        }
        }
    printf("\n");
    
    printf("  ");
    for (i = 0; i < Game.Length; i++) {
    printf("%d", (i + 1) % 10);
    }
    printf("\n");

    do{
        MoveRepeat = 0;
        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", Player.Lives , Player.Treasure, Game.Moves);
        printf("+---------------------------------------------------+\n");
    
    if (Player.Lives != 0 && Game.Moves != 0){
        do {
            RangeRepeat = 0;
            printf("Next Move [1-%2d]: ", Game.Length);
            scanf("%d", &Userposition);
            if (Userposition < 1 || Userposition > Game.Length){
                printf("  Out of Range!!!\n");
                RangeRepeat = 1;
            }
        } while (RangeRepeat);
        printf("\n");

    if ((Player.History[Userposition - 1] == '.') || (Player.History[Userposition - 1] == '&') || (Player.History[Userposition - 1] == '$') || (Player.History[Userposition - 1] == '!')){
        printf("===============> Dope! You've been here before!\n\n");
        }
        else if ((Game.Bombs[Userposition - 1] == 0) && (Game.Treasure[Userposition - 1] == 0)){
            printf("===============> [%c] ...Nothing found here... [%c]\n\n", Mark_NotBombandTreasure, Mark_NotBombandTreasure);
            Game.Moves--;
            Player.History[Userposition - 1] = '.';
            }

        else if ((Game.Bombs[Userposition - 1] == 1) && (Game.Treasure[Userposition - 1] == 1)){
            printf("===============> [%c] !!! BOOOOOM !!! [%c]\n", Mark_BombAndTreasure, Mark_BombAndTreasure);
            printf("===============> [%c] $$$ Life Insurance Payout!!! [%c]\n\n", Mark_BombAndTreasure, Mark_BombAndTreasure);
            Player.Lives--;
            Game.Moves--;
            Player.Treasure++;
            Player.History[Userposition - 1] = '&';
            }

        else if (Game.Bombs[Userposition - 1] == 1){
            printf("===============> [%c] !!! BOOOOOM !!! [%c]\n\n", Mark_Bomb, Mark_Bomb);
            Player.Lives--;
            Game.Moves--;
            Player.History[Userposition - 1] = '!';
            }
        
        else if (Game.Treasure[Userposition - 1] == 1){
            printf("===============> [%c] $$$ Found Treasure! $$$ [%c]\n\n", Mark_Treasure, Mark_Treasure);
            Game.Moves--;
            Player.Treasure++;
            Player.History[Userposition - 1] = '$';
            }

    if (Player.Lives == 0){
        printf("No more LIVES remaining!\n\n");
    }
    else if (Game.Moves == 0){
        printf("No more MOVES remaining!\n\n");
    }
    
    printf("  ");
    for (i = 0; i < Userposition - 1; i++)  {
        printf(" ");
    }
    printf("%c\n", Player.Symbol);
    Repeat = 1;
            }
        } while (MoveRepeat);
    } while (Repeat);

    printf("\n");
    printf("##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n\n");
    printf("You should play again and try to beat your score!\n\n");   

    return 0;
}

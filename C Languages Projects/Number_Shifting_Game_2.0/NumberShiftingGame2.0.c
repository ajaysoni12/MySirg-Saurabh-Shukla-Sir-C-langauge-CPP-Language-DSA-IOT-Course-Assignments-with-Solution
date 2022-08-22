#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int ROW, COL, TOTAL_MOVES;
int MATRIX_PUZZEL[4][4];

// Declaration of all function
int WORKING_WITH_KEY(char);
int CHECK_WIN_CONDITION();
void DISPLAY_MATRIX_PUZZEL(char *);
int CHECK_EXISTS(int);
void RANDOME_NUMBER_GENERATED_IN_MATRIXPUZZEL();
void GAME_OF_RULES();
int EXIT_KEY(char key);
void RESTART_THE_GAME();
void DISPLAY_PLAYER_NAME(char[]);
void DISPLAY_PLAYER_TOTAL_MOVES();
void PLAY_GAME(char[]);
void NUMBER_SHIFTING_GAME();

int WORKING_WITH_KEY(char key)
{
    if (key == 75 && COL < 3) // for right
    {
        int temp = MATRIX_PUZZEL[ROW][COL];
        MATRIX_PUZZEL[ROW][COL] = MATRIX_PUZZEL[ROW][COL + 1];
        MATRIX_PUZZEL[ROW][COL + 1] = temp;
        COL++;
        return 1;
    }
    else if (key == 72 && ROW < 3) // for down
    {
        int temp = MATRIX_PUZZEL[ROW][COL];
        MATRIX_PUZZEL[ROW][COL] = MATRIX_PUZZEL[ROW + 1][COL];
        MATRIX_PUZZEL[ROW + 1][COL] = temp;
        ROW++;
        return 1;
    }
    else if (key == 80 && ROW > 0) // for up
    {
        int temp = MATRIX_PUZZEL[ROW][COL];
        MATRIX_PUZZEL[ROW][COL] = MATRIX_PUZZEL[ROW - 1][COL];
        MATRIX_PUZZEL[ROW - 1][COL] = temp;
        ROW--;
        return 1;
    }
    else if (key == 77 && COL > 0) // for left
    {
        int temp = MATRIX_PUZZEL[ROW][COL];
        MATRIX_PUZZEL[ROW][COL] = MATRIX_PUZZEL[ROW][COL - 1];
        MATRIX_PUZZEL[ROW][COL - 1] = temp;
        COL--;
        return 1;
    }
    return 0;
}

int CHECK_WIN_CONDITION()
{
    int count = 0, i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            count++; // according to winning condition all num are sorted so we create count variable and update continuesoly
            if (MATRIX_PUZZEL[i][j] != count)
                return 0;
            if (count == 15)
                break;
        }
    }
    return 1;
}

void DISPLAY_MATRIX_PUZZEL(char playerName[])
{
    int i, j;
    DISPLAY_PLAYER_NAME(playerName);
    DISPLAY_PLAYER_TOTAL_MOVES();
    printf("\n\tYOU CAN EXIT THE GAME BY PRESSING 'E' OR 'e' DOUBLE TIME!"); // double because if user press e or E by mistake
    fflush(stdin);
    printf("\n---------------------\n");
    for (i = 0; i < 4; i++)
    {
        printf("|");
        for (j = 0; j < 4; j++)
        {
            if (MATRIX_PUZZEL[i][j] == 32)
                printf("%3c |", 32);
            else
                printf("%3d |", MATRIX_PUZZEL[i][j]);
        }
        printf("\n");
    }
    printf("---------------------\n");
}

int CHECK_EXISTS(int randomeVal)
{
    int i, j;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            if (MATRIX_PUZZEL[i][j] == randomeVal)
                return 0;
    return 1;
}

void RANDOME_NUMBER_GENERATED_IN_MATRIXPUZZEL()
{
    int i, j, flag = 1, randomeVal;
    srand(time(0)); // per execution randome number different generate
    for (i = 0; i < 4; i++)
    {
        j = 0;
        while (j < 4)
        {
            randomeVal = rand() % 16 + 1; // %16 means i need only 1 - 15
            if (CHECK_EXISTS(randomeVal)) // this function check any number should not be repeated
            {
                MATRIX_PUZZEL[i][j] = randomeVal;
                j++;
            }
        }
    }

    // Here we find 16, and convert 32 for space
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (MATRIX_PUZZEL[i][j] == 16)
            {
                ROW = i, COL = j;
                break;
            }
        }
    }
    MATRIX_PUZZEL[ROW][COL] = 32; // assign 32 for space
}

void GAME_OF_RULES()
{
    system("cls");
    printf("\t\t\t\"NUMBER SHIFTING GAME 2.0\"");

    printf("\n\n\tSOME BASIC RULE OF THIS GAME, YOU DEFINITLY UNDERSTANTD!");

    printf("\n\nRULE NO.1  - YOU CAN MOVE ONLY 1 STEPS AT A TIME BY ARROWS KEY!");
    printf("\n\t\tMOVE UP : by up arrow key");
    printf("\n\t\tMOVE DOWN : by Down Arrow key");
    printf("\n\t\tMOVE LEFT : by Left Arrow key");
    printf("\n\t\tMOVE RIGHT : by Right Arrow key");

    printf("\n\nRULE NO.2 - YOU CAN MOVE NUMBER AT EMPTY POSITION ONLY!");

    printf("\n\nRULE NO.3 - FOR EACH VALID MOVE YOUR TOTAL NUMBER OF MOVE WILL BE DECREASED BY 1!");

    printf("\n\nRULE NO.4 - WINNING SITUATION, NUMBER IN 4*4 MATRIX BE IN SORTED ORDER FROM 1 TO 15!");

    printf("\n\n\t\tWINNING SITUATION");
    printf("\n-------------------------\n");
    printf("|  1  |  2  |  3  |  4  |\n");
    printf("|  5  |  6  |  7  |  8  |\n");
    printf("|  9  | 10  | 11  | 12  |\n");
    printf("| 13  | 14  | 15  |     |");
    printf("\n-------------------------\n");

    printf("\nRULE NO.5 - YOU CAN EXIT THE GAME AT ANY TIME BY PRESSING 'E' OR 'e' DOUBLE TIME!"); // double because if user press e or E by mistake

    printf("\n\nSO TRY TO WIN THE GAME IN MINIMUM NO. OF MOVE!");

    printf("\nPRESS ANY KEY TO CONTINUE....");
    getch();
    getch();
}

int EXIT_KEY(char key)
{
    if (key == 'E' || key == 'e')
        return 0;
    return 1;
}

void RESTART_THE_GAME()
{
    system("cls");
    char opt;
    printf("\n\n\tPRESS 'Y' FOR YES OR PRESS 'N' FOR NO");
    while (1)
    {
        printf("\nCHOOSE YOUR OPTION: ");
        scanf("%c", &opt);
        if (opt == 'Y')
            NUMBER_SHIFTING_GAME();
        else if (opt == 'N')
        {
            printf("\nTHANK-YOU FOR PLAYING GAME, VISIT AGAIN!");
            exit(0);
        }
        else
            printf("\nWRONG OPTION!");
    }
}

int CHOOSE_LEVEL_OF_GAME()
{
    int level;
    system("cls");
    printf("\n\tLEVELS OF NUMBER SHIFTING GAME");
    printf("\n\t\tLevel 1 - BEGINNER");
    printf("\n\t\tLevel 2 - INTERMEDIATE");
    printf("\n\t\tLevel 3 - ADVANCED");
    printf("\n\t\tLevel 4 - MASTER");
    printf("\n\t\tLevel 5 - STREAMERS");
    printf("\n\t\tLevel 6 - PERSONALITIES");
    while (1)
    {
        printf("\nCHOOSE YOUR LEVEL: ");
        scanf("%d", &level);
        if (level < 1 || level > 6)
            printf("\n\nENTER LEVEL NO. NOT AVAIABLE!");
        else
            break;
    }
    return level;
}

void NUMBER_SHIFTING_GAME()
{
    char playerName[20];
    int levelOfGame;
    printf("\t\t\t\"Welcome to Number Shifting Game\"");
    printf("\n\nEnter Player Name: ");
    gets(playerName);
    GAME_OF_RULES();
    RANDOME_NUMBER_GENERATED_IN_MATRIXPUZZEL();
    levelOfGame = CHOOSE_LEVEL_OF_GAME();
    switch (levelOfGame)
    {
    case 1:
        TOTAL_MOVES = 500;
        PLAY_GAME(playerName);
        break;
    case 2:
        TOTAL_MOVES = 400;
        PLAY_GAME(playerName);
        break;
    case 3:
        TOTAL_MOVES = 300;
        PLAY_GAME(playerName);
        break;
    case 4:
        TOTAL_MOVES = 200;
        PLAY_GAME(playerName);
        break;
    case 5:
        TOTAL_MOVES = 100;
        PLAY_GAME(playerName);
        break;
    case 6:
        TOTAL_MOVES = 50;
        PLAY_GAME(playerName);
        break;
    }
}

void PLAY_GAME(char playerName[])
{
    while (1)
    {
        char arrowKey;
        system("cls");
        DISPLAY_MATRIX_PUZZEL(playerName);
        printf("\nPRESS ANY ARROW KEY...");
        arrowKey = getch();
        arrowKey = getch();
        fflush(stdin);
        if (EXIT_KEY(arrowKey))
        {
            if (WORKING_WITH_KEY(arrowKey))
                TOTAL_MOVES--;

            if (CHECK_WIN_CONDITION())
            {
                printf("\n\nCONGRATULATIONS!, YOU WIN THE GAME");
                printf("\nPRESS ANY KEY.....");
                getch();
                RESTART_THE_GAME();
            }
        }
        else // For Exit Purpose
        {
            printf("\n\nYOU ENTER 'E' OR 'e' KEYS FOR EXITS!");
            printf("\nPRESS ANY KEY.....");
            getch();
            RESTART_THE_GAME();
        }

        if (TOTAL_MOVES == 0)
        {
            printf("\n\nOOPS!, YOU LOSS THE GAME! YOUR TOTAL MOVES WILL BE EMPTY!");
            printf("\nPRESS ANY KEY.....");
            getch();
            RESTART_THE_GAME();
        }
    } // while loop body
}

void DISPLAY_PLAYER_NAME(char playerName[])
{
    printf("\n\n\tPLAYER NAME: %s", playerName);
}

void DISPLAY_PLAYER_TOTAL_MOVES()
{
    printf("\n\tREMAINING MOVES OF GAME: %d", TOTAL_MOVES - 1);
}

int main()
{
    NUMBER_SHIFTING_GAME();
    return 0;
}
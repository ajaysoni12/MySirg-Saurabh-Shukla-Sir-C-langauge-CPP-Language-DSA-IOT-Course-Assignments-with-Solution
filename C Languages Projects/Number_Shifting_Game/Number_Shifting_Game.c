#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
int row, col;
int workKey(int arr[][4], char key)
{
    system("cls");
    int flag = 0;
    if (key == 75) // for left
    {
        if (col > 0)
        {
            int temp = arr[row][col];
            arr[row][col] = arr[row][col - 1];
            arr[row][col - 1] = temp;
            col--;
        }
        flag = 1;
    }
    else if (key == 72) // up
    {
        if (row > 0)
        {
            int temp = arr[row][col];
            arr[row][col] = arr[row - 1][col];
            arr[row - 1][col] = temp;
            row--;
        }
        flag = 1;
    }
    else if (key == 80) // down
    {
        if (row < 3)
        {
            int temp = arr[row][col];
            arr[row][col] = arr[row + 1][col];
            arr[row + 1][col] = temp;
            row++;
        }
        flag = 1;
    }
    else if (key == 77) // right
    {
        if (col < 3)
        {
            int temp = arr[row][col];
            arr[row][col] = arr[row][col + 1];
            arr[row][col + 1] = temp;
            col++;
        }
        flag = 1;
    }
    if (flag)
        return 1; // if user press arrow key
    return 0;     // if user press remaining another key means it's exists
}

int check_win_condition(int arr[][4])
{
    int count = 0;
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            count++; // according to winning condition all num are sorted so we create count variable and update continuesoly
            if (arr[i][j] != count)
                return 0;
        }
    }
    return 1;
}
void display(int arr[][4], int totalMove, char name[])
{
    printf("Player Name: %s", name);
    printf("Total Remaining Move: %d\n", totalMove);
    int i, j;
    printf("---------------------\n");
    for (i = 0; i < 4; i++)
    {
        printf("|");
        for (j = 0; j < 4; j++)
        {
            if (arr[i][j] == 32)
                printf("%3c |", 32);
            else
                printf("%3d |", arr[i][j]);
        }
        printf("\n");
    }
    printf("---------------------\n");
}
int check_exist(int arr[][4], int randome)
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (arr[i][j] == randome)
                return 0;
        }
    }
    return 1;
}
void randNumGen(int arr[][4])
{
    int i, j, flag = 1, randome;
    srand(time(0)); // per execution randome number different generate
    for (i = 0; i < 4; i++)
    {
        j = 0;
        while (j < 4)
        {
            randome = rand() % 16 + 1;     // %16 means i need only 1 - 15
            if (check_exist(arr, randome)) // this function check any number should not be repeated
            {
                arr[i][j] = randome;
                j++;
            }
        }
    }

    // Here we find 16, and convert 32 for space
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (arr[i][j] == 16)
            {
                row = i, col = j;
                break;
            }
        }
    }
    arr[row][col] = 32; // assign 32 for space
}

int menu()
{
    system("cls");
    char yesNo;
    printf("\t\t\tMATRIX PUZZULE");
    printf("\n\t\t     RULE OF THIS GAME  \n\n");

    printf("\n1. You can move only 1 steps at a time by arrow key\n");
    printf("\t\tMove Up : by Up Arrow key\n");
    printf("\t\tMove Down : by Down Arrow key\n");
    printf("\t\tMove Left : by Left Arrow key\n");
    printf("\t\tMove Right : by Right Arrow key\n");

    printf("\n2. You can move number at empty position only \n");

    printf("\n3. For each valid move : your total number of move will dicreased by 1\n");

    printf("\n4. Winning situation : number in a 4*4 matrix be in order from 1 to 15\n");

    printf("\n\n\tWinning Situation");
    printf("\n-------------------------\n");
    printf("|  1  |  2  |  3  |  4  |\n");
    printf("|  5  |  6  |  7  |  8  |\n");
    printf("|  9  | 10  | 11  | 12  |\n");
    printf("| 13  | 14  | 15  |     |");
    printf("\n-------------------------\n");
    printf("\n5. You can exit the game at any time by Pressing any key(Left ArrowKeys) \n");
    printf("\nSo try to win in minimum no. of move!");
    printf("\nPress 'Y' or 'y' key for continue......\n");
    scanf("%c", &yesNo);
    system("cls");
    if (yesNo == 'Y' || yesNo == 'y')
        return 1;
    return 0;
}

int main()
{
    int totalMoves = 50, flag = 1; // totalMoves given - 50
    char arrowKey, opt;            // take user input from arrowkey
    int randNum[4][4];             // randome Number Generate in Matrix
    char userName[30];             // take UserName

    printf("Enter your name: ");
    fgets(userName, 30, stdin); // input userName

    randNumGen(randNum); // Fill Randome Num in Matrix

    if (menu()) // First we show our menu if user press Y means continue or N means N. it all handle this if conditions
    {
        while (totalMoves--)
        {
            display(randNum, totalMoves, userName); // Display matrix, username, and totalMoves
            arrowKey = getch();
            arrowKey = getch();

            if (!workKey(randNum, arrowKey))
                exit(0); // if user don't press arrow key

            if (check_win_condition(randNum))
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            printf("You loss!");
        else
            printf("You Won!");

        fflush(stdin);
        printf("\nDo you want to play again if yes to press 'y' or 'Y', either press 'n' or 'N' ");
        scanf("%c", &opt);
        if (opt == 'Y')
            main();
        else
        {
            printf("\nVisit again!");
            exit(0);
        }
    }
    else
    {
        printf("\nVisit again!");
        exit(0);
    }

    return 0;
}

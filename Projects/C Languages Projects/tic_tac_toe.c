#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

int N; // Matrix Dimenstion

// function declrations
int main();
void createMatrix(int[][N]);
void ticTacToeGameRules();
int newGame();
int getIntOnly();
void restartTheGame();
void gameDiscription();
void displayGame(int[][N]);
char checkWinner(int[][N]);
void putSymbol(int[][N], char, int);
int checkPlaceIsValid(int[][N], int);
void playWithFriend(int[][N]);
void displayPlayersNameWithSymbol(char[], char, char[], char);
void playWithSmartOrEvilComputer(int[][N], int);
int computerMove(int[][N], int);

int main()
{
    gameDiscription();
    system("cls");
    printf("HERE, YOU ENTER TIC TAC TOE BOARD SIZE IN DIMENSION N*N\n\tENTER THE VALUE OF N: ");
    while (1)
    {
        N = getIntOnly(); // Input Intger type value only 
        if (N != -1)
        {
            printf("\n\tYOU ENTERD %d*%d TIC TAC BOARD\n\tCONTINUE.....", N, N);
            getch();
            break;
        }
        else
        {
            printf("\nINVALID INPUT..!!  CONTINUE...");
            getch();
        }
    }
    int matrix[N][N];
    createMatrix(matrix);
    char choice = newGame();
    switch (choice)
    {
    case '1':
        playWithSmartOrEvilComputer(matrix, 1);
        break;
    case '2':
        playWithSmartOrEvilComputer(matrix, 2);
        break;
    case '3':
        playWithFriend(matrix);
        break;
    case '4':
        printf("THANKU, FOR PLAYING THE GAME, VISIT AGAIN!");
        exit(0);
    }

    return 0;
}
void createMatrix(int matrix[][N])
{
    int i, j;
    int count = 0;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            matrix[i][j] = ++count;
}
int newGame()
{
    while (1)
    {
        fflush(stdin);
        system("cls");
        char choice;
        printf("\n\t-----NEW GAME-----\n\n1 - PLAY WITH SMART COMPUTER\n2 - PLAY WITH EVIL COMPUTER\n3 - PLAY WITH FRIEND\n4 - EXIT THE GAME\n\tENTER YOUR CHOICE: ");
        scanf("%c", &choice);
        if (choice == '1' || choice == '2' || choice == '3' || choice == '4')
            return choice;
        else
        {
            printf("\n\tINVALID INPUT... TRY AGAIN!\nPRESS ANY KEY..");
            getch();
        }
    }
}
void ticTacToeGameRules()
{
    system("cls");
    printf("\n\tGAME OF RULES\n\nRULE NO.1 - X(symbol) MOVES FIRST\n\nRULE NO.2 - A PIECE MAY BE PLACED ON ANY EMPTY SPACE\n\nRULE NO.3 - A PLAYER WINS BY BEING THE FIRST TO CONNECT A LINE OF FRIENDLY PIECES FROM ONE SIDE OR CORNER OF THE BOARD TO THE OTHER\n\nRULES NO.4 - THE GAME ENDS WHEN EITHER ONE PLAYER WINS OR IT IS NO LONGER POSSIBLE FOR A PLAYER TO WIN (IN WHICH CASE THE RESULT IS A DRAW)\n\n\tPRESS ANY KEY TO CONTINUE....");
    getch();
}
void gameDiscription()
{
    system("cls");
    char choice;
    printf("\n\t--------TIC-TAC-TOE GAME---------\n\n\n\tPRESS-1 FOR SEE TIC-TAC-TOE GAME RULE\n\tPRESS-2 FOR CONTINUE...\n");
    while (1)
    {
        fflush(stdin);
        printf("\nENTER YOUR CHOICE: ");
        scanf("%c", &choice);
        if (choice == '1')
        {
            ticTacToeGameRules();
            break;
        }
        else if (choice == '2')
            break;
        else
            printf("\tINVALID INPUT... TRY AGAIN!");
    }
}
int checkPlaceIsValid(int matrix[][N], int markPlace)
{
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            if (matrix[i][j] == markPlace)
                return 0; // Found
    return 1;             // notFound
}
int getIntOnly()
{
    int inputData;
    int flag = scanf("%d", &inputData);
    if (flag == 1)
        return inputData;
    return -1;
}
void displayPlayersNameWithSymbol(char firstPlayerName[], char firstPlayerSymbol, char secondPlayerName[], char secondPlayerSymbol)
{
    system("cls");
    printf("\nFIRST PLAYER NAME - %s, AND YOUR SYMBOL IS: 'X'", firstPlayerName);
    printf("\nSECOND PLAYER NAME - %s, AND YOUR SYMBOL IS: 'O'\n", secondPlayerName);
    printf("\n\tYOU CANE EXIT THE GAME ANY TIME, JUST TYPE 100 FOR EXIT THE GAME  \"OR\"  FOR NEW GAME 101\n\n");
}
void displayGame(int matrix[][N])
{
    printf("\n   ----------------TIC-TAC-TOE-GAME------------------\n");
    int i, j;
    for (i = 0; i < N; i++)
    {
        printf("\n\t\t  ");
        for (j = 0; j < N; j++)
        {
            if (matrix[i][j] == 'X' || matrix[i][j] == 'O')
                printf("%5c", matrix[i][j]);
            else
                printf("%5d", matrix[i][j]);
        }
        printf("\n\n");
    }
}
void restartTheGame()
{
    while (1)
    {
        system("cls");
        char choice;
        fflush(stdin);
        printf("\n\tDO YOU WANT TO PLAY AGAIN!\n1 - YES\n2 - NO\n\tENTER YOUR CHOICE: ");
        scanf("%c", &choice);
        if (choice == '1')
            main();
        else if (choice == '2')
        {
            printf("THANKU, FOR PLAYING THE GAME, VISIT AGAIN!");
            exit(0);
        }
        else
        {
            printf("\n\tINVALID INPUT.... TRY AGAIN!\n\tPRESS ANY KEY...");
            getch();
        }
    }
}
void playWithFriend(int matrix[][N])
{
    system("cls");
    int markPlace, totalMoves = N * N, alternate = 1;
    char firstPlayerSymbol = 'X', secondPlayerSymbol = 'O';
    char firstPlayerName[20], secondPlayerName[20];
    printf("\n\n\t----PLAY WITH FIREND----\n\nENTER FIRST PLAYER NAME: ");
    fflush(stdin);
    gets(firstPlayerName);
    printf("%s...\tYOUR SYMBOLS IS: '%c'\n\tPRESS ANY KEY....", firstPlayerName, firstPlayerSymbol);
    getch();
    system("cls");
    fflush(stdin);
    printf("\nENTER SECOND PLAYER NAME: ");
    gets(secondPlayerName);
    printf("%s...\tYOUR SYMBOLS IS: '%c'\n\tPRESS ANY KEY....", secondPlayerName, secondPlayerSymbol);
    getch();

    while (1)
    {
        system("cls");
        displayPlayersNameWithSymbol(firstPlayerName, firstPlayerSymbol, secondPlayerName, secondPlayerSymbol);
        displayGame(matrix);
        alternate ? printf("%s, ENTER MARKING PLACE:\t", firstPlayerName) : printf("%s, ENTER MARKING PLACE:\t", secondPlayerName);
        markPlace = getIntOnly();
        if ((markPlace >= 1 && markPlace <= N * N) && !checkPlaceIsValid(matrix, markPlace))
        {
            alternate ? putSymbol(matrix, 'X', markPlace) : putSymbol(matrix, 'O', markPlace);
            char result = checkWinner(matrix);
            if (result == 'X')
            {
                system("cls");
                displayPlayersNameWithSymbol(firstPlayerName, firstPlayerSymbol, secondPlayerName, secondPlayerSymbol);
                displayGame(matrix);
                printf("\n\tCONGRATULATIONS! %s, FOR WIN THE GAME...!!\nPRESS ANY KEY.......", firstPlayerName);
                getch();
                restartTheGame();
            }
            else if (result == 'O')
            {
                system("cls");
                displayPlayersNameWithSymbol(firstPlayerName, firstPlayerSymbol, secondPlayerName, secondPlayerSymbol);
                displayGame(matrix);
                printf("\n\tCONGRATULATIONS! %s, FOR WIN THE GAME...!!\nPRESS ANY KEY.......", secondPlayerName);
                getch();
                restartTheGame();
            }
            if (--totalMoves == 0)
            {
                system("cls");
                displayPlayersNameWithSymbol(firstPlayerName, firstPlayerSymbol, secondPlayerName, secondPlayerSymbol);
                displayGame(matrix);
                printf("\n\tOOPS!, MATCH IS DRAW..!!\nPRESS ANY KEY.......");
                getch();
                restartTheGame();
            }
            alternate = !alternate;
        }
        else if (markPlace == 100)
        {
            printf("\nYOU ENTER 100 FOR EXIT...!\n\tBYE..");
            exit(0);
        }
        else if (markPlace == 101)
        {
            printf("\nYOU ENTER 101 FOR NEW GAME....!\n\tPRESS ANY KEY....");
            getch();
            main();
        }
        else
        {
            printf("\n\tINVALID INPUT OR ALREADY TAKE! TRY AGAIN....\nPRESS ANY KEY FOR CONTINUE....");
            fflush(stdin);
            getch();
        }
    }
}
char checkWinner(int matrix[][N])
{
    int chX, chO, i, j;
    // row
    for (i = 0; i < N; i++)
    {
        j = 0, chX = 0, chO = 0;
        while (j < N)
        {
            if (matrix[i][j] == 'X')
                chX++;
            if (matrix[i][j] == 'O')
                chO++;
            j++;
        }
        if (chX == N)
            return 'X';
        else if (chO == N)
            return 'O';
    }

    // col
    for (i = 0; i < N; i++)
    {
        int j = 0;
        chX = 0, chO = 0;
        while (j < N)
        {
            if (matrix[j][i] == 'X')
                chX++;
            if (matrix[j][i] == 'O')
                chO++;
            j++;
        }
        if (chX == N)
            return 'X';
        else if (chO == N)
            return 'O';
    }

    // for left digonal
    chX = 0, chO = 0;
    for (i = 0, j = 0; i < N; i++, j++)
    {
        if (matrix[i][j] == 'X')
            chX++;
        if (matrix[i][j] == 'O')
            chO++;
    }
    if (chX == N)
        return 'X';
    else if (chO == N)
        return 'O';

    // for right diagonal
    chX = 0, chO = 0;
    for (i = 0, j = (N - 1); i < N; i++, j--)
    {
        if (matrix[i][j] == 'X')
            chX++;
        if (matrix[i][j] == 'O')
            chO++;
    }
    if (chX == N)
        return 'X';
    else if (chO == N)
        return 'O';

    return 'A';
}
void putSymbol(int matrix[][N], char symbol, int markPlace)
{
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            if (matrix[i][j] == markPlace)
            {
                matrix[i][j] = symbol;
                break;
            }
}
void playWithSmartOrEvilComputer(int matrix[][N], int whoose)
{
    system("cls");
    int markPlace, totalMoves = N * N, alternate = 1;
    char firstPlayerName[20], secondPlayerName[20];
    char firstPlayerSymbol = 'X', secondPlayerSymbol = 'O';
    printf("\n\n\t----PLAY WITH SMART COMPUTER----\n");
    printf("\nENTER PLAYER NAME: ");
    fflush(stdin);
    gets(firstPlayerName);
    system("cls");
    printf("%s, YOUR SMBOLS IS: %c\n", firstPlayerName, firstPlayerSymbol);
    if (whoose == 1)
        strcpy(secondPlayerName, "SMART COMPUTER");
    else
        strcpy(secondPlayerName, "EVIL COMPUTER");
    printf("%s, YOUR SMBOLS IS: %c\n", secondPlayerName, secondPlayerSymbol);
    printf("\nPRESS ANY KEY...");
    getch();

    while (1)
    {
        system("cls");
        displayPlayersNameWithSymbol(firstPlayerName, firstPlayerSymbol, secondPlayerName, secondPlayerSymbol);
        displayGame(matrix);
        printf("%s, ENTER MARKING PLACE:\t", firstPlayerName);
        markPlace = getIntOnly();
        if ((markPlace >= 1 && markPlace <= N * N) && !checkPlaceIsValid(matrix, markPlace))
        {
            putSymbol(matrix, 'X', markPlace);
            char result = checkWinner(matrix);
            if (result == 'X')
            {
                system("cls");
                displayPlayersNameWithSymbol(firstPlayerName, firstPlayerSymbol, secondPlayerName, secondPlayerSymbol);
                displayGame(matrix);
                printf("\n\tCONGRATULATIONS! %s, FOR WIN THE GAME...!!\nPRESS ANY KEY.......", firstPlayerName);
                getch();
                restartTheGame();
            }
            if (--totalMoves == 0)
            {
                system("cls");
                displayPlayersNameWithSymbol(firstPlayerName, firstPlayerSymbol, secondPlayerName, secondPlayerSymbol);
                displayGame(matrix);
                printf("\n\tOOPS!, MATCH IS DRAW..!!\nPRESS ANY KEY.......");
                getch();
                restartTheGame();
            }
            int temp = computerMove(matrix, whoose);
            totalMoves = totalMoves - temp;
            result = checkWinner(matrix);
            if (result == 'O')
            {
                system("cls");
                displayPlayersNameWithSymbol(firstPlayerName, firstPlayerSymbol, secondPlayerName, secondPlayerSymbol);
                displayGame(matrix);
                printf("\n\tOPPS...! %s YOUR LOSE THE GAME...!!  %s WIN THE GAME\nPRESS ANY KEY.......", firstPlayerName, secondPlayerName);
                getch();
                restartTheGame();
            }
            if (totalMoves <= 0)
            {
                system("cls");
                displayPlayersNameWithSymbol(firstPlayerName, firstPlayerSymbol, secondPlayerName, secondPlayerSymbol);
                displayGame(matrix);
                printf("\n\tOOPS!, MATCH IS DRAW..!!\nPRESS ANY KEY.......");
                getch();
                restartTheGame();
            }
        }
        else if (markPlace == 100)
        {
            printf("\nYOU ENTER 100 FOR EXIT...!\n\tBYE..");
            exit(0);
        }
        else if (markPlace == 101)
        {
            printf("\nYOU ENTER 101 FOR NEW GAME....!\n\tPRESS ANY KEY....");
            getch();
            main();
        }
        else
        {
            printf("\n\tINVALID INPUT OR ALREADY TAKE! TRY AGAIN....\nPRESS ANY KEY FOR CONTINUE....");
            fflush(stdin);
            getch();
        }
    }
}
int computerMove(int matrix[][N], int whose)
{
    int i, j, count, num = 0, flag = 0, ct = 0;
    if (whose == 1)
    {
        while (1)
        {
            num++;
            for (i = 0; i < N; i++)
            {
                count = 0;
                for (j = 0; j < N; j++)
                {
                    if (matrix[i][j] == 'O')
                        count++;
                }
                if (count == N - num)
                {
                    for (j = 0; j < N; j++)
                    {
                        if (matrix[i][j] != 'O' && matrix[i][j] != 'X')
                        {
                            matrix[i][j] = 'O';
                            flag = 1;
                            return 1;
                        }
                    }
                }

                count = 0;
                for (j = 0; j < N; j++)
                {
                    if (matrix[j][i] == 'O')
                        count++;
                }
                if (count == N - num)
                {
                    for (j = 0; j < N; j++)
                    {
                        if (matrix[j][i] != 'O' && matrix[j][i] != 'X')
                        {
                            matrix[j][i] = 'O';
                            flag = 1;
                            return 1;
                        }
                    }
                }
            }

            count = 0;
            for (i = 0, j = 0; i < N; i++, j++)
            {
                if (matrix[i][j] == 'O')
                    count++;
            }
            if (count == N - num)
            {
                for (i = 0, j = 0; j < N; i++, j++)
                {
                    if (matrix[i][j] != 'O' && matrix[i][j] != 'X')
                    {
                        matrix[i][j] = 'O';
                        flag = 1;
                        return 1;
                    }
                }
            }
            count = 0;
            for (i = 0, j = N - 1; i < N; i++, j--)
            {
                if (matrix[i][j] == 'O')
                    count++;
            }
            if (count == N - num)
            {
                for (i = 0, j = N - 1; j >= 0; i++, j--)
                {
                    if (matrix[i][j] != 'O' && matrix[i][j] != 'X')
                    {
                        matrix[i][j] = 'O';
                        flag = 1;
                        return 1;
                    }
                }
            }

            for (i = 0; i < N; i++)
            {
                // for row
                count = 0;
                for (j = 0; j < N; j++)
                {
                    if (matrix[i][j] == 'X')
                        count++;
                }
                if (count == N - num)
                {
                    for (j = 0; j < N; j++)
                    {
                        if (matrix[i][j] != 'X' && matrix[i][j] != 'O')
                        {
                            matrix[i][j] = 'O';
                            flag = 1;
                            return 1;
                        }
                    }
                }

                // for col
                count = 0;
                for (j = 0; j < N; j++)
                {
                    if (matrix[j][i] == 'X')
                        count++;
                }
                if (count == N - num)
                {
                    for (j = 0; j < N; j++)
                    {
                        if (matrix[j][i] != 'X' && matrix[j][i] != 'O')
                        {
                            matrix[j][i] = 'O';
                            flag = 1;
                            return 1;
                        }
                    }
                }
            }

            count = 0;
            for (i = 0, j = 0; i < N; i++, j++)
            {
                if (matrix[i][j] == 'X')
                    count++;
            }
            if (count == N - num)
            {
                for (i = 0, j = 0; j < N; i++, j++)
                {
                    if (matrix[i][j] != 'X' && matrix[i][j] != 'O')
                    {
                        matrix[i][j] = 'O';
                        flag = 1;
                        return 1;
                    }
                }
            }
            count = 0;
            for (i = 0, j = N - 1; i < N; i++, j--)
            {
                if (matrix[i][j] == 'X')
                    count++;
            }
            if (count == N - num)
            {
                for (i = 0, j = N - 1; j >= 0; i++, j--)
                {
                    if (matrix[i][j] != 'X' && matrix[i][j] != 'O')
                    {
                        matrix[i][j] = 'O';
                        flag = 1;
                        return 1;
                    }
                }
            }
        }
    }
    else
    {
        num = 1;
        for (i = 0; i < N; i++)
        {
            count = 0;
            for (j = 0; j < N; j++)
            {
                if (matrix[i][j] == 'O')
                    count++;
            }
            if (count == N - num)
            {
                for (j = 0; j < N; j++)
                {
                    if (matrix[i][j] != 'O' && matrix[i][j] != 'X')
                    {
                        matrix[i][j] = 'O';
                        flag = 1;
                        ct++;
                        break;
                    }
                }
            }

            count = 0;
            for (j = 0; j < N; j++)
            {
                if (matrix[j][i] == 'O')
                    count++;
            }
            if (count == N - num)
            {
                for (j = 0; j < N; j++)
                {
                    if (matrix[j][i] != 'O' && matrix[j][i] != 'X')
                    {
                        matrix[j][i] = 'O';
                        flag = 1;
                        ct++;
                        break;
                    }
                }
            }
            if (flag)
                break;
        }

        count = 0;
        for (i = 0, j = 0; i < N; i++, j++)
        {
            if (matrix[i][j] == 'O')
                count++;
        }
        if (count == N - num)
        {
            for (i = 0, j = 0; j < N; i++, j++)
            {
                if (matrix[i][j] != 'O' && matrix[i][j] != 'X')
                {
                    matrix[i][j] = 'O';
                    flag = 1;
                    ct++;
                    break;
                }
            }
        }
        count = 0;
        for (i = 0, j = N - 1; i < N; i++, j--)
        {
            if (matrix[i][j] == 'O')
                count++;
        }
        if (count == N - num)
        {
            for (i = 0, j = N - 1; j >= 0; i++, j--)
            {
                if (matrix[i][j] != 'O' && matrix[i][j] != 'X')
                {
                    matrix[i][j] = 'O';
                    flag = 1;
                    ct++;
                    break;
                }
            }
        }

        for (i = 0; i < N; i++)
        {
            // for row
            count = 0;
            for (j = 0; j < N; j++)
            {
                if (matrix[i][j] == 'X')
                    count++;
            }
            if (count == N - num)
            {
                for (j = 0; j < N; j++)
                {
                    if (matrix[i][j] != 'X' && matrix[i][j] != 'O')
                    {
                        matrix[i][j] = 'O';
                        flag = 1;
                        ct++;
                        break;
                    }
                }
            }

            count = 0;
            for (j = 0; j < N; j++)
            {
                if (matrix[j][i] == 'X')
                    count++;
            }
            if (count == N - num)
            {
                for (j = 0; j < N; j++)
                {
                    if (matrix[j][i] != 'X' && matrix[j][i] != 'O')
                    {
                        matrix[j][i] = 'O';
                        flag = 1;
                        ct++;
                        break;
                    }
                }
            }
            if (flag)
                break;
        }

        count = 0;
        for (i = 0, j = 0; i < N; i++, j++)
        {
            if (matrix[i][j] == 'X')
                count++;
        }
        if (count == N - num)
        {
            for (i = 0, j = 0; j < N; i++, j++)
            {
                if (matrix[i][j] != 'X' && matrix[i][j] != 'O')
                {
                    matrix[i][j] = 'O';
                    ct++;
                    flag = 1;
                    break;
                }
            }
        }
        count = 0;
        for (i = 0, j = N - 1; i < N; i++, j--)
        {
            if (matrix[i][j] == 'X')
                count++;
        }
        if (count == N - num)
        {
            for (i = 0, j = N - 1; j >= 0; i++, j--)
            {
                if (matrix[i][j] != 'X' && matrix[i][j] != 'O')
                {
                    matrix[i][j] = 'O';
                    flag = 1;
                    ct++;
                    break;
                }
            }
        }
    }
    if (flag)
        return ct;
    else if (flag == 0)
    {
        while (1)
        {
            int random = rand() % (N * N) + 1;
            if (!checkPlaceIsValid(matrix, random))
            {
                for (i = 0; i < N; i++)
                {
                    for (j = 0; j < N; j++)
                    {
                        if (matrix[i][j] == random)
                        {
                            matrix[i][j] = 'O';
                            return 1;
                        }
                    }
                }
            }
        }
    }

    return -1;
}

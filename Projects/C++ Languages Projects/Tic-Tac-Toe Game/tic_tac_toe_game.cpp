#include <iostream>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

// work on this matrix
int matrix[3][3];

// function declration
int main();
void ticTacToeGameRules();
void matrixCreate();
void displayPlayersName(char[], char[]);
void displayGame();
int check_exist(int);
char gameWinner(char);
void restartTheGame();
int newGame();
void markingPlaceFriend(int, int, char[], char[]);
void markingPlaceSmartComputer(int, char[], char[], int);
void markingPlaceEvilComputer(int, char[], char[], int &);
void playWithFriend();
void playWithSmartComputer();
void playWithEvilComputer();

int newGame()
{
    while (1)
    {
        system("cls");
        int choice;
        cout << "\n\t-----NEW GAME-----";
        cout << "\n\n1 - PLAY WITH SMART COMPUTER";
        cout << "\n2 - PLAY WITH EVIL COMPUTER";
        cout << "\n3 - PLAY WITH FRIEND";
        cout << "\n4 - EXIT";
        cout << "\n\tENTER YOUR CHOICE: ";
        cin >> choice;
        if (choice == 1 || choice == 2 || choice == 3 || choice == 4)
            return choice;
        else
        {
            cout << "\n\tINVALID INPUT... TRY AGAIN!\nPRESS ANY KEY..";
            getch();
        }
    }
}

void ticTacToeGameRules()
{
    system("cls");
    cout << "\n\tGAME OF RULES";
    cout << "\n\nRULE NO.1 - X(symbol) MOVES FIRST";
    cout << "\n\nRULE NO.2 - A PIECE MAY BE PLACED ON ANY EMPTY SPACE";
    cout << "\n\nRULE NO.3 - A PLAYER WINS BY BEING THE FIRST TO CONNECT A LINE OF FRIENDLY PIECES FROM ONE SIDE OR CORNER OF THE BOARD TO THE OTHER";
    cout << "\n\nRULES NO.4 - THE GAME ENDS WHEN EITHER ONE PLAYER WINS OR IT IS NO LONGER POSSIBLE FOR A PLAYER TO WIN (IN WHICH CASE THE RESULT IS A DRAW)";
    cout << "\n\n\tPRESS ANY KEY TO CONTINUE....";
    getch();
}

void gameDiscription()
{
    system("cls");
    cout << "\n\t--------TIC-TAC-TOE GAME---------\n\n";
    int choice;
    cout << "\n\tPRESS-1 FOR SEE TIC-TAC-TOE GAME RULE";
    cout << "\n\tPRESS-2 FOR CONTINUE...";
    while (1)
    {
        cout << "\nENTER YOUR CHOICE: ";
        cin >> choice;
        if (choice == 1)
        {
            ticTacToeGameRules();
            break;
        }
        else if (choice == 2)
            break;
        else
            cout << "\tINVALID INPUT... TRY AGAIN!";
    }
}

void matrixCreate()
{
    int i, j, count = 0;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            matrix[i][j] = ++count;
}

void displayPlayersName(char firstName[], char secondName[])
{
    system("cls");
    cout << "\nFIRST PLAYER NAME - " << firstName << " AND YOUR SYMBOL IS: X";
    cout << "\nSECOND PLAYER NAME - " << secondName << " AND YOU SYMBOL IS: O\n\n";
}

void displayGame()
{
    cout << "\n\t\tTIC-TAC-TOE-GAME\n";
    int i, j;
    for (i = 0; i < 3; i++)
    {
        cout << "\n\t\t  ";
        for (j = 0; j < 3; j++)
        {
            if (matrix[i][j] >= 1 && matrix[i][j] <= 9)
                cout << matrix[i][j] << " ";
            else
                cout << (char)matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int check_exist(int randome)
{
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (matrix[i][j] == randome)
                return 1;
    return 0;
}

char gameWinner(char markSign)
{
    if (matrix[0][0] == matrix[0][1] && matrix[0][0] == matrix[0][2]) // first row
        return markSign;
    else if (matrix[1][0] == matrix[1][1] && matrix[1][0] == matrix[1][2]) // second row
        return markSign;
    else if (matrix[2][0] == matrix[2][1] && matrix[2][0] == matrix[2][2]) // third row
        return markSign;
    else if (matrix[0][0] == matrix[1][0] && matrix[0][0] == matrix[2][0]) // first col
        return markSign;
    else if (matrix[0][1] == matrix[1][1] && matrix[0][1] == matrix[2][1]) // second col
        return markSign;
    else if (matrix[0][2] == matrix[1][2] && matrix[0][2] == matrix[2][2]) // third row
        return markSign;
    else if (matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2]) // left diagonal
        return markSign;
    else if (matrix[0][2] == matrix[1][1] && matrix[0][2] == matrix[2][0]) // right diagonal
        return markSign;

    return 'N';
}

int main();

void restartTheGame()
{
    while (1)
    {
        system("cls");
        int choice;
        cout << "\n\tDO YOU WANT TO PLAY AGAIN!\n";
        cout << "1 - YES" << endl;
        cout << "2 - NO" << endl;
        cout << "\tENTER YOUR CHOICE: ";
        cin >> choice;
        if (choice == 1)
            main();
        else if (choice == 2)
        {
            cout << "THANKU, FOR PLAYING THE GAME, VISIT AGAIN!\nHAVE A GOOD DAY/NIGHT";
            exit(0);
        }
        else
        {
            cout << "\n\tINVALID INPUT.... TRY AGAIN!";
            Sleep(1000);
        }
    }
}

void markingPlaceFriend(int markPlace, int alternate, char firstPlayerName[], char secondPlayerName[])
{
    char markingSign = alternate ? 'X' : 'O';
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (matrix[i][j] == markPlace)
                matrix[i][j] = markingSign;

    char gameWinnerChar = gameWinner(markingSign);

    if (gameWinnerChar == 'X')
    {
        system("cls");
        displayGame();
        cout << "\n\tCONGRAULATION--!, " << firstPlayerName << " YOU WIN THE GAME...";
        cout << "PRESS ANY KEY....";
        getch();
        restartTheGame();
    }
    else if (gameWinnerChar == 'O')
    {
        system("cls");
        displayGame();
        cout << "\n\tCONGRAULATION--!, " << secondPlayerName << " YOU WIN THE GAME...";
        cout << "PRESS ANY KEY....";
        getch();
        restartTheGame();
    }
}

void playWithFriend()
{
    system("cls");
    int markPlace, flag = 1, totalMoves = 9, alternate = 1;
    char firstPlayerName[20], secondPlayerName[20];
    cout << "\n\n\t----PLAY WITH FIREND----\n";
    cout << "\nENTER FIRST PLAYER NAME: ";
    cin.ignore();
    gets(firstPlayerName);
    cout << "\nENTER SECOND PLAYER NAME: ";
    gets(secondPlayerName);

    while (1)
    {
        if (alternate == 1)
        {
            while (1)
            {
                system("cls");
                displayPlayersName(firstPlayerName, secondPlayerName);
                displayGame();
                cout << "\n"
                     << firstPlayerName << ", ENTER MARKING PLACE: ";
                cin >> markPlace;
                if ((markPlace >= 1 && markPlace <= 9) && check_exist(markPlace))
                {
                    alternate = 0;
                    break;
                }
                else
                {
                    cout << "\n\tINVALID INPUT OR ALREADY TAKE! TRY AGAIN....\nPRESS ANY KEY FOR CONTINUE....";
                    getch();
                }
            }
        }
        else
        {
            while (1)
            {
                system("cls");
                displayPlayersName(firstPlayerName, secondPlayerName);
                displayGame();
                cout << "\n"
                     << secondPlayerName << ", ENTER MARKING PLACE: ";
                cin >> markPlace;
                if ((markPlace >= 1 && markPlace <= 9) && check_exist(markPlace))
                {
                    alternate = 1;
                    break;
                }
                else
                {
                    cout << "\n\tINVALID INPUT OR ALREADY TAKE! TRY AGAIN....\nPRESS ANY KEY FOR CONTINUE....";
                    getch();
                }
            }
        }

        markingPlaceFriend(markPlace, !(alternate), firstPlayerName, secondPlayerName);

        if (--totalMoves == 0)
        {
            system("cls");
            displayPlayersName(firstPlayerName, secondPlayerName);
            displayGame();
            cout << "\n\tOOPS!, MATCH IS DRAW..!!\nPRESS ANY KEY.......";
            getch();
            restartTheGame();
        }
    }
}

int isTwo()
{
    if ((matrix[0][0] == matrix[0][1]) || (matrix[0][0] == matrix[0][2]) || (matrix[0][1] == matrix[0][2])) // first row
        return 1;
    else if ((matrix[1][0] == matrix[1][1]) || (matrix[1][0] == matrix[1][2]) || (matrix[1][1] == matrix[1][2])) // second row
        return 1;
    else if ((matrix[2][0] == matrix[2][1]) || (matrix[2][0] == matrix[2][2]) || (matrix[2][1] == matrix[2][2])) // third row
        return 1;
    else if ((matrix[0][0] == matrix[1][0]) || (matrix[0][0] == matrix[2][0]) || (matrix[1][0] == matrix[2][0])) // first col
        return 1;
    else if ((matrix[0][1] == matrix[1][1]) || (matrix[0][1] == matrix[2][1]) || (matrix[1][1] == matrix[2][1])) // second col
        return 1;
    else if ((matrix[0][2] == matrix[1][2]) || (matrix[0][2] == matrix[2][2]) || (matrix[1][2] == matrix[2][2])) // third row
        return 1;
    else if ((matrix[0][0] == matrix[1][1]) || (matrix[0][0] == matrix[2][2]) || (matrix[1][1] == matrix[2][2])) // left diagonal
        return 1;
    else if ((matrix[0][2] == matrix[1][1]) || (matrix[0][2] == matrix[2][0]) || (matrix[1][1] == matrix[2][0])) // right diagonal
        return 1;

    return 0;
}

void markingPlaceSmartComputer(int markPlace, char firstPlayerName[], char secondPlayerName[], int totalMoves)
{
    srand(time(0));
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (matrix[i][j] == markPlace)
                matrix[i][j] = 'X';

    if (gameWinner('X') == 'X')
    {
        system("cls");
        displayGame();
        cout << "\n\tCONGRAULATION--!, " << firstPlayerName << " YOU WIN THE GAME...";
        cout << "PRESS ANY KEY....";
        getch();
        restartTheGame();
    }

    // for win
    // for first row
    if (matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] != 'X')
        matrix[0][2] = 'O';
    else if (matrix[0][0] == 'O' && matrix[0][2] == 'O' && matrix[0][1] != 'X')
        matrix[0][1] = 'O';
    else if (matrix[0][1] == 'O' && matrix[0][2] == 'O' && matrix[0][0] != 'X')
        matrix[0][0] = 'O';

    // for second row
    else if (matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] != 'X')
        matrix[1][2] = 'O';
    else if (matrix[1][0] == 'O' && matrix[1][2] == 'O' && matrix[1][1] != 'X')
        matrix[1][1] = 'O';
    else if (matrix[1][1] == 'O' && matrix[1][2] == 'O' && matrix[1][0] != 'X')
        matrix[1][0] = 'O';

    // for third row
    else if (matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] != 'X')
        matrix[2][2] = 'O';
    else if (matrix[2][0] == 'O' && matrix[2][2] == 'O' && matrix[2][1] != 'X')
        matrix[2][1] = 'O';
    else if (matrix[2][1] == 'O' && matrix[2][2] == 'O' && matrix[2][0] != 'X')
        matrix[2][0] = 'O';

    // for first col
    else if (matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] != 'X')
        matrix[2][0] = 'O';
    else if (matrix[0][0] == 'O' && matrix[2][0] == 'O' && matrix[1][0] != 'X')
        matrix[1][0] = 'O';
    else if (matrix[1][0] == 'O' && matrix[2][0] == 'O' && matrix[0][0] != 'X')
        matrix[0][0] = 'O';

    // for second col
    else if (matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] != 'X')
        matrix[2][1] = 'O';
    else if (matrix[0][1] == 'O' && matrix[2][1] == 'O' && matrix[1][1] != 'X')
        matrix[1][1] = 'O';
    else if (matrix[1][1] == 'O' && matrix[2][1] == 'O' && matrix[0][1] != 'X')
        matrix[0][1] = 'O';

    // for third col
    else if (matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] != 'X')
        matrix[2][2] = 'O';
    else if (matrix[0][2] == 'O' && matrix[2][2] == 'O' && matrix[1][2] != 'X')
        matrix[1][2] = 'O';
    else if (matrix[1][2] == 'O' && matrix[2][2] == 'O' && matrix[0][2] != 'X')
        matrix[0][2] = 'O';

    // for left diagonal
    else if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] != 'X')
        matrix[2][2] = 'O';
    else if (matrix[0][0] == 'O' && matrix[2][2] == 'O' && matrix[1][1] != 'X')
        matrix[1][1] = 'O';
    else if (matrix[1][1] == 'O' && matrix[2][2] == 'O' && matrix[0][0] != 'X')
        matrix[0][0] = 'O';

    // for right diagonal
    else if (matrix[0][2] == 'O' && matrix[1][1] == 'O' && matrix[2][0] != 'X')
        matrix[2][0] = 'O';
    else if (matrix[0][2] == 'O' && matrix[2][0] == 'O' && matrix[1][1] != 'X')
        matrix[1][1] = 'O';
    else if (matrix[1][1] == 'O' && matrix[2][0] == 'O' && matrix[0][2] != 'X')
        matrix[0][2] = 'O';

    // for defend
    // for first row
    else if (matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] != 'O')
        matrix[0][2] = 'O';
    else if (matrix[0][0] == 'X' && matrix[0][2] == 'X' && matrix[0][1] != 'O')
        matrix[0][1] = 'O';
    else if (matrix[0][1] == 'X' && matrix[0][2] == 'X' && matrix[0][0] != 'O')
        matrix[0][0] = 'O';

    // for second row
    else if (matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] != 'O')
        matrix[1][2] = 'O';
    else if (matrix[1][0] == 'X' && matrix[1][2] == 'X' && matrix[1][1] != 'O')
        matrix[1][1] = 'O';
    else if (matrix[1][1] == 'X' && matrix[1][2] == 'X' && matrix[1][0] != 'O')
        matrix[1][0] = 'O';

    // for third row
    else if (matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] != 'O')
        matrix[2][2] = 'O';
    else if (matrix[2][0] == 'X' && matrix[2][2] == 'X' && matrix[2][1] != 'O')
        matrix[2][1] = 'O';
    else if (matrix[2][1] == 'X' && matrix[2][2] == 'X' && matrix[2][0] != 'O')
        matrix[2][0] = 'O';

    // for first col
    else if (matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] != 'O')
        matrix[2][0] = 'O';
    else if (matrix[0][0] == 'X' && matrix[2][0] == 'X' && matrix[1][0] != 'O')
        matrix[1][0] = 'O';
    else if (matrix[1][0] == 'X' && matrix[2][0] == 'X' && matrix[0][0] != 'O')
        matrix[0][0] = 'O';

    // for second col
    else if (matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] != 'O')
        matrix[2][1] = 'O';
    else if (matrix[0][1] == 'X' && matrix[2][1] == 'X' && matrix[1][1] != 'O')
        matrix[1][1] = 'O';
    else if (matrix[1][1] == 'X' && matrix[2][1] == 'X' && matrix[0][1] != 'O')
        matrix[0][1] = 'O';

    // for third row
    else if (matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] != 'O')
        matrix[2][2] = 'O';
    else if (matrix[0][2] == 'X' && matrix[2][2] == 'X' && matrix[1][2] != 'O')
        matrix[1][2] = 'O';
    else if (matrix[1][2] == 'X' && matrix[2][2] == 'X' && matrix[0][2] != 'O')
        matrix[0][2] = 'O';

    // for left diagonal
    else if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] != 'O')
        matrix[2][2] = 'O';
    else if (matrix[0][0] == 'X' && matrix[2][2] == 'X' && matrix[1][1] != 'O')
        matrix[1][1] = 'O';
    else if (matrix[1][1] == 'X' && matrix[2][2] == 'X' && matrix[0][0] != 'O')
        matrix[0][0] = 'O';

    // for right diagonal
    else if (matrix[0][2] == 'X' && matrix[1][1] == 'X' && matrix[2][0] != 'O')
        matrix[2][0] = 'O';
    else if (matrix[0][2] == 'X' && matrix[2][0] == 'X' && matrix[1][1] != 'O')
        matrix[1][1] = 'O';
    else if (matrix[1][1] == 'X' && matrix[2][0] == 'X' && matrix[0][2] != 'O')
        matrix[0][2] = 'O';
    else
    {
        if (totalMoves <= 0)
        {
            system("cls");
            displayPlayersName(firstPlayerName, secondPlayerName);
            displayGame();
            cout << "\n\tOOPS...!! MATCH IS DRAWN...\nPRESS ANY KEY...";
            getch();
            restartTheGame();
        }
        else
        {
            while (1)
            {
                int random = rand() % 9 + 1;
                if (check_exist(random))
                {
                    for (int i = 0; i < 3; i++)
                        for (int j = 0; j < 3; j++)
                            if (matrix[i][j] == random)
                                matrix[i][j] = 'O';

                    break;
                }
            }
        }
    }
    if (gameWinner('O') == 'O')
    {
        system("cls");
        displayGame();
        cout << "\n\tYOU LOSE THE GAME--!, " << secondPlayerName << " WIN THE GAME...";
        cout << "PRESS ANY KEY....";
        getch();
        restartTheGame();
    }
}

void playWithSmartComputer()
{
    system("cls");
    int markPlace, totalMoves = 9;
    char firstPlayerName[20], secondPlayerName[20];
    cout << "\n\n\t----PLAY WITH SMART COMPUTER----\n";
    cout << "\nENTER PLAYER NAME: ";
    cin.ignore();
    gets(firstPlayerName);
    strcpy(secondPlayerName, "SMART COMPUTER ");

    while (1)
    {
        while (1)
        {
            system("cls");
            displayPlayersName(firstPlayerName, secondPlayerName);
            displayGame();
            cout << "\n"
                 << firstPlayerName << ", ENTER MARKING PLACE: ";
            cin >> markPlace;
            if ((markPlace >= 1 && markPlace <= 9) && check_exist(markPlace))
                break;
            else
            {
                cout << "\n\tINVALID INPUT OR ALREADY TAKE! TRY AGAIN....\nPRESS ANY KEY FOR CONTINUE....";
                getch();
            }
        }
        totalMoves -= 2;
        markingPlaceSmartComputer(markPlace, firstPlayerName, secondPlayerName, totalMoves);
    }
}

void markingPlaceEvilComputer(int markPlace, char firstPlayerName[], char secondPlayerName[], int &totalMoves)
{
    srand(time(0));
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (matrix[i][j] == markPlace)
            {
                matrix[i][j] = 'X';
                totalMoves--;
            }

    if (gameWinner('X') == 'X')
    {
        system("cls");
        displayGame();
        cout << "\n\tCONGRAULATION--!, " << firstPlayerName << " YOU WIN THE GAME...";
        cout << "PRESS ANY KEY....";
        getch();
        restartTheGame();
    }
    if (totalMoves <= 0)
    {
        system("cls");
        displayPlayersName(firstPlayerName, secondPlayerName);
        displayGame();
        cout << "\n\tOOPS...!! MATCH IS DRAWN...\nPRESS ANY KEY...";
        getch();
        restartTheGame();
    }
    // for win
    // for first row
    if (matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] != 'X')
    {
        matrix[0][2] = 'O';
        totalMoves--;
    }
    else if (matrix[0][0] == 'O' && matrix[0][2] == 'O' && matrix[0][1] != 'X')
    {
        matrix[0][1] = 'O';
        totalMoves--;
    }
    else if (matrix[0][1] == 'O' && matrix[0][2] == 'O' && matrix[0][0] != 'X')
    {
        matrix[0][0] = 'O';
        totalMoves--;
    }

    // for second row
    else if (matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] != 'X')
    {
        matrix[1][2] = 'O';
        totalMoves--;
    }
    else if (matrix[1][0] == 'O' && matrix[1][2] == 'O' && matrix[1][1] != 'X')
    {
        matrix[1][1] = 'O';
        totalMoves--;
    }
    else if (matrix[1][1] == 'O' && matrix[1][2] == 'O' && matrix[1][0] != 'X')
    {
        matrix[1][0] = 'O';
        totalMoves--;
    }

    // for third row
    else if (matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] != 'X')
    {
        matrix[2][2] = 'O';
        totalMoves--;
    }
    else if (matrix[2][0] == 'O' && matrix[2][2] == 'O' && matrix[2][1] != 'X')
    {
        matrix[2][1] = 'O';
        totalMoves--;
    }
    else if (matrix[2][1] == 'O' && matrix[2][2] == 'O' && matrix[2][0] != 'X')
    {
        matrix[2][0] = 'O';
        totalMoves--;
    }

    // for first col
    else if (matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] != 'X')
    {
        matrix[2][0] = 'O';
        totalMoves--;
    }
    else if (matrix[0][0] == 'O' && matrix[2][0] == 'O' && matrix[1][0] != 'X')
    {
        matrix[1][0] = 'O';
        totalMoves--;
    }
    else if (matrix[1][0] == 'O' && matrix[2][0] == 'O' && matrix[0][0] != 'X')
    {
        matrix[0][0] = 'O';
        totalMoves--;
    }

    // for second col
    else if (matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] != 'X')
    {
        matrix[2][1] = 'O';
        totalMoves--;
    }
    else if (matrix[0][1] == 'O' && matrix[2][1] == 'O' && matrix[1][1] != 'X')
    {
        matrix[1][1] = 'O';
        totalMoves--;
    }
    else if (matrix[1][1] == 'O' && matrix[2][1] == 'O' && matrix[0][1] != 'X')
    {
        matrix[0][1] = 'O';
        totalMoves--;
    }

    // for third col
    else if (matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] != 'X')
    {
        matrix[2][2] = 'O';
        totalMoves--;
    }
    else if (matrix[0][2] == 'O' && matrix[2][2] == 'O' && matrix[1][2] != 'X')
    {
        matrix[1][2] = 'O';
        totalMoves--;
    }
    else if (matrix[1][2] == 'O' && matrix[2][2] == 'O' && matrix[0][2] != 'X')
    {
        matrix[0][2] = 'O';
        totalMoves--;
    }

    // for left diagonal
    else if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] != 'X')
    {
        matrix[2][2] = 'O';
        totalMoves--;
    }
    else if (matrix[0][0] == 'O' && matrix[2][2] == 'O' && matrix[1][1] != 'X')
    {
        matrix[1][1] = 'O';
        totalMoves--;
    }
    else if (matrix[1][1] == 'O' && matrix[2][2] == 'O' && matrix[0][0] != 'X')
    {
        matrix[0][0] = 'O';
        totalMoves--;
    }

    // for right diagonal
    else if (matrix[0][2] == 'O' && matrix[1][1] == 'O' && matrix[2][0] != 'X')
    {
        matrix[2][0] = 'O';
        totalMoves--;
    }
    else if (matrix[0][2] == 'O' && matrix[2][0] == 'O' && matrix[1][1] != 'X')
    {
        matrix[1][1] = 'O';
        totalMoves--;
    }
    else if (matrix[1][1] == 'O' && matrix[2][0] == 'O' && matrix[0][2] != 'X')
    {
        matrix[0][2] = 'O';
        totalMoves--;
    }

    if (gameWinner('O') == 'O')
    {
        system("cls");
        displayGame();
        cout << "\n\tYOU LOSE THE GAME--!, " << secondPlayerName << " WIN THE GAME...";
        cout << "PRESS ANY KEY....";
        getch();
        restartTheGame();
    }

    // for defend
    // for first row
    int flag = 0;
    if (matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] != 'O')
    {
        matrix[0][2] = 'O';
        flag = 1;
        totalMoves--;
    }
    else if (matrix[0][0] == 'X' && matrix[0][2] == 'X' && matrix[0][1] != 'O')
    {
        matrix[0][1] = 'O';
        flag = 1;
        totalMoves--;
    }
    else if (matrix[0][1] == 'X' && matrix[0][2] == 'X' && matrix[0][0] != 'O')
    {
        matrix[0][0] = 'O';
        flag = 1;
        totalMoves--;
    }

    // for second row
    if (matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] != 'O')
    {
        matrix[1][2] = 'O';
        totalMoves--;
        flag = 1;
    }
    else if (matrix[1][0] == 'X' && matrix[1][2] == 'X' && matrix[1][1] != 'O')
    {
        matrix[1][1] = 'O';
        flag = 1;
        totalMoves--;
    }
    else if (matrix[1][1] == 'X' && matrix[1][2] == 'X' && matrix[1][0] != 'O')
    {
        matrix[1][0] = 'O';
        flag = 1;
        totalMoves--;
    }

    // for third row
    if (matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] != 'O')
    {
        matrix[2][2] = 'O';
        flag = 1;
        totalMoves--;
    }
    else if (matrix[2][0] == 'X' && matrix[2][2] == 'X' && matrix[2][1] != 'O')
    {
        matrix[2][1] = 'O';
        totalMoves--;
        flag = 1;
    }
    else if (matrix[2][1] == 'X' && matrix[2][2] == 'X' && matrix[2][0] != 'O')
    {
        matrix[2][0] = 'O';
        totalMoves--;
        flag = 1;
    }

    // for first col
    if (matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] != 'O')
    {
        matrix[2][0] = 'O';
        totalMoves--;
        flag = 1;
    }
    else if (matrix[0][0] == 'X' && matrix[2][0] == 'X' && matrix[1][0] != 'O')
    {
        matrix[1][0] = 'O';
        flag = 1;
        totalMoves--;
    }
    else if (matrix[1][0] == 'X' && matrix[2][0] == 'X' && matrix[0][0] != 'O')
    {
        matrix[0][0] = 'O';
        flag = 1;
        totalMoves--;
    }

    // for second col
    if (matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] != 'O')
    {
        matrix[2][1] = 'O';
        flag = 1;
        totalMoves--;
    }
    else if (matrix[0][1] == 'X' && matrix[2][1] == 'X' && matrix[1][1] != 'O')
    {
        matrix[1][1] = 'O';
        flag = 1;
        totalMoves--;
    }
    else if (matrix[1][1] == 'X' && matrix[2][1] == 'X' && matrix[0][1] != 'O')
    {
        matrix[0][1] = 'O';
        flag = 1;
        totalMoves--;
    }

    // for third row
    if (matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] != 'O')
    {
        matrix[2][2] = 'O';
        flag = 1;
        totalMoves--;
    }
    else if (matrix[0][2] == 'X' && matrix[2][2] == 'X' && matrix[1][2] != 'O')
    {
        matrix[1][2] = 'O';
        flag = 1;
        totalMoves--;
    }
    else if (matrix[1][2] == 'X' && matrix[2][2] == 'X' && matrix[0][2] != 'O')
    {
        matrix[0][2] = 'O';
        flag = 1;
        totalMoves--;
    }

    // for left diagonal
    if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] != 'O')
    {
        matrix[2][2] = 'O';
        flag = 1;
        totalMoves--;
    }
    else if (matrix[0][0] == 'X' && matrix[2][2] == 'X' && matrix[1][1] != 'O')
    {
        matrix[1][1] = 'O';
        flag = 1;
        totalMoves--;
    }
    else if (matrix[1][1] == 'X' && matrix[2][2] == 'X' && matrix[0][0] != 'O')
    {
        matrix[0][0] = 'O';
        flag = 1;
        totalMoves--;
    }

    // for right diagonal
    if (matrix[0][2] == 'X' && matrix[1][1] == 'X' && matrix[2][0] != 'O')
    {
        matrix[2][0] = 'O';
        flag = 1;
        totalMoves--;
    }
    else if (matrix[0][2] == 'X' && matrix[2][0] == 'X' && matrix[1][1] != 'O')
    {
        matrix[1][1] = 'O';
        flag = 1;
        totalMoves--;
    }
    else if (matrix[1][1] == 'X' && matrix[2][0] == 'X' && matrix[0][2] != 'O')
    {
        matrix[0][2] = 'O';
        flag = 1;
        totalMoves--;
    }

    if (flag == 0)
    {
        while (1)
        {
            int random = rand() % 9 + 1;
            if (check_exist(random))
            {
                for (int i = 0; i < 3; i++)
                    for (int j = 0; j < 3; j++)
                        if (matrix[i][j] == random)
                        {
                            matrix[i][j] = 'O';
                            totalMoves--;
                        }

                break;
            }
        }
    }
    if (gameWinner('O') == 'O')
    {
        system("cls");
        displayGame();
        cout << "\n\tYOU LOSE THE GAME--!, " << secondPlayerName << " WIN THE GAME...";
        cout << "PRESS ANY KEY....";
        getch();
        restartTheGame();
    }
    if (totalMoves <= 0)
    {
        system("cls");
        displayPlayersName(firstPlayerName, secondPlayerName);
        displayGame();
        cout << "\n\tOOPS...!! MATCH IS DRAWN...\nPRESS ANY KEY...";
        getch();
        restartTheGame();
    }
}

void playWithEvilComputer()
{
    system("cls");
    int markPlace, totalMoves = 9;
    char firstPlayerName[20], secondPlayerName[20];
    cout << "\n\n\t----PLAY WITH EVIL COMPUTER----\n";
    cout << "\nENTER PLAYER NAME: ";
    cin.ignore();
    gets(firstPlayerName);
    strcpy(secondPlayerName, "EVIL COMPUTER ");
    while (1)
    {
        while (1)
        {
            system("cls");
            displayPlayersName(firstPlayerName, secondPlayerName);
            displayGame();
            cout << "\n"
                 << firstPlayerName << ", ENTER MARKING PLACE: ";
            cin >> markPlace;
            if ((markPlace >= 1 && markPlace <= 9) && check_exist(markPlace))
                break;
            else
            {
                cout << "\n\tINVALID INPUT OR ALREADY TAKE! TRY AGAIN....\nPRESS ANY KEY FOR CONTINUE....";
                getch();
            }
        }
        markingPlaceEvilComputer(markPlace, firstPlayerName, secondPlayerName, totalMoves);
    }
}

int main()
{
    matrixCreate();
    gameDiscription();
    switch (newGame())
    {
    case 1:
        playWithSmartComputer();
        break;
    case 2:
        playWithEvilComputer();
        break;

    case 3:
        playWithFriend();
        break;

    case 4:
        cout << "THANKU, FOR VISITING THE GAME, VISIT AGAIN!\nHAVE A GOOD DAY/NIGHT";
        exit(0);
    }

    return 0;
}

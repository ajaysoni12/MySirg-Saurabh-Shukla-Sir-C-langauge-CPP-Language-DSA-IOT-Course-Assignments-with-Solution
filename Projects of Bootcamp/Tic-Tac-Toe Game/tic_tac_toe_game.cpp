#include <iostream>
#include <string.h>
#include <conio.h>
#include <time.h>
using namespace std;

// work on this matrix
int matrix[3][3];

// function declation

int markingPlace(int);
int markingPlaceSmartCom(int);
int markingPlaceEvilCom(int);
void playWithFriend();
void playWithSmartCom();
void playWithEvilCom();
int winGame();
void ticTacToeGameRules();
void gameDiscription();
int newGame();
void displayPlayersName(char[], char[]);
void displayGame();
void restartTheGame();
void displayWinner(char[]);
void gameDiscription();
void matrixCreate();
int checkedSmartCom();
int checkedEvilCom();
int computer_win();
int main();
int check_exist(int);

int markingPlace(int markPlace)
{
    int i, j, flag = 0;
    static char ch = 'X';
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (matrix[i][j] == markPlace && ch == 'X') // user markplace find
            {
                matrix[i][j] = ch;
                ch = 'O';
                flag = 1;
            }
            else if (matrix[i][j] == markPlace && ch == 'O')
            {
                matrix[i][j] = ch;
                ch = 'X';
                flag = 1;
            }
        }
    }
    if (flag == 0)
    {
        cout << "\n\tOOPS!, YOU LOOOSE YOUR MOVE!, BECUASE YOUR MARK PLACE IS ALREADY TAKEN!";
        cout << "\nPRESS ANY KEY TO CONTINUE...";
        getch();
        return 1;
    }
    return 0;
}

int markingPlaceSmartCom(int markPlace)
{
    int i, j, flag = 0, check = 0;
    srand(time(0));
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (matrix[i][j] == markPlace)
            {
                matrix[i][j] = 'X';
                flag = 1;
                if (!checkedSmartCom())
                {
                    while (1)
                    {
                        int random = rand() % 9 + 1;
                        if (check_exist(random))
                        {
                            check = 1;
                            break;
                        }
                    }
                }
            }
            if (check)
                break;
        }
        if (check)
            break;
    }
    if (flag == 0)
    {
        cout << "\n\tOOPS!, YOU LOOOSE YOUR MOVE!, BECUASE YOUR MARK PLACE IS ALREADY TAKEN!";
        cout << "\nPRESS ANY KEY TO CONTINUE...";
        getch();
        return 1;
    }
    return 0;
}

int markingPlaceEvilCom(int markPlace)
{
    int i, j, flag = 0, check = 0;
    srand(time(0));
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (matrix[i][j] == markPlace)
            {
                matrix[i][j] = 'X';
                flag = 1;
                if (!checkedEvilCom())
                {
                    while (1)
                    {
                        int random = rand() % 9 + 1;
                        if (check_exist(random))
                        {
                            check = 1;
                            break;
                        }
                    }
                }
            }
            if (check)
                break;
        }
        if (check)
            break;
    }

    if (flag)
        return 1;
    return 0;
}

int winGame()
{
    int i, j;
    for (int i = 0; i < 3; i++)
    {
        int countX = 0, countO = 0;
        for (j = 0; j < 3; j++)
        {
            if (matrix[i][j] == 'X')
                countX++;
            if (matrix[i][j] == 'O')
                countO++;
        }
        if (countO == 3)
            return 2;
        if (countX == 3)
            return 1;
    }
    for (int i = 0; i < 3; i++)
    {
        int countX = 0, countO = 0;
        for (j = 0; j < 3; j++)
        {
            if (matrix[j][i] == 'X')
                countX++;
            if (matrix[j][i] == 'O')
                countO++;
        }
        if (countO == 3)
            return 2;
        if (countX == 3)
            return 1;
    }
    int countX = 0, countO = 0;
    for (i = 0; i < 3; i++)
    {
        if (matrix[i][i] == 'X')
            countX++;
        if (matrix[i][i] == 'O')
            countO++;
    }
    if (countO == 3)
        return 2;
    if (countX == 3)
        return 1;

    countX = 0, countO = 0;
    for (i = 0, j = 2; i < 3; i++, j--)
    {
        if (matrix[i][j] == 'X')
            countX++;
        if (matrix[i][j] == 'O')
            countO++;
    }
    if (countO == 3)
        return 2;
    if (countX == 3)
        return 1;

    return 0;
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
        if (choice == 1 || choice == 2 || choice == 3)
            return choice;
        else
        {
            cout << "\n\tINVALID INPUT... TRY AGAIN!\nPRESS ANY KEY..";
            getch();
        }
    }
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

void restartTheGame();

void displayWinner(char winnerName[])
{
    displayGame();
    cout << "\n\nCONGRAULATION! " << winnerName << ", WELL DONE!, YOU PLAY GREAT!";
    cout << "\nPRESS ANY KEY...";
    getch();
    restartTheGame();
}

void playWithFriend()
{
    system("cls");
    int markPlace, flag = 1, totalMoves = 9;
    char firstPlayerName[20], secondPlayerName[20];
    cout << "\n\n\t----PLAY WITH FIREND----\n";
    cout << "\nENTER FIRST PLAYER NAME: ";
    cin.ignore();
    gets(firstPlayerName);
    cout << "\nENTER SECOND PLAYER NAME: ";
    gets(secondPlayerName);

    while (true)
    {
        system("cls");
        int flag = 1;
        displayPlayersName(firstPlayerName, secondPlayerName);
        displayGame();
        if (flag)
        {
            cout << "\n"
                 << firstPlayerName << ", ENTER MARKING PLACE: ";
            flag = 0;
        }
        else
        {
            cout << "\n"
                 << secondPlayerName << ", ENTER MARKING PLACE: ";
            flag = 1;
        }
        cin >> markPlace;
        if (markPlace >= 1 && markPlace <= 9)
        {
            flag = markingPlace(markPlace);
            int ans = winGame();
            if (ans == 1)
                displayWinner(firstPlayerName);
            else if (ans == 2)
                displayWinner(secondPlayerName);
        }
        else
        {
            cout << "\n\tINVALID MARKING PLACE... TRY AGAIN!" << endl;
        }

        if (flag == 0 && --totalMoves == 0)
        {
            cout << "\n\tOOPS!, MATCH IS DRAW, NICE PLAY BOTH OF THE PLAYER!";
            cout << "\nPRESS ANY KEY....";
            getch();
            restartTheGame();
        }
    }
}

void matrixCreate()
{
    int i, j, count = 0;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            matrix[i][j] = ++count;
}

int checkedSmartCom()
{
    if (computer_win())
    {
        cout << "\nOOPS!, YOU LOSE THE GAME, SMART COMPUTER WIN THE GAME , WELL PLAYED";
        cout << "PRESS ANY KEY...";
        getch();
        restartTheGame();
    }

    int i, j, countX;
    for (i = 0; i < 3; i++)
    {
        countX = 0;
        for (j = 0; j < 3; j++)
        {
            if (matrix[i][j] == 'X')
                countX++;
        }
        if (countX == 2)
        {
            for (j = 0; j < 3; j++)
            {
                if (!(matrix[i][j] == 'X' || matrix[i][j] == 'O'))
                {
                    matrix[i][j] = 'O';
                    return 1;
                }
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        countX = 0;
        for (j = 0; j < 3; j++)
        {
            if (matrix[j][i] == 'X')
                countX++;
        }
        if (countX == 2)
        {
            for (j = 0; j < 3; j++)
            {
                if (!(matrix[j][i] == 'X' || matrix[j][i] == 'O'))
                {
                    matrix[j][i] = 'O';
                    return 1;
                }
            }
        }
    }

    countX = 0;
    for (i = 0; i < 3; i++)
    {
        if (matrix[i][i] == 'X')
            countX++;
    }
    if (countX == 2)
    {
        for (j = 0; j < 3; j++)
        {
            if (!(matrix[i][j] == 'X' || matrix[i][j] == 'O'))
            {
                matrix[j][j] = 'O';
                return 1;
            }
        }
    }

    countX = 0;
    for (i = 0, j = 2; i < 3; i++, j--)
    {
        if (matrix[i][j] == 'X')
            countX++;
    }
    if (countX == 2)
    {
        for (i = 0, j = 2; j < 3; i++, j--)
        {
            if (!(matrix[i][j] == 'X' || matrix[i][j] == 'O'))
            {
                matrix[i][j] = 'O';
                return 1;
            }
        }
    }

    return 0;
}

int computer_win()
{
    int i, j, countO;
    for (i = 0; i < 3; i++)
    {
        countO = 0;
        for (j = 0; j < 3; j++)
        {
            if (matrix[i][j] == 'O')
                countO++;
        }
        if (countO == 2)
        {
            for (j = 0; j < 3; j++)
            {
                if (!(matrix[i][j] == 'X' || matrix[i][j] == 'O'))
                {
                    matrix[i][j] = 'O';
                    return 1;
                }
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        countO = 0;
        for (j = 0; j < 3; j++)
        {
            if (matrix[j][i] == 'O')
                countO++;
        }
        if (countO == 2)
        {
            for (j = 0; j < 3; j++)
            {
                if (!(matrix[j][i] == 'X' || matrix[j][i] == 'O'))
                {
                    matrix[j][i] = 'O';
                    return 1;
                }
            }
        }
    }

    countO = 0;
    for (i = 0; i < 3; i++)
    {
        if (matrix[i][i] == 'O')
            countO++;
    }
    if (countO == 2)
    {
        for (j = 0; j < 3; j++)
        {
            if (!(matrix[i][j] == 'X' || matrix[i][j] == 'O'))
            {
                matrix[j][j] = 'O';
                return 1;
            }
        }
    }

    countO = 0;
    for (i = 0, j = 2; i < 3; i++, j--)
    {
        if (matrix[i][j] == 'O')
            countO++;
    }
    if (countO == 2)
    {
        for (i = 0, j = 2; j < 3; i++, j--)
        {
            if (!(matrix[i][j] == 'X' || matrix[i][j] == 'O'))
            {
                matrix[i][j] = 'O';
                return 1;
            }
        }
    }

    return 0;
}

int check_exist(int randome)
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (matrix[i][j] == randome)
            {
                matrix[i][j] = 'O';
                return 1;
            }
        }
    }
    return 0;
}

void playWithSmartComputer()
{
    system("cls");
    int markPlace, flag = 1, totalMoves = 5;
    char firstPlayerName[20], secondPlayerName[20];
    cout << "\n\n\t----PLAY WITH SMART COMPUTER----\n";
    cout << "\nENTER PLAYER NAME: ";
    cin.ignore();
    gets(firstPlayerName);
    strcpy(secondPlayerName, "SMART COMPUTER");

    while (true)
    {
        system("cls");
        int flag;
        displayPlayersName(firstPlayerName, secondPlayerName);
        displayGame();
        cout << "\n"
             << firstPlayerName << ", ENTER MARKING PLACE: ";
        cin >> markPlace;
        if (markPlace >= 1 && markPlace <= 9)
        {
            flag = markingPlaceSmartCom(markPlace);
            int ans = winGame();
            if (ans == 1)
                displayWinner(firstPlayerName);
            else if (ans == 2)
                displayWinner(secondPlayerName);
        }
        else
        {
            cout << "\n\tINVALID MARKING PLACE... TRY AGAIN!" << endl;
        }

        if (flag == 0 && --totalMoves == 0)
        {
            cout << "\n\tOOPS!, MATCH IS DRAW, NICE PLAY BOTH OF THE PLAYER!";
            cout << "\nPRESS ANY KEY....";
            getch();
            restartTheGame();
        }
    }
}

void playWithEvilComputer()
{
    system("cls");
    int markPlace, flag = 1, totalMoves = 5;
    char firstPlayerName[20], secondPlayerName[20];
    cout << "\n\n\t----PLAY WITH EVIL COMPUTER----\n";
    cout << "\nENTER PLAYER NAME: ";
    cin.ignore();
    gets(firstPlayerName);
    strcpy(secondPlayerName, "EVIL COMPUTER");

    while (true)
    {
        system("cls");
        int flag;
        displayPlayersName(firstPlayerName, secondPlayerName);
        displayGame();
        cout << "\n"
             << firstPlayerName << ", ENTER MARKING PLACE: ";
        cin >> markPlace;
        if (markPlace >= 1 && markPlace <= 9)
        {
            flag = markingPlaceEvilCom(markPlace);
            int ans = winGame();
            if (ans == 1)
                displayWinner(firstPlayerName);
            else if (ans == 2)
                displayWinner(secondPlayerName);
        }
        else
        {
            cout << "\n\tINVALID MARKING PLACE... TRY AGAIN!" << endl;
        }

        if (flag == 0 && --totalMoves == 0)
        {
            cout << "\n\tOOPS!, MATCH IS DRAW, NICE PLAY BOTH OF THE PLAYER!";
            cout << "\nPRESS ANY KEY....";
            getch();
            restartTheGame();
        }
    }
}

void restartTheGame()
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
    else
    {
        cout << "THANKU, FOR PLAYING THE GAME, VISIT AGAIN!\nHAVE A GOOD DAY/NIGHT";
        exit(0);
    }
}

int checkedEvilCom()
{
    if (computer_win())
    {
        cout << "\nOOPS!, YOU LOSE THE GAME, EVIL COMPUTER WIN THE GAME , WELL PLAYED";
        cout << "PRESS ANY KEY...";
        getch();
        restartTheGame();
    }

    int i, j, countX, flag = 0;
    for (i = 0; i < 3; i++)
    {
        countX = 0;
        for (j = 0; j < 3; j++)
        {
            if (matrix[i][j] == 'X')
                countX++;
        }
        if (countX == 2)
        {
            for (j = 0; j < 3; j++)
            {
                if (!(matrix[i][j] == 'X' || matrix[i][j] == 'O'))
                {
                    matrix[i][j] = 'O';
                    flag = 1;
                }
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        countX = 0;
        for (j = 0; j < 3; j++)
        {
            if (matrix[j][i] == 'X')
                countX++;
        }
        if (countX == 2)
        {
            for (j = 0; j < 3; j++)
            {
                if (!(matrix[j][i] == 'X' || matrix[j][i] == 'O'))
                {
                    matrix[j][i] = 'O';
                    flag = 1;
                }
            }
        }
    }

    countX = 0;
    for (i = 0; i < 3; i++)
    {
        if (matrix[i][i] == 'X')
            countX++;
    }
    if (countX == 2)
    {
        for (j = 0; j < 3; j++)
        {
            if (!(matrix[j][j] == 'X' || matrix[j][j] == 'O'))
            {
                matrix[j][j] = 'O';
                flag = 1;
            }
        }
    }

    countX = 0;
    for (i = 0, j = 2; i < 3; i++, j--)
    {
        if (matrix[i][j] == 'X')
            flag = 1;
    }
    if (countX == 2)
    {
        for (i = 0, j = 2; j < 3; i++, j--)
        {
            if (!(matrix[i][j] == 'X' || matrix[i][j] == 'O'))
            {
                matrix[i][j] = 'O';
                flag = 1;
            }
        }
    }
    if (flag)
        return 1;
    return 0;
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

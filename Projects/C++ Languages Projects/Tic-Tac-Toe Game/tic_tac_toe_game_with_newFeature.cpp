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
void matrixCreate();
void ticTacToeGameRules();
int newGame();
void displayGame();
int check_exist(int);
char gameWinner(char);
void restartTheGame();
void playWithFriend();
void markingPlaceFriend(int, int, char[], char[], char, char);
void playWithSmartComputer();
void markingPlaceSmartComputer(int, char[], char[], int, char, char);
void playWithEvilComputer();
void markingPlaceEvilComputer(int, char[], char[], int &, char, char);
void displayPlayersNameWithSymbol(char[], char, char[], char);

// function defintions
int newGame()
{
    while (1)
    {
        system("cls");
        int choice;
        cout << "\n\t-----NEW GAME-----\n\n1 - PLAY WITH SMART COMPUTER\n2 - PLAY WITH EVIL COMPUTER\n3 - PLAY WITH FRIEND\n4 - EXIT THE GAME\n\tENTER YOUR CHOICE: ";
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
    cout << "\n\tGAME OF RULES\n\nRULE NO.1 - X(symbol) MOVES FIRST\n\nRULE NO.2 - A PIECE MAY BE PLACED ON ANY EMPTY SPACE\n\nRULE NO.3 - A PLAYER WINS BY BEING THE FIRST TO CONNECT A LINE OF FRIENDLY PIECES FROM ONE SIDE OR CORNER OF THE BOARD TO THE OTHER\n\nRULES NO.4 - THE GAME ENDS WHEN EITHER ONE PLAYER WINS OR IT IS NO LONGER POSSIBLE FOR A PLAYER TO WIN (IN WHICH CASE THE RESULT IS A DRAW)\n\n\tPRESS ANY KEY TO CONTINUE....";
    getch();
}

void gameDiscription()
{
    system("cls");
    int choice;
    cout << "\n\t--------TIC-TAC-TOE GAME---------\n\n\n\tPRESS-1 FOR SEE TIC-TAC-TOE GAME RULE\n\tPRESS-2 FOR CONTINUE...\n";
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

void displayPlayersNameWithSymbol(char firstPlayerName[], char firstPlayerSymbol, char secondPlayerName[], char secondPlayerSymbol)
{
    system("cls");
    cout << "\nFIRST PLAYER NAME - " << firstPlayerName << " AND YOUR SYMBOL IS: " << firstPlayerSymbol;
    cout << "\nSECOND PLAYER NAME - " << secondPlayerName << " AND YOUR SYMBOL IS: " << secondPlayerSymbol << "\n";
    cout << "\n\tYOU CANE EXIT THE GAME ANY TIME BYE JUST TYPING 100 AND ENTER OR FOR NEW GAME TYPING 101\n\n";
}

char symbolChooser(char playerName[], char playerSymbol = ' ', int computer = 0)
{
    int options;
    char symbol;
    while (1)
    {
        if (computer == 2 || computer == 3) // if we play with smartCom or evilCom
        {
            symbol = playerSymbol != 'X' ? 'X' : 'O';
            return symbol;
        }
        else // if we play with frined
        {
            cout << "\n " << playerName << " YOU CAN CHOOSE YOUR SYMBOL, HERE SOME SYMBOL AVAILBLE ";
            cout << "\n\t1 - 'X'\n\t2 - 'O\n\t3 - ALPHABETS FROM A-Z(RANDOMALY SELECTED)\n\nPLEASE CHOOSE YOUR SYMBOL: ";
            cin >> options;
            if (options < 1 || options > 3)
            {
                cout << "\n\n\tINVALID OPTION SELECTED, TRY AGAIN...!!\n\t\tPRESS ANY KEY..";
                getch();
                system("cls");
            }
            else
            {
                srand(time(0));
                int random = rand() % 26 + 65;
                symbol = (char)random;
                if ((options == 1 && 'X' == playerSymbol) || (options == 2 && 'O' == playerSymbol) || (options == 3 && symbol == playerSymbol))
                {
                    cout << "\n\n\tALREADY TAKE THIS SYMBOLS..!  TRY AGAIN...!!\n\t\tPRESS ANY KEY..";
                    getch();
                    system("cls");
                }
                else if (options == 1)
                    return 'X';
                else if (options == 2)
                    return 'O';
                else
                    return symbol;
            }
        }
    }
}

void displayGame()
{
    cout << "\n----------------TIC-TAC-TOE-GAME------------------\n";
    int i, j;
    for (i = 0; i < 3; i++)
    {
        cout << "\n\t\t  ";
        for (j = 0; j < 3; j++)
        {
            if (matrix[i][j] >= 1 && matrix[i][j] <= 9)
                cout << matrix[i][j] << "   ";
            else
                cout << (char)matrix[i][j] << "   ";
        }
        cout << "\n\n";
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

    return '@'; // if upper conditions doesn't match
}

void restartTheGame()
{
    while (1)
    {
        system("cls");
        int choice;
        cout << "\n\tDO YOU WANT TO PLAY AGAIN!\n1 - YES\n2 - NO\n\tENTER YOUR CHOICE: ";
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
            cout << "\n\tINVALID INPUT.... TRY AGAIN!\n\tPRESS ANY KEY...";
            getch();
        }
    }
}

void markingPlaceFriend(int markPlace, int alternate, char firstPlayerName[], char secondPlayerName[], char firstPlayerSymbol, char secondPlayerSymbol)
{
    char markingSign = alternate ? firstPlayerSymbol : secondPlayerSymbol; // get markingSign character
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (matrix[i][j] == markPlace)
                matrix[i][j] = markingSign;

    if (gameWinner(markingSign) == firstPlayerSymbol) // check firstPlayer Win
    {
        system("cls");
        displayPlayersNameWithSymbol(firstPlayerName, firstPlayerSymbol, secondPlayerName, secondPlayerSymbol);
        displayGame();
        cout << "\n\tCONGRAULATION--!, " << firstPlayerName << " YOU WIN THE GAME...";
        cout << "PRESS ANY KEY....";
        getch();
        restartTheGame();
    }
    else if (gameWinner(markingSign) == secondPlayerSymbol) // check secondPLayer Win
    {
        system("cls");
        displayPlayersNameWithSymbol(firstPlayerName, firstPlayerSymbol, secondPlayerName, secondPlayerSymbol);
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
    char firstPlayerSymbol, secondPlayerSymbol;
    char firstPlayerName[20], secondPlayerName[20];
    cout << "\n\n\t----PLAY WITH FIREND----\n\nENTER FIRST PLAYER NAME: ";
    cin.ignore();
    gets(firstPlayerName);
    firstPlayerSymbol = symbolChooser(firstPlayerName); // Default Argument - here we provide some options
    cout << firstPlayerName << ", \n\tYOUR SYMBOLS IS: " << firstPlayerSymbol << "\nPRESS ANY KEY..." << endl;
    getch();
    system("cls");
    cin.ignore();
    cout << "\nENTER SECOND PLAYER NAME: ";
    gets(secondPlayerName);
    secondPlayerSymbol = symbolChooser(secondPlayerName, firstPlayerSymbol); // Default ARgument
    cout << secondPlayerName << ", \n\tYOUR SYMBOLS IS: " << secondPlayerSymbol << "\nPRESS ANY KEY...\n";
    getch();
    system("cls");

    while (1)
    {
        while (1)
        {
            system("cls");
            displayPlayersNameWithSymbol(firstPlayerName, firstPlayerSymbol, secondPlayerName, secondPlayerSymbol);
            displayGame();
            if (alternate == 1)
                cout << "\n\n"
                     << firstPlayerName << ", ENTER MARKING PLACE: ";
            else
                cout << "\n\n"
                     << secondPlayerName << ", ENTER MARKING PLACE: ";
            cin >> markPlace;
            cin.ignore();
            if ((markPlace >= 1 && markPlace <= 9) && check_exist(markPlace))
            {
                alternate ? alternate = 0 : alternate = 1; // alterNate Player chanage
                break;
            }
            else if (markPlace == 100)
            {
                cout << "\nYOU ENTER 100 FOR EXIT...!\n\tBYE..";
                exit(0);
            }
            else if (markPlace == 101)
            {
                cout << "\nYOU ENTER 101 FOR MAIN MENU....!\n\tPRESS ANY KEY....";
                getch();
                main();
            }
            else
            {
                cout << "\n\tINVALID INPUT OR ALREADY TAKE! TRY AGAIN....\nPRESS ANY KEY FOR CONTINUE....";
                cin.ignore();
                getch();
            }
        }

        markingPlaceFriend(markPlace, !(alternate), firstPlayerName, secondPlayerName, firstPlayerSymbol, secondPlayerSymbol);

        if (--totalMoves == 0) // if match is drawn
        {
            system("cls");
            displayPlayersNameWithSymbol(firstPlayerName, firstPlayerSymbol, secondPlayerName, secondPlayerSymbol);
            displayGame();
            cout << "\n\tOOPS!, MATCH IS DRAW..!!\nPRESS ANY KEY.......";
            getch();
            restartTheGame();
        }
    }
}

void markingPlaceSmartComputer(int markPlace, char firstPlayerName[], char secondPlayerName[], int totalMoves, char firstPlayerSymbol, char secondPlayerSymbol)
{
    int computerMove;
    srand(time(0));
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (matrix[i][j] == markPlace)
                matrix[i][j] = firstPlayerSymbol;

    system("cls");
    displayPlayersNameWithSymbol(firstPlayerName, firstPlayerSymbol, secondPlayerName, secondPlayerSymbol);
    displayGame();

    if (gameWinner(firstPlayerSymbol) == firstPlayerSymbol)
    {
        system("cls");
        displayPlayersNameWithSymbol(firstPlayerName, firstPlayerSymbol, secondPlayerName, secondPlayerSymbol);
        displayGame();
        cout << "\n\tCONGRAULATION--!, " << firstPlayerName << " YOU WIN THE GAME...";
        cout << "PRESS ANY KEY....";
        getch();
        restartTheGame();
    }

    // for win
    // for first row
    if (matrix[0][0] == secondPlayerSymbol && matrix[0][1] == secondPlayerSymbol && matrix[0][2] != firstPlayerSymbol)
    {
        matrix[0][2] = secondPlayerSymbol;
        computerMove = 3;
    }
    else if (matrix[0][0] == secondPlayerSymbol && matrix[0][2] == secondPlayerSymbol && matrix[0][1] != firstPlayerSymbol)
    {
        matrix[0][1] = secondPlayerSymbol;
        computerMove = 2;
    }
    else if (matrix[0][1] == secondPlayerSymbol && matrix[0][2] == secondPlayerSymbol && matrix[0][0] != firstPlayerSymbol)
    {
        matrix[0][0] = secondPlayerSymbol;
        computerMove = 0;
    }

    // for second row
    else if (matrix[1][0] == secondPlayerSymbol && matrix[1][1] == secondPlayerSymbol && matrix[1][2] != firstPlayerSymbol)
    {
        matrix[1][2] = secondPlayerSymbol;
        computerMove = 6;
    }
    else if (matrix[1][0] == secondPlayerSymbol && matrix[1][2] == secondPlayerSymbol && matrix[1][1] != firstPlayerSymbol)
    {
        matrix[1][1] = secondPlayerSymbol;
        computerMove = 5;
    }
    else if (matrix[1][1] == secondPlayerSymbol && matrix[1][2] == secondPlayerSymbol && matrix[1][0] != firstPlayerSymbol)
    {
        matrix[1][0] = secondPlayerSymbol;
        computerMove = 4;
    }

    // for third row
    else if (matrix[2][0] == secondPlayerSymbol && matrix[2][1] == secondPlayerSymbol && matrix[2][2] != firstPlayerSymbol)
    {
        matrix[2][2] = secondPlayerSymbol;
        computerMove = 9;
    }
    else if (matrix[2][0] == secondPlayerSymbol && matrix[2][2] == secondPlayerSymbol && matrix[2][1] != firstPlayerSymbol)
    {
        matrix[2][1] = secondPlayerSymbol;
        computerMove = 8;
    }
    else if (matrix[2][1] == secondPlayerSymbol && matrix[2][2] == secondPlayerSymbol && matrix[2][0] != firstPlayerSymbol)
    {
        matrix[2][0] = secondPlayerSymbol;
        computerMove = 7;
    }

    // for first col
    else if (matrix[0][0] == secondPlayerSymbol && matrix[1][0] == secondPlayerSymbol && matrix[2][0] != firstPlayerSymbol)
    {
        matrix[2][0] = secondPlayerSymbol;
        computerMove = 7;
    }
    else if (matrix[0][0] == secondPlayerSymbol && matrix[2][0] == secondPlayerSymbol && matrix[1][0] != firstPlayerSymbol)
    {
        matrix[1][0] = secondPlayerSymbol;
        computerMove = 4;
    }
    else if (matrix[1][0] == secondPlayerSymbol && matrix[2][0] == secondPlayerSymbol && matrix[0][0] != firstPlayerSymbol)
    {
        matrix[0][0] = secondPlayerSymbol;
        computerMove = 1;
    }

    // for second col
    else if (matrix[0][1] == secondPlayerSymbol && matrix[1][1] == secondPlayerSymbol && matrix[2][1] != firstPlayerSymbol)
    {
        matrix[2][1] = secondPlayerSymbol;
        computerMove = 8;
    }
    else if (matrix[0][1] == secondPlayerSymbol && matrix[2][1] == secondPlayerSymbol && matrix[1][1] != firstPlayerSymbol)
    {
        matrix[1][1] = secondPlayerSymbol;
        computerMove = 5;
    }
    else if (matrix[1][1] == secondPlayerSymbol && matrix[2][1] == secondPlayerSymbol && matrix[0][1] != firstPlayerSymbol)
    {
        matrix[0][1] = secondPlayerSymbol;
        computerMove = 2;
    }

    // for third col
    else if (matrix[0][2] == secondPlayerSymbol && matrix[1][2] == secondPlayerSymbol && matrix[2][2] != firstPlayerSymbol)
    {
        matrix[2][2] = secondPlayerSymbol;
        computerMove = 9;
    }
    else if (matrix[0][2] == secondPlayerSymbol && matrix[2][2] == secondPlayerSymbol && matrix[1][2] != firstPlayerSymbol)
    {
        matrix[1][2] = secondPlayerSymbol;
        computerMove = 6;
    }
    else if (matrix[1][2] == secondPlayerSymbol && matrix[2][2] == secondPlayerSymbol && matrix[0][2] != firstPlayerSymbol)
    {
        matrix[0][2] = secondPlayerSymbol;
        computerMove = 3;
    }

    // for left diagonal
    else if (matrix[0][0] == secondPlayerSymbol && matrix[1][1] == secondPlayerSymbol && matrix[2][2] != firstPlayerSymbol)
    {
        matrix[2][2] = secondPlayerSymbol;
        computerMove = 9;
    }
    else if (matrix[0][0] == secondPlayerSymbol && matrix[2][2] == secondPlayerSymbol && matrix[1][1] != firstPlayerSymbol)
    {
        matrix[1][1] = secondPlayerSymbol;
        computerMove = 5;
    }
    else if (matrix[1][1] == secondPlayerSymbol && matrix[2][2] == secondPlayerSymbol && matrix[0][0] != firstPlayerSymbol)
    {
        matrix[0][0] = secondPlayerSymbol;
        computerMove = 1;
    }

    // for right diagonal
    else if (matrix[0][2] == secondPlayerSymbol && matrix[1][1] == secondPlayerSymbol && matrix[2][0] != firstPlayerSymbol)
    {
        matrix[2][0] = secondPlayerSymbol;
        computerMove = 7;
    }
    else if (matrix[0][2] == secondPlayerSymbol && matrix[2][0] == secondPlayerSymbol && matrix[1][1] != firstPlayerSymbol)
    {
        matrix[1][1] = secondPlayerSymbol;
        computerMove = 5;
    }
    else if (matrix[1][1] == secondPlayerSymbol && matrix[2][0] == secondPlayerSymbol && matrix[0][2] != firstPlayerSymbol)
    {
        matrix[0][2] = secondPlayerSymbol;
        computerMove = 3;
    }

    // for defend
    // for first row
    else if (matrix[0][0] == firstPlayerSymbol && matrix[0][1] == firstPlayerSymbol && matrix[0][2] != secondPlayerSymbol)
    {
        matrix[0][2] = secondPlayerSymbol;
        computerMove = 3;
    }
    else if (matrix[0][0] == firstPlayerSymbol && matrix[0][2] == firstPlayerSymbol && matrix[0][1] != secondPlayerSymbol)
    {
        matrix[0][1] = secondPlayerSymbol;
        computerMove = 2;
    }
    else if (matrix[0][1] == firstPlayerSymbol && matrix[0][2] == firstPlayerSymbol && matrix[0][0] != secondPlayerSymbol)
    {
        matrix[0][0] = secondPlayerSymbol;
        computerMove = 1;
    }

    // for second row
    else if (matrix[1][0] == firstPlayerSymbol && matrix[1][1] == firstPlayerSymbol && matrix[1][2] != secondPlayerSymbol)
    {
        matrix[1][2] = secondPlayerSymbol;
        computerMove = 6;
    }
    else if (matrix[1][0] == firstPlayerSymbol && matrix[1][2] == firstPlayerSymbol && matrix[1][1] != secondPlayerSymbol)
    {
        matrix[1][1] = secondPlayerSymbol;
        computerMove = 5;
    }
    else if (matrix[1][1] == firstPlayerSymbol && matrix[1][2] == firstPlayerSymbol && matrix[1][0] != secondPlayerSymbol)
    {
        matrix[1][0] = secondPlayerSymbol;
        computerMove = 4;
    }

    // for third row
    else if (matrix[2][0] == firstPlayerSymbol && matrix[2][1] == firstPlayerSymbol && matrix[2][2] != secondPlayerSymbol)
    {
        matrix[2][2] = secondPlayerSymbol;
        computerMove = 9;
    }
    else if (matrix[2][0] == firstPlayerSymbol && matrix[2][2] == firstPlayerSymbol && matrix[2][1] != secondPlayerSymbol)
    {
        matrix[2][1] = secondPlayerSymbol;
        computerMove = 8;
    }
    else if (matrix[2][1] == firstPlayerSymbol && matrix[2][2] == firstPlayerSymbol && matrix[2][0] != secondPlayerSymbol)
    {
        matrix[2][0] = secondPlayerSymbol;
        computerMove = 7;
    }

    // for first col
    else if (matrix[0][0] == firstPlayerSymbol && matrix[1][0] == firstPlayerSymbol && matrix[2][0] != secondPlayerSymbol)
    {
        matrix[2][0] = secondPlayerSymbol;
        computerMove = 7;
    }
    else if (matrix[0][0] == firstPlayerSymbol && matrix[2][0] == firstPlayerSymbol && matrix[1][0] != secondPlayerSymbol)
    {
        matrix[1][0] = secondPlayerSymbol;
        computerMove = 4;
    }
    else if (matrix[1][0] == firstPlayerSymbol && matrix[2][0] == firstPlayerSymbol && matrix[0][0] != secondPlayerSymbol)
    {
        matrix[0][0] = secondPlayerSymbol;
        computerMove = 1;
    }

    // for second col
    else if (matrix[0][1] == firstPlayerSymbol && matrix[1][1] == firstPlayerSymbol && matrix[2][1] != secondPlayerSymbol)
    {
        matrix[2][1] = secondPlayerSymbol;
        computerMove = 8;
    }
    else if (matrix[0][1] == firstPlayerSymbol && matrix[2][1] == firstPlayerSymbol && matrix[1][1] != secondPlayerSymbol)
    {
        matrix[1][1] = secondPlayerSymbol;
        computerMove = 5;
    }
    else if (matrix[1][1] == firstPlayerSymbol && matrix[2][1] == firstPlayerSymbol && matrix[0][1] != secondPlayerSymbol)
    {
        matrix[0][1] = secondPlayerSymbol;
        computerMove = 2;
    }

    // for third row
    else if (matrix[0][2] == firstPlayerSymbol && matrix[1][2] == firstPlayerSymbol && matrix[2][2] != secondPlayerSymbol)
    {
        matrix[2][2] = secondPlayerSymbol;
        computerMove = 9;
    }
    else if (matrix[0][2] == firstPlayerSymbol && matrix[2][2] == firstPlayerSymbol && matrix[1][2] != secondPlayerSymbol)
    {
        matrix[1][2] = secondPlayerSymbol;
        computerMove = 6;
    }
    else if (matrix[1][2] == firstPlayerSymbol && matrix[2][2] == firstPlayerSymbol && matrix[0][2] != secondPlayerSymbol)
    {
        matrix[0][2] = secondPlayerSymbol;
        computerMove = 3;
    }

    // for left diagonal
    else if (matrix[0][0] == firstPlayerSymbol && matrix[1][1] == firstPlayerSymbol && matrix[2][2] != secondPlayerSymbol)
    {
        matrix[2][2] = secondPlayerSymbol;
        computerMove = 9;
    }
    else if (matrix[0][0] == firstPlayerSymbol && matrix[2][2] == firstPlayerSymbol && matrix[1][1] != secondPlayerSymbol)
    {
        matrix[1][1] = secondPlayerSymbol;
        computerMove = 5;
    }
    else if (matrix[1][1] == firstPlayerSymbol && matrix[2][2] == firstPlayerSymbol && matrix[0][0] != secondPlayerSymbol)
    {
        matrix[0][0] = secondPlayerSymbol;
        computerMove = 1;
    }

    // for right diagonal
    else if (matrix[0][2] == firstPlayerSymbol && matrix[1][1] == firstPlayerSymbol && matrix[2][0] != secondPlayerSymbol)
    {
        matrix[2][0] = secondPlayerSymbol;
        computerMove = 7;
    }
    else if (matrix[0][2] == firstPlayerSymbol && matrix[2][0] == firstPlayerSymbol && matrix[1][1] != secondPlayerSymbol)
    {
        matrix[1][1] = secondPlayerSymbol;
        computerMove = 5;
    }
    else if (matrix[1][1] == firstPlayerSymbol && matrix[2][0] == firstPlayerSymbol && matrix[0][2] != secondPlayerSymbol)
    {
        matrix[0][2] = secondPlayerSymbol;
        computerMove = 3;
    }
    else
    {
        if (totalMoves <= 0)
        {
            system("cls");
            displayPlayersNameWithSymbol(firstPlayerName, firstPlayerSymbol, secondPlayerName, secondPlayerSymbol);
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
                                matrix[i][j] = secondPlayerSymbol;

                    computerMove = random;
                    break;
                }
            }
        }
    }

    if (gameWinner(secondPlayerSymbol) == secondPlayerSymbol)
    {
        system("cls");
        displayPlayersNameWithSymbol(firstPlayerName, firstPlayerSymbol, secondPlayerName, secondPlayerSymbol);
        displayGame();
        cout << "\nSMART COMPUTER PLACE: " << computerMove;
        cout << "\n\tYOU LOSE THE GAME--!, " << secondPlayerName << " WIN THE GAME...";
        cout << "PRESS ANY KEY....";
        getch();
        restartTheGame();
    }
    system("cls");
    displayPlayersNameWithSymbol(firstPlayerName, firstPlayerSymbol, secondPlayerName, secondPlayerSymbol);
    displayGame();
    cout << "\nSMART COMPUTER PLACE: " << computerMove << "\n\tPRESS ANY KEY...";
    getch();
}

void playWithSmartComputer()
{
    system("cls");
    int markPlace, totalMoves = 9;
    char firstPlayerName[20], secondPlayerName[20];
    char firstPlayerSymbol, secondPlayerSymbol;
    cout << "\n\n\t----PLAY WITH SMART COMPUTER----\n";
    cout << "\nENTER PLAYER NAME: ";
    cin.ignore();
    gets(firstPlayerName);
    firstPlayerSymbol = symbolChooser(firstPlayerName); // Default Argument
    system("cls");
    cout << firstPlayerName << ", \n\tYOUR SYMBOLS IS: " << firstPlayerSymbol << "\n";
    strcpy(secondPlayerName, "SMART COMPUTER ");
    secondPlayerSymbol = symbolChooser(secondPlayerName, firstPlayerSymbol, 2); // Default ARgument amd 2 means smart computer
    cout << secondPlayerName << ", \n\tYOUR SYMBOLS IS: " << secondPlayerSymbol << "\nPRESS ANY KEY..." << endl;
    getch();
    system("cls");

    while (1)
    {
        while (1)
        {
            system("cls");
            displayPlayersNameWithSymbol(firstPlayerName, firstPlayerSymbol, secondPlayerName, secondPlayerSymbol);
            displayGame();
            cout << "\n"
                 << firstPlayerName << ", ENTER MARKING PLACE: ";
            cin >> markPlace;
            if ((markPlace >= 1 && markPlace <= 9) && check_exist(markPlace))
                break;
            else if (markPlace == 100)
            {
                cout << "\nYOU ENTER 100 FOR EXIT...!\n\tBYE..";
                exit(0);
            }
            else if (markPlace == 101)
            {
                cout << "\nYOU ENTER 101 FOR MAIN MENU....!\n\tPRESS ANY KEY....";
                getch();
                main();
            }
            else
            {
                cout << "\n\tINVALID INPUT OR ALREADY TAKE! TRY AGAIN....\nPRESS ANY KEY FOR CONTINUE....";
                getch();
            }
        }
        totalMoves -= 2;
        markingPlaceSmartComputer(markPlace, firstPlayerName, secondPlayerName, totalMoves, firstPlayerSymbol, secondPlayerSymbol);
    }
}

void markingPlaceEvilComputer(int markPlace, char firstPlayerName[], char secondPlayerName[], int &totalMoves, char firstPlayerSymbol, char secondPlayerSymbol)
{
    int computerMove = -1, computerMove2 = -1;
    srand(time(0));
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (matrix[i][j] == markPlace)
            {
                matrix[i][j] = firstPlayerSymbol;
                totalMoves--;
            }

    system("cls");
    displayPlayersNameWithSymbol(firstPlayerName, firstPlayerSymbol, secondPlayerName, secondPlayerSymbol);
    displayGame();

    if (gameWinner(firstPlayerSymbol) == firstPlayerSymbol)
    {
        system("cls");
        displayPlayersNameWithSymbol(firstPlayerName, firstPlayerSymbol, secondPlayerName, secondPlayerSymbol);
        displayGame();
        cout << "\n\tCONGRAULATION--!, " << firstPlayerName << " YOU WIN THE GAME...";
        cout << "PRESS ANY KEY....";
        getch();
        restartTheGame();
    }
    if (totalMoves <= 0)
    {
        system("cls");
        displayPlayersNameWithSymbol(firstPlayerName, firstPlayerSymbol, secondPlayerName, secondPlayerSymbol);
        displayGame();
        cout << "\n\tOOPS...!! MATCH IS DRAWN...\nPRESS ANY KEY...";
        getch();
        restartTheGame();
    }
    // for win
    // for first row
    if (matrix[0][0] == secondPlayerSymbol && matrix[0][1] == secondPlayerSymbol && matrix[0][2] != secondPlayerSymbol)
    {
        matrix[0][2] = secondPlayerSymbol;
        totalMoves--;
        computerMove = 3;
    }
    else if (matrix[0][0] == secondPlayerSymbol && matrix[0][2] == secondPlayerSymbol && matrix[0][1] != secondPlayerSymbol)
    {
        matrix[0][1] = secondPlayerSymbol;
        totalMoves--;
        computerMove = 2;
    }
    else if (matrix[0][1] == secondPlayerSymbol && matrix[0][2] == secondPlayerSymbol && matrix[0][0] != 'X')
    {
        matrix[0][0] = secondPlayerSymbol;
        totalMoves--;
        computerMove = 1;
    }

    // for second row
    else if (matrix[1][0] == secondPlayerSymbol && matrix[1][1] == secondPlayerSymbol && matrix[1][2] != secondPlayerSymbol)
    {
        matrix[1][2] = secondPlayerSymbol;
        totalMoves--;
        computerMove = 6;
    }
    else if (matrix[1][0] == firstPlayerSymbol && matrix[1][2] == firstPlayerSymbol && matrix[1][1] != secondPlayerSymbol)
    {
        matrix[1][1] = firstPlayerSymbol;
        totalMoves--;
        computerMove = 5;
    }
    else if (matrix[1][1] == secondPlayerSymbol && matrix[1][2] == secondPlayerSymbol && matrix[1][0] != secondPlayerSymbol)
    {
        matrix[1][0] = secondPlayerSymbol;
        totalMoves--;
        computerMove = 4;
    }

    // for third row
    else if (matrix[2][0] == secondPlayerSymbol && matrix[2][1] == secondPlayerSymbol && matrix[2][2] != secondPlayerSymbol)
    {
        matrix[2][2] = secondPlayerSymbol;
        totalMoves--;
        computerMove = 9;
    }
    else if (matrix[2][0] == secondPlayerSymbol && matrix[2][2] == secondPlayerSymbol && matrix[2][1] != secondPlayerSymbol)
    {
        matrix[2][1] = secondPlayerSymbol;
        totalMoves--;
        computerMove = 8;
    }
    else if (matrix[2][1] == secondPlayerSymbol && matrix[2][2] == secondPlayerSymbol && matrix[2][0] != secondPlayerSymbol)
    {
        matrix[2][0] = secondPlayerSymbol;
        totalMoves--;
        computerMove = 7;
    }

    // for first col
    else if (matrix[0][0] == secondPlayerSymbol && matrix[1][0] == secondPlayerSymbol && matrix[2][0] != secondPlayerSymbol)
    {
        matrix[2][0] = secondPlayerSymbol;
        totalMoves--;
        computerMove = 7;
    }
    else if (matrix[0][0] == secondPlayerSymbol && matrix[2][0] == secondPlayerSymbol && matrix[1][0] != secondPlayerSymbol)
    {
        matrix[1][0] = secondPlayerSymbol;
        totalMoves--;
        computerMove = 4;
    }
    else if (matrix[1][0] == secondPlayerSymbol && matrix[2][0] == secondPlayerSymbol && matrix[0][0] != secondPlayerSymbol)
    {
        matrix[0][0] = secondPlayerSymbol;
        totalMoves--;
        computerMove = 1;
    }

    // for second col
    else if (matrix[0][1] == secondPlayerSymbol && matrix[1][1] == secondPlayerSymbol && matrix[2][1] != secondPlayerSymbol)
    {
        matrix[2][1] = secondPlayerSymbol;
        totalMoves--;
        computerMove = 8;
    }
    else if (matrix[0][1] == secondPlayerSymbol && matrix[2][1] == secondPlayerSymbol && matrix[1][1] != secondPlayerSymbol)
    {
        matrix[1][1] = secondPlayerSymbol;
        totalMoves--;
        computerMove = 5;
    }
    else if (matrix[1][1] == secondPlayerSymbol && matrix[2][1] == secondPlayerSymbol && matrix[0][1] != secondPlayerSymbol)
    {
        matrix[0][1] = secondPlayerSymbol;
        totalMoves--;
        computerMove = 2;
    }

    // for third col
    else if (matrix[0][2] == secondPlayerSymbol && matrix[1][2] == secondPlayerSymbol && matrix[2][2] != secondPlayerSymbol)
    {
        matrix[2][2] = secondPlayerSymbol;
        totalMoves--;
        computerMove = 9;
    }
    else if (matrix[0][2] == secondPlayerSymbol && matrix[2][2] == secondPlayerSymbol && matrix[1][2] != 'X')
    {
        matrix[1][2] = secondPlayerSymbol;
        totalMoves--;
        computerMove = 6;
    }
    else if (matrix[1][2] == secondPlayerSymbol && matrix[2][2] == secondPlayerSymbol && matrix[0][2] != secondPlayerSymbol)
    {
        matrix[0][2] = secondPlayerSymbol;
        totalMoves--;
        computerMove = 3;
    }

    // for left diagonal
    else if (matrix[0][0] == secondPlayerSymbol && matrix[1][1] == secondPlayerSymbol && matrix[2][2] != secondPlayerSymbol)
    {
        matrix[2][2] = secondPlayerSymbol;
        totalMoves--;
        computerMove = 9;
    }
    else if (matrix[0][0] == secondPlayerSymbol && matrix[2][2] == secondPlayerSymbol && matrix[1][1] != secondPlayerSymbol)
    {
        matrix[1][1] = secondPlayerSymbol;
        totalMoves--;
        computerMove = 5;
    }
    else if (matrix[1][1] == secondPlayerSymbol && matrix[2][2] == secondPlayerSymbol && matrix[0][0] != secondPlayerSymbol)
    {
        matrix[0][0] = secondPlayerSymbol;
        totalMoves--;
        computerMove = 1;
    }

    // for right diagonal
    else if (matrix[0][2] == secondPlayerSymbol && matrix[1][1] == secondPlayerSymbol && matrix[2][0] != secondPlayerSymbol)
    {
        matrix[2][0] = secondPlayerSymbol;
        totalMoves--;
        computerMove = 7;
    }
    else if (matrix[0][2] == secondPlayerSymbol && matrix[2][0] == secondPlayerSymbol && matrix[1][1] != secondPlayerSymbol)
    {
        matrix[1][1] = secondPlayerSymbol;
        totalMoves--;
        computerMove = 5;
    }
    else if (matrix[1][1] == secondPlayerSymbol && matrix[2][0] == secondPlayerSymbol && matrix[0][2] != secondPlayerSymbol)
    {
        matrix[0][2] = secondPlayerSymbol;
        totalMoves--;
        computerMove = 3;
    }

    if (gameWinner(secondPlayerSymbol) == secondPlayerSymbol)
    {
        system("cls");
        displayPlayersNameWithSymbol(firstPlayerName, firstPlayerSymbol, secondPlayerName, secondPlayerSymbol);
        displayGame();
        cout << "\nEVIL COMPUTER MARKING PLACE: " << computerMove;
        cout << "\n\tYOU LOSE THE GAME--!, " << secondPlayerName << " WIN THE GAME...";
        cout << "PRESS ANY KEY....";
        getch();
        restartTheGame();
    }

    // for defend
    // for first row
    int flag = 0;
    if (matrix[0][0] == firstPlayerSymbol && matrix[0][1] == firstPlayerSymbol && matrix[0][2] != secondPlayerSymbol)
    {
        matrix[0][2] = secondPlayerSymbol;
        flag = 1;
        totalMoves--;
        if (computerMove == -1)
            computerMove = 3;
        else
            computerMove2 = 3;
    }
    else if (matrix[0][0] == firstPlayerSymbol && matrix[0][2] == firstPlayerSymbol && matrix[0][1] != secondPlayerSymbol)
    {
        matrix[0][1] = secondPlayerSymbol;
        flag = 1;
        totalMoves--;
        if (computerMove == -1)
            computerMove = 2;
        else
            computerMove2 = 2;
    }
    else if (matrix[0][1] == firstPlayerSymbol && matrix[0][2] == firstPlayerSymbol && matrix[0][0] != secondPlayerSymbol)
    {
        matrix[0][0] = secondPlayerSymbol;
        flag = 1;
        totalMoves--;
        if (computerMove == -1)
            computerMove = 1;
        else
            computerMove2 = 1;
    }

    // for second row
    if (matrix[1][0] == firstPlayerSymbol && matrix[1][1] == firstPlayerSymbol && matrix[1][2] != secondPlayerSymbol)
    {
        matrix[1][2] = secondPlayerSymbol;
        totalMoves--;
        flag = 1;
        if (computerMove == -1)
            computerMove = 6;
        else
            computerMove2 = 6;
    }
    else if (matrix[1][0] == firstPlayerSymbol && matrix[1][2] == firstPlayerSymbol && matrix[1][1] != secondPlayerSymbol)
    {
        matrix[1][1] = secondPlayerSymbol;
        flag = 1;
        totalMoves--;
        if (computerMove == -1)
            computerMove = 5;
        else
            computerMove2 = 5;
    }
    else if (matrix[1][1] == firstPlayerSymbol && matrix[1][2] == firstPlayerSymbol && matrix[1][0] != secondPlayerSymbol)
    {
        matrix[1][0] = secondPlayerSymbol;
        flag = 1;
        totalMoves--;
        if (computerMove == -1)
            computerMove = 4;
        else
            computerMove2 = 4;
    }

    // for third row
    if (matrix[2][0] == firstPlayerSymbol && matrix[2][1] == firstPlayerSymbol && matrix[2][2] != secondPlayerSymbol)
    {
        matrix[2][2] = secondPlayerSymbol;
        flag = 1;
        totalMoves--;
        if (computerMove == -1)
            computerMove = 9;
        else
            computerMove2 = 9;
    }
    else if (matrix[2][0] == firstPlayerSymbol && matrix[2][2] == firstPlayerSymbol && matrix[2][1] != secondPlayerSymbol)
    {
        matrix[2][1] = secondPlayerSymbol;
        totalMoves--;
        flag = 1;
        if (computerMove == -1)
            computerMove = 8;
        else
            computerMove2 = 8;
    }
    else if (matrix[2][1] == firstPlayerSymbol && matrix[2][2] == firstPlayerSymbol && matrix[2][0] != secondPlayerSymbol)
    {
        matrix[2][0] = secondPlayerSymbol;
        totalMoves--;
        flag = 1;
        if (computerMove == -1)
            computerMove = 7;
        else
            computerMove2 = 7;
    }

    // for first col
    if (matrix[0][0] == firstPlayerSymbol && matrix[1][0] == firstPlayerSymbol && matrix[2][0] != secondPlayerSymbol)
    {
        matrix[2][0] = secondPlayerSymbol;
        totalMoves--;
        flag = 1;
        if (computerMove == -1)
            computerMove = 7;
        else
            computerMove2 = 7;
    }
    else if (matrix[0][0] == firstPlayerSymbol && matrix[2][0] == firstPlayerSymbol && matrix[1][0] != secondPlayerSymbol)
    {
        matrix[1][0] = secondPlayerSymbol;
        flag = 1;
        totalMoves--;
        if (computerMove == -1)
            computerMove = 4;
        else
            computerMove2 = 4;
    }
    else if (matrix[1][0] == firstPlayerSymbol && matrix[2][0] == firstPlayerSymbol && matrix[0][0] != secondPlayerSymbol)
    {
        matrix[0][0] = secondPlayerSymbol;
        flag = 1;
        totalMoves--;
        if (computerMove == -1)
            computerMove = 1;
        else
            computerMove2 = 1;
    }

    // for second col
    if (matrix[0][1] == firstPlayerSymbol && matrix[1][1] == firstPlayerSymbol && matrix[2][1] != secondPlayerSymbol)
    {
        matrix[2][1] = secondPlayerSymbol;
        flag = 1;
        totalMoves--;
        if (computerMove == -1)
            computerMove = 8;
        else
            computerMove2 = 8;
    }
    else if (matrix[0][1] == firstPlayerSymbol && matrix[2][1] == firstPlayerSymbol && matrix[1][1] != secondPlayerSymbol)
    {
        matrix[1][1] = secondPlayerSymbol;
        flag = 1;
        totalMoves--;
        if (computerMove == -1)
            computerMove = 5;
        else
            computerMove2 = 5;
    }
    else if (matrix[1][1] == firstPlayerSymbol && matrix[2][1] == firstPlayerSymbol && matrix[0][1] != secondPlayerSymbol)
    {
        matrix[0][1] = secondPlayerSymbol;
        flag = 1;
        totalMoves--;
        if (computerMove == -1)
            computerMove = 2;
        else
            computerMove2 = 2;
    }

    // for third row
    if (matrix[0][2] == firstPlayerSymbol && matrix[1][2] == firstPlayerSymbol && matrix[2][2] != secondPlayerSymbol)
    {
        matrix[2][2] = secondPlayerSymbol;
        flag = 1;
        totalMoves--;
        if (computerMove == -1)
            computerMove = 9;
        else
            computerMove2 = 9;
    }
    else if (matrix[0][2] == firstPlayerSymbol && matrix[2][2] == firstPlayerSymbol && matrix[1][2] != secondPlayerSymbol)
    {
        matrix[1][2] = secondPlayerSymbol;
        flag = 1;
        totalMoves--;
        if (computerMove == -1)
            computerMove = 6;
        else
            computerMove2 = 6;
    }
    else if (matrix[1][2] == firstPlayerSymbol && matrix[2][2] == firstPlayerSymbol && matrix[0][2] != secondPlayerSymbol)
    {
        matrix[0][2] = secondPlayerSymbol;
        flag = 1;
        totalMoves--;
        if (computerMove == -1)
            computerMove = 3;
        else
            computerMove2 = 3;
    }

    // for left diagonal
    if (matrix[0][0] == firstPlayerSymbol && matrix[1][1] == firstPlayerSymbol && matrix[2][2] != secondPlayerSymbol)
    {
        matrix[2][2] = secondPlayerSymbol;
        flag = 1;
        totalMoves--;
        if (computerMove == -1)
            computerMove = 9;
        else
            computerMove2 = 9;
    }
    else if (matrix[0][0] == firstPlayerSymbol && matrix[2][2] == firstPlayerSymbol && matrix[1][1] != secondPlayerSymbol)
    {
        matrix[1][1] = secondPlayerSymbol;
        flag = 1;
        if (computerMove == -1)
            computerMove = 5;
        else
            computerMove2 = 5;
        totalMoves--;
    }
    else if (matrix[1][1] == firstPlayerSymbol && matrix[2][2] == firstPlayerSymbol && matrix[0][0] != secondPlayerSymbol)
    {
        matrix[0][0] = secondPlayerSymbol;
        flag = 1;
        totalMoves--;
        if (computerMove == -1)
            computerMove = 1;
        else
            computerMove2 = 1;
    }

    // for right diagonal
    if (matrix[0][2] == firstPlayerSymbol && matrix[1][1] == firstPlayerSymbol && matrix[2][0] != secondPlayerSymbol)
    {
        matrix[2][0] = secondPlayerSymbol;
        flag = 1;
        totalMoves--;
        if (computerMove == -1)
            computerMove = 7;
        else
            computerMove2 = 7;
    }
    else if (matrix[0][2] == firstPlayerSymbol && matrix[2][0] == firstPlayerSymbol && matrix[1][1] != secondPlayerSymbol)
    {
        matrix[1][1] = secondPlayerSymbol;
        flag = 1;
        totalMoves--;
        if (computerMove == -1)
            computerMove = 5;
        else
            computerMove2 = 5;
    }
    else if (matrix[1][1] == firstPlayerSymbol && matrix[2][0] == firstPlayerSymbol && matrix[0][2] != secondPlayerSymbol)
    {
        matrix[0][2] = secondPlayerSymbol;
        flag = 1;
        totalMoves--;
        if (computerMove == -1)
            computerMove = 3;
        else
            computerMove2 = 3;
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
                            matrix[i][j] = secondPlayerSymbol;
                            totalMoves--;
                        }
                computerMove = random;
                break;
            }
        }
    }
    if (gameWinner(secondPlayerSymbol) == secondPlayerSymbol)
    {
        system("cls");
        displayPlayersNameWithSymbol(firstPlayerName, firstPlayerSymbol, secondPlayerName, secondPlayerSymbol);
        displayGame();
        if (computerMove != -1 && computerMove2 != -1)
            cout << "\nEVIL COMPUTER MARKING PLACE: " << computerMove << " AND " << computerMove2;
        else if (computerMove != -1)
            cout << "\nEVIL COMPUTER MARKING PLACE: " << computerMove;
        cout << "\n\tYOU LOSE THE GAME--!, " << secondPlayerName << " WIN THE GAME...";
        cout << "PRESS ANY KEY....";
        getch();
        restartTheGame();
    }
    if (totalMoves <= 0)
    {
        system("cls");
        displayPlayersNameWithSymbol(firstPlayerName, firstPlayerSymbol, secondPlayerName, secondPlayerSymbol);
        displayGame();
        cout << "\n\tOOPS...!! MATCH IS DRAWN...\nPRESS ANY KEY...";
        getch();
        restartTheGame();
    }
    system("cls");
    displayPlayersNameWithSymbol(firstPlayerName, firstPlayerSymbol, secondPlayerName, secondPlayerSymbol);
    displayGame();
    if (computerMove != -1 && computerMove2 != -1)
        cout << "\nEVIL COMPUTER MARKING PLACE: " << computerMove << " AND " << computerMove2;
    else if (computerMove != -1)
        cout << "\nEVIL COMPUTER MARKING PLACE: " << computerMove;
    cout << "\n\tPRESS ANY KEY...";
    getch();
}

void playWithEvilComputer()
{
    system("cls");
    int markPlace, totalMoves = 9;
    char firstPlayerName[20], secondPlayerName[20];
    char firstPlayerSymbol, secondPlayerSymbol;
    cout << "\n\n\t----PLAY WITH EVIL COMPUTER----\n";
    cout << "\nENTER PLAYER NAME: ";
    cin.ignore();
    gets(firstPlayerName);
    firstPlayerSymbol = symbolChooser(firstPlayerName); // Default Argument
    system("cls");
    cout << firstPlayerName << ", \n\tYOUR SYMBOLS IS: " << firstPlayerSymbol << "\n";
    strcpy(secondPlayerName, "EVIL COMPUTER ");
    secondPlayerSymbol = symbolChooser(secondPlayerName, firstPlayerSymbol, 3); // Default ARgument amd 3 means evil computer
    cout << secondPlayerName << ", \n\tYOUR SYMBOLS IS: " << secondPlayerSymbol << "\nPRESS ANY KEY..." << endl;
    getch();
    system("cls");

    while (1)
    {
        while (1)
        {
            system("cls");
            displayPlayersNameWithSymbol(firstPlayerName, firstPlayerSymbol, secondPlayerName, secondPlayerSymbol);
            displayGame();
            cout << "\n"
                 << firstPlayerName << ", ENTER MARKING PLACE: ";
            cin >> markPlace;
            if ((markPlace >= 1 && markPlace <= 9) && check_exist(markPlace))
                break;
            else if (markPlace == 100)
            {
                cout << "\nYOU ENTER 100 FOR EXIT...!\n\tBYE..";
                exit(0);
            }
            else if (markPlace == 101)
            {
                cout << "\nYOU ENTER 101 FOR MAIN MENU....!\n\tPRESS ANY KEY....";
                getch();
                main();
            }
            else
            {
                cout << "\n\tINVALID INPUT OR ALREADY TAKE! TRY AGAIN....\nPRESS ANY KEY FOR CONTINUE....";
                getch();
            }
        }
        markingPlaceEvilComputer(markPlace, firstPlayerName, secondPlayerName, totalMoves, firstPlayerSymbol, secondPlayerSymbol);
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
        system("cls");
        cout << "THANKU, FOR VISITING THE GAME, VISIT AGAIN!\nHAVE A GOOD DAY/NIGHT";
        exit(0);
    }

    return 0;
}

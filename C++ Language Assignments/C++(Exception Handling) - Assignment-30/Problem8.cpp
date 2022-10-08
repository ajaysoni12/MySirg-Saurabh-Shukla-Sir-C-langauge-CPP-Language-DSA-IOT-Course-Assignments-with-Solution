#include <iostream>
using namespace std;
bool ifUserPasswordValid(string passWord)
{
    int digit = -1, specialSymbol = -1, capitalChar = -1;
    int length = 0;
    for (int i = 0; passWord[i] != '\0'; i++)
    {
        if (passWord[i] >= '0' && passWord[i] <= '9')
            digit = 1;
        else if ( (passWord[i] >= 'A' && passWord[i] <= 'Z'))
            capitalChar = 1;
        else
            specialSymbol = 1;
        length++;
    }
    if (length < 6 || digit == -1 || capitalChar == -1 || specialSymbol == -1)
        return false;
    return true;
}
int main()
{
    string passWord;
    cout << "Enter user password: ";
    cin >> passWord;
    try
    {
        if (ifUserPasswordValid(passWord))
            cout << "\nuser password is valid..";
        else
            throw 'e';
    }
    catch (char e)
    {
        cout << "\nExeception occurr. " << e << ", Invalid user pasword";
    }

    return 0;
}
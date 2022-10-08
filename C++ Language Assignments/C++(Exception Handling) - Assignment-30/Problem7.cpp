#include <iostream>
using namespace std;
bool ifUsernameValid(string userName)
{
    int digit = -1, specialSymbol = -1, character = -1;
    int length = 0;
    for (int i = 0; userName[i] != '\0'; i++)
    {
        if (userName[i] >= '0' && userName[i] <= '9')
            digit = 1;
        else if ((userName[i] >= 'a' && userName[i] <= 'z') || (userName[i] >= 'A' && userName[i] <= 'Z'))
            character = 1;
        else
            specialSymbol = 1;
        length++;
    }
    if (length < 6 || digit == -1 || character == -1 || specialSymbol == -1)
        return false;
    return true;
}
int main()
{
    string userName;
    cout << "Enter user name: ";
    cin >> userName;
    try
    {
        if (ifUsernameValid(userName))
            cout << "\nUserName is valid..";
        else
            throw 'e';
    }
    catch (char e)
    {
        cout << "\nExeception occurr. " << e << ", Invalid username";
    }

    return 0;
}
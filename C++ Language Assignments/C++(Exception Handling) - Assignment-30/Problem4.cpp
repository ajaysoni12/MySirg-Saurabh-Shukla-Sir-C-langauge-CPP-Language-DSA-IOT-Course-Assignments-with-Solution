#include <iostream>
using namespace std;
bool isEmailValid(string email)
{
    int atFlag = -1, dotFlag = -1;
    int length = 0;
    for (int i = 0; email[i] != '\0'; i++)
    {
        if (email[i] == '@')
            atFlag = i;
        if (email[i] == '.')
            dotFlag = i;
        length++;
    }
    if (atFlag == -1 && dotFlag == -1)
        return 0;
    else if (atFlag > dotFlag)
        return 0; 
    else
        return 1;
}
int main()
{
    string email;
    cout << "Enter Email Id: ";
    cin >> email;
    try
    {
        if (isEmailValid(email))
            cout << "Email is valid..";
        else
            throw 'c';
    }
    catch (const char e)
    {
        cout << "\nException caught...!, Invalid email id..!";
    }
    return 0;
}
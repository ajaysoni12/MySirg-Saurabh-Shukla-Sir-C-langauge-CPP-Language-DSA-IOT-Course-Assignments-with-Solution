#include <iostream>
using namespace std;
bool isValidNickName(string nickName)
{
    int i;
    for (i = 0; nickName[i] != '\0'; i++)
    {
        if (nickName[i] >= '0' && nickName[i] <= '9')
            return false;
        else if (nickName[i] == ' ')
            return false;
        else if (!((nickName[i] >= 'a' && nickName[i] <= 'z') || (nickName[i] >= 'A' && nickName[i] <= 'Z')))
            return false; // this is for special symbol
    }
    if (i > 8)
        return false;
    return true;
}
int main()
{
    string nickName;
    cout << "Enter NickName: ";
    cin >> nickName;
    try
    {
        if (isValidNickName(nickName))
            cout << "\nValid nickname.." << endl;
        else
            throw 'e';
    }
    catch (char e)
    {
        cout << "\nException occur..." << e << "\nInvalid nickName" << endl;
    }

    return 0;
}
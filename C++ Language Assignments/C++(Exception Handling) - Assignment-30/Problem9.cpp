#include <iostream>
using namespace std;
bool isValidGamilId(string gmailId)
{
    int atContain = -1, gmailContain = -1;
    int i;
    if (gmailId.find("@gmail.com") != -1) // this funtion find substring in gmaild
        return true;
    return false;
}
int main()
{
    string gmailId;
    cout << "Enter Gemail Id - ";
    cin >> gmailId;
    try
    {
        if (isValidGamilId(gmailId))
            cout << "\nValid gmail id..";
        else
            throw 'e';
    }
    catch (char e)
    {
        cout << "\nException occurr... " << e << " \nInvalid gmaild id";
    }

    return 0;
}
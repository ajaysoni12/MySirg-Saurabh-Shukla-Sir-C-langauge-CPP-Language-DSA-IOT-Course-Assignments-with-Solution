#include <iostream>
#include <string.h>
using namespace std;
bool isValidNumber(string m)
{
    int i;
    for (i = 0; m[i] != '\0'; i++)
        ;
    if (i == 10)
        return true;
    return false;
}
int main()
{
    string mobileNum;
    cout<<"Enter Mobile Number: "; 
    cin >> mobileNum;
    try
    {
        if (isValidNumber(mobileNum))
            cout << "\nValid Mobile Number..." << endl;
        else
            throw 1;
    }
    catch (int n)
    {
        cout << "\nException Caught...\n Invalid Mobile Number" << endl;
    }

    return 0;
}
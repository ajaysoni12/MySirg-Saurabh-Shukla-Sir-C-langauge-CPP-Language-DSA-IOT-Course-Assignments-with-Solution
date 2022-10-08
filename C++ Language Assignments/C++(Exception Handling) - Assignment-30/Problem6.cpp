#include <iostream>
#include <string.h>
using namespace std;
bool isValidPinCode(string m)
{
    int i;
    for (i = 0; m[i] != '\0'; i++)
    {
        if (!(m[i] >= '0' && m[i] <= '9'))
            return false;
    }

    if (i == 6) 
        return true;
    return false;
}
int main()
{
    string pinCode;
    cout << "Enter Area Pincode: ";
    cin >> pinCode;
    try
    {
        if (isValidPinCode(pinCode))
            cout << "\nValid area pincode..." << endl;
        else
            throw 1;
    }
    catch (int n)
    {
        cout << "\nException Caught...\n Invalid area pincode" << endl;
    }

    return 0;
}
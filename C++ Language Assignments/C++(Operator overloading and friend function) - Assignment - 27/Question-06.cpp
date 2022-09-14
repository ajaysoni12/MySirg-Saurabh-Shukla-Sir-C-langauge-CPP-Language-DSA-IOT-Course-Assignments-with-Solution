/*
6. Create a class CString to represent a string.
a) Overload the + operator to concatenate two strings.
b) == to compare 2 strings. */
#include <iostream>
#include <string.h>
using namespace std;
class CString
{
private:
    char str[100];

public:
    void setString(char *arr)
    {
        strcpy(str, arr);
    }
    void showString()
    {
        cout << str << endl;
    }
    CString operator+(CString s) // concatenate two string
    {
        CString temp;
        strcpy(temp.str, str);
        int length = strlen(temp.str);
        strcpy(temp.str + length, s.str);
        return temp;
    }
    bool operator==(CString s) // compare two string (==)
    {
        if (strcmp(str, s.str) == 0)
            return 1;
        return 0;
    }
};
int main()
{
    CString s1, s2, s3;
    s1.setString("Welcome ");
    s2.setString("MySirG");
    s1.showString();
    s2.showString();
    s3 = s1 + s2; // s1.operator+(s2);
    cout<<"Concatenate String: "; 
    s3.showString();
    bool result = s1 == s2;
    if (result)
        cout << "String are equal";
    else
        cout << "String are not equal ";

    return 0;
}
/* 9. Consider the following class mystring
Class mystring
{
    char str [100];
Public:
    // methods
};
Overload operator “!” to reverse the case of each alphabet in the string
(Uppercase to Lowercase and vice versa). */
#include <iostream>
#include <string.h>
using namespace std;
class MyString
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
        cout << "String is: ";
        cout << str << endl;
    }
    MyString operator!()
    {
        MyString temp;
        strcpy(temp.str, str);
        for (int i = 0; str[i]; i++)
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
                temp.str[i] = str[i] + 32;
            else if (str[i] >= 'a' && str[i] < 'z')
                temp.str[i] = str[i] - 32;
        }
        return temp;
    }
};
int main()
{
    MyString s1, s2, s3;
    s1.setString("Ajay Soni");
    s1.showString();
    s2 = !s1;
    cout << "\n(Uppercase to Lowercase and vice versa)\n\n";
    s2.showString();
    return 0;
}

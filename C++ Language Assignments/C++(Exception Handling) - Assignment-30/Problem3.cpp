#include <iostream>
using namespace std;
int main()
{
    char Operator;
    float num1, num2, ans;
    cout << "\nPerform Arithmetic Operations on Two Numbers";
    cout << "\n---------------------------------------------";
    try
    {
        cout << "\nEnter First Number: ";
        cin >> num1;
        cout << "\nEnter operator: ";
        cin >> Operator;
        if (Operator != '+' && Operator != '-' && Operator != '*' && Operator != '/')
            throw Operator;
        cout << "Enter the second number: ";
        cin >> num2;
        if (num1 == 0)
            throw 0; 
        cout << "\n-------------------------------------------------------\n";
        switch (Operator)
        {
        case '+':
            ans = num1 + num2;
            break;
        case '-':
            ans = num1 - num2;
            break;
        case '*':
            ans = num1 * num2;
            break;
        case '/':
            ans = num1 / num2;
            break;
        default:
            break;
        }
        cout << "\nAnswer : " << num1 << " " << Operator << " " << num2 << " = " << ans << endl;
    }
    catch (const char c)
    {
        cout << "\nExcepiton Caught...\nWrong Operator : " << c << " is not a valid operator.." << endl;
    }
    catch (const int x)
    {
        cout << "\nError!, Wrong Operator.." << endl;
    }
    return 0;
}
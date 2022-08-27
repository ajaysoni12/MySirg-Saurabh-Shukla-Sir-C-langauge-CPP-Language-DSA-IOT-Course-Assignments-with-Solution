#include <iostream>
using namespace std;
bool checkFibonacciSeriesNum(int num)
{
    if (num == 0 || num == 1)
        return true;
    else
    {
        int x = 0, y = 1, temp;
        while (x + y <= num)
        {
            if (x + y == num)
                return true;
            temp = x + y;
            x = y;
            y = temp;
        }
    }
    return false;
}
int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if (checkFibonacciSeriesNum(num))
        cout << num << " is present in fibonacci series!";
    else
        cout << num << " is not present in fibonacci series!";
    return 0;
}
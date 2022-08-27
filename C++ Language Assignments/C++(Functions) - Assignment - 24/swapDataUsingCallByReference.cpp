#include <iostream>
using namespace std;
void swap(int &, int &);
int main()
{
    int num1, num2;
    cout << "Enter two number: ";
    cin >> num1 >> num2;
    cout << "\nBefore swaping: ";
    cout << "Num1 = " << num1 << " and Num2 = " << num2 << endl;
    swap(num1, num2);
    cout << "\nAfter swaping: ";
    cout << "Num1 = " << num1 << " and Num2 = " << num2 << endl;

    return 0;
}
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
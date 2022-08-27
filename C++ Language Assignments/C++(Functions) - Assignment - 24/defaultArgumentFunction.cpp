#include <iostream>
using namespace std;
int add(int num1, int num2, int num3 = 0); // this function able to add too argument or three argument number
int main()
{
    int num1, num2, num3;
    cout << "Enter two number: ";
    cin >> num1 >> num2;
    cout << "Sum of " << num1 << " and " << num2 << " is: " << add(num1, num2) << endl;
    cout << "\nNow enter three number: ";
    cin >> num1 >> num2 >> num3;
    cout << "Sum of " << num1 << ", " << num2 << " and " << num3 << " is: " << add(num1, num2, num3) << endl;
    return 0;
}
int add(int num1, int num2, int num3)
{
    return num1 + num2 + num3;
}
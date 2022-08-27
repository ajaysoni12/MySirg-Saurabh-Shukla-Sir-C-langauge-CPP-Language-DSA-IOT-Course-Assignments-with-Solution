#include <iostream>
using namespace std;

// we can make different type of function overloading for diff data type here we make only three function for int, float and double, you can also make for sort, long, long long etc.
int add(int num1, int num2)
{
    return num1 + num2;
}
float add(float num1, float num2)
{
    return num1 + num2;
}
double add(double num1, double num2)
{
    return num1 + num2;
}

using namespace std;
int main()
{
    double num1, num2;
    cout << "Enter two int type number: ";
    cin >> num1 >> num2;
    cout << " Sum is: " << add((int)num1, (int)num2) << endl;
    cout << "Enter two float type number: ";
    cin >> num1 >> num2;
    cout << "Sum is: " << add((float)num1, (float)num2) << endl;
    cout << "Enter two double type number: ";
    cin >> num1 >> num2;
    cout << "Sum is: " << add(num1, num2) << endl;
    return 0;
}
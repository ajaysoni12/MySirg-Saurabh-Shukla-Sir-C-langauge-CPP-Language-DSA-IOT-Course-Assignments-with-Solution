/*
9. Write a C++ program to find the maximum of two numbers.
*/
#include <iostream>
using namespace std;
int main()
{
    int num1 = 43, num2 = 6;
    cout << "Max of " << num1 << " and " << num2 << " is: " << (num1 > num2 ? num1 : num2);
    return 0;
}
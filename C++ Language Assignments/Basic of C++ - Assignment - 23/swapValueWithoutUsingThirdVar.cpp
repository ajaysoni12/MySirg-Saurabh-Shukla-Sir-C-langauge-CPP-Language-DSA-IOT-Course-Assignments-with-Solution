/*
8. Write a C++ program to swap values of two int variables without using third variable
*/
#include <iostream>
using namespace std;
int main()
{
    int num1 = 5, num2 = 3;
    cout << "Before Swapping, a = " << num1 << " b = " << num2 << endl;
    num1 = num1 + num2; // 8
    num2 = num1 - num2; // 3
    num1 = num1 - num2; // 5
    cout << "After Swapping, a = " << num1 << " b = " << num2 << endl;
    return 0;
}

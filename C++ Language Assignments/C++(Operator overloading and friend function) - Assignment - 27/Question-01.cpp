/*
1. Define a class Complex with appropriate instance variables and member functions.
Define following operators in the class:
a. +
b. -
c. *
d. ==
*/
#include <iostream>
using namespace std;
class Complex
{
private:
    int real, img;

public:
    void setData(int x, int y)
    {
        real = x;
        img = y;
    }
    void showData()
    {
        cout << real << " + " << img << "i" << endl;
    }
    Complex operator+(Complex C) // Part - A
    {
        Complex temp;
        temp.real = real + C.real;
        temp.img = img + C.img;
        return temp;
    }
    Complex operator-(Complex C) // Part - B
    {
        Complex temp;
        temp.real = real - C.real;
        temp.img = img - C.img;
        return temp;
    }
    Complex operator*(Complex C) // Part - 3
    {
        Complex temp;
        temp.real = real * C.real;
        temp.img = img * C.img;
        return temp;
    }
    bool operator==(Complex C) // Part - 4
    {
        if (real == C.real && img == C.img)
            return true;
        return false;
    }
};
int main()
{
    Complex c1, c2, c3, c4, c5, c6;
    c1.setData(5, 4);
    c2.setData(5, 4);
    c1.showData();
    c2.showData();
    c3 = c1 + c2; // c1.operator+(c2);
    c3.showData();
    c4 = c1 - c2; // c1.operator-(c2);
    c4.showData();
    c5 = c1 * c2; // c1.operator*(c2);
    c5.showData();
    bool result = c1 == c2; // c1.operator==(c2);
    result ? cout << "Equal" : cout << "Not Equal ";
    return 0;
}
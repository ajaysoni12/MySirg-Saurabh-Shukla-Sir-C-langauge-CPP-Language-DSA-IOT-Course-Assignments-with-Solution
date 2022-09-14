// 3. Write a C++ program to add two complex numbers using operator overloaded by a
// friend function.
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
        cout << real << " + " << img << " i" << endl;
    }
    friend Complex operator+(Complex, Complex);
};

Complex operator+(Complex x, Complex y)
{
    Complex temp;
    temp.real = x.real + y.real;
    temp.img = x.img + y.img;
    return temp;
}

int main()
{
    Complex c1, c2, c3;
    c1.setData(5, 4);
    c2.setData(6, 7);
    c1.showData();
    c2.showData();
    c3 = c1 + c2; // operator+(c1,c2);
    c3.showData();
    return 0;
}
// 2. Write a C++ program to overload unary operators that is increment and decrement.
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
    Complex operator++() // Pre Increment
    {
        Complex temp;
        temp.real = ++real;
        temp.img = ++img;
        return temp;
    }
    Complex operator++(int) // Post Increment, Just Pass Int for Deference ++(pre) and ++(post)
    {
        Complex temp;
        temp.real = real++;
        temp.img = img++;
        return temp;
    }
};
int main()
{
    Complex c1, c2, c3, c4;
    c1.setData(5, 4);
    c2.setData(6, 7);
    c1.showData();
    c2.showData();
    c4 = c2++; // Unary operator // c2.operator++(int); 
    c3 = ++c2; // Unary operator  // c2.operator++();
    c3.showData();
    c4.showData();
    return 0;
}
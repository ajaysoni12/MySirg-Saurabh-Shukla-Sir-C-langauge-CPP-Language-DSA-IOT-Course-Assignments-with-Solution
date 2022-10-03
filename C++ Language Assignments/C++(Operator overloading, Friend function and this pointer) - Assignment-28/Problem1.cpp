#include <iostream>
using namespace std;
class Complex
{
private:
    int real, img;

public:
    Complex(int x, int y)
    {
        real = x;
        img = y;
    }
    Complex() {}
    friend ostream &operator<<(ostream &output, Complex c);
    friend istream &operator>>(istream &input, Complex c);
};
ostream &operator<<(ostream &output, Complex c)
{
    output << "Real = " << c.real << " Imag = " << c.img << endl;
    return output;
}
istream &operator>>(istream &input, Complex c)
{
    input >> c.real >> c.img;
    return input; 
}
int main()
{
    Complex c1(2, 3), c2(4, 4);
    cout << c1 << c2;
    return 0;
}
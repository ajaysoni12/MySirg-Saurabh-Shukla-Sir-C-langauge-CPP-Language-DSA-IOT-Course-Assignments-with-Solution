#include <iostream>
using namespace std;
class Complex
{
private:
    int real, img;

public:
    Complex() {}
    Complex(int x, int y)
    {
        real = x;
        img = y;
    }
    void display() { cout << "Real = " << real << " Imag = " << img << endl; }
    Complex operator=(Complex c)
    {
        // if we crete dma memory then first free this memory
        // but first check both the object are not equal
        // third point is c1=c2=c3
        // here we don't need to check this all condition because we don't cretae dma memory
        this->real = c.real;
        this->img = c.img;
        return *this;
    }
};
int main()
{
    Complex c1(5, 4), c2(5, 3);
    c1 = c2;
    c1.display();
    return 0;
}
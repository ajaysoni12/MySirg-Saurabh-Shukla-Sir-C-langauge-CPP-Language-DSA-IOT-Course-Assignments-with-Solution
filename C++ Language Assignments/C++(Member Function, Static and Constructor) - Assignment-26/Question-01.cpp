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
        cout << "Real = " << real << " img = " << img << endl;
    }
    Complex add(Complex C)
    {
        Complex temp;
        temp.real = real + C.real;
        temp.img = img + C.img;
        return temp;
    }
};
int main()
{
    Complex c1, c2, c3;
    c1.setData(1, 2);
    c2.setData(3, 4);
    c1.showData();
    c2.showData();
    c3 = c1.add(c2);
    c3.showData();
    return 0;
}
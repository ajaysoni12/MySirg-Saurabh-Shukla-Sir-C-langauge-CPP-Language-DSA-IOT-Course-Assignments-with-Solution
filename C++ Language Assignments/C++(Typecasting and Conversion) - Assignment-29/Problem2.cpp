#include <iostream>
using namespace std;
class Complex
{
    int real, img;

public:
    void setData(int x, int y)
    {
        real = x;
        img = y;
    }
    operator long()
    {
        return real + img;
    }
    explicit operator int()
    {
        return real + img; // you can also return img
    }
    void display()
    {
        cout << "Img: " << img << " and Real: " << real << endl;
    }
};
int main()
{
    Complex c1;
    c1.setData(5, 4);
    // int x;
    // x = c1;
    // cout << "Value is: " << x << endl;
    // c1.display();
    cout << c1 << endl;
    return 0;
}
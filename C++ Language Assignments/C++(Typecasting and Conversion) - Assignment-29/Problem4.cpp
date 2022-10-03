#include <iostream>
using namespace std;
class Item
{
    int a, b;

public:
    Item() {}
    Item(int x, int y)
    {
        a = x;
        b = y;
    }

    void display() { cout << "a = " << a << " b = " << b << endl; }
};
class Product
{
    int x, y;

public:
    void setData(int a, int b)
    {
        x = a;
        y = b;
    }
    int getX() { return x; }
    int getY() { return y; }
    operator Item()
    {
        Item i(4, 3);
        return i;
    }
    void display() { cout << "x = " << x << " y = " << y << endl; }
};

int main()
{
    Item i1;
    Product p1;
    i1 = p1;
    i1.display();
    return 0;
}
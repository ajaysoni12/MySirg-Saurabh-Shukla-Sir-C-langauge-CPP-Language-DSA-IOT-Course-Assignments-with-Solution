#include <iostream>
using namespace std;
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
    void display() { cout << "x = " << x << " y = " << y << endl; }
};
class Item
{
    int a, b;

public:
    Item() {}
    Item(Product p)
    {
        a = p.getX();
        b = p.getY();
    }
    void display() { cout << "a = " << a << " b = " << b << endl; }
};
int main()
{
    Item i1;
    Product p1;
    p1.setData(3, 4);
    i1 = p1;
    p1.display(); 
    i1.display();
    return 0;
}
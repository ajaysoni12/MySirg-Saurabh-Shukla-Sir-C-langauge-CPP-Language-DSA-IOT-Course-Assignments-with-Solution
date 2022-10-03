#include <iostream>
using namespace std;
class Invent1
{
private:
    int x, y;

public:
    Invent1() {}
    Invent1(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    operator float()
    {
        return x + y;
    }
    int getX() { return x; }
    int getY() { return y; }
    void display() { cout << "x = " << x << " y = " << y << endl; }
};
class Invent2
{
private:
    int a, b;

public:
    Invent2() {}
    Invent2(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    Invent2(Invent1 i1)
    {
        a = i1.getX();
        b = i1.getY();
    }
    void display()
    {
        cout << "a = " << a << " b = " << b << endl;
    }
};
int main()
{
    Invent1 i1(3, 4);
    Invent1 i2;
    float f;
    f = i1;  // invent1 to float
    i2 = i1; // invent1 to invent2
    cout << "Float f = " << f << endl;
    i2.display();
    return 0;
}
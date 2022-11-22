#include <iostream>
using namespace std;
class shape
{
protected:
    double l1, l2;

public:
    void setData(int x, int y)
    {
        l1 = x;
        l2 = y;
    }
    virtual void displayArea() = 0;
};
class Triangle : public shape
{
public:
    void displayArea() { cout << "\nArea of triangle is: " << 0.5 * l1 * l2; }
};
class Rectangle : public shape
{
public:
    void displayArea() { cout << "\nArea of Rectangle is: " << l1 * l2; }
};
int main()
{
    Triangle t;
    Rectangle r;
    t.setData(1, 2);
    r.setData(1, 2);
    t.displayArea();
    r.displayArea();
    return 0;
}
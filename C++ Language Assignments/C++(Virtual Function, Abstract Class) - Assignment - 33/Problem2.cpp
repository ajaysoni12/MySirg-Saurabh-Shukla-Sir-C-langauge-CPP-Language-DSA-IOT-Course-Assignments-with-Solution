#include <iostream>
using namespace std;
class shape
{
protected:
    double x, y;

public:
    void setData(int x, int y = 0)
    {
        this->x = x;
        this->y = y;
    }
    virtual void displayArea() = 0;
};
class Triangle : public shape
{
public:
    void displayArea()
    {
        cout << "\nTriangle area is: " << x * y / 2.0;
    }
};
class Rectangle : public shape
{
public:
    void displayArea()
    {
        cout << "\nRectangle area is: " << x * y;
    }
};
class Circle : public shape
{
public:
    void displayArea()
    {
        cout << "\nCircle area is: " << 3.14 * x * x;
    }
};
int main()
{
    Triangle t;
    Rectangle r;
    Circle c;

    t.setData(13, 10);
    r.setData(14, 18);
    c.setData(5);

    t.displayArea();
    r.displayArea();
    c.displayArea();
    return 0;
}
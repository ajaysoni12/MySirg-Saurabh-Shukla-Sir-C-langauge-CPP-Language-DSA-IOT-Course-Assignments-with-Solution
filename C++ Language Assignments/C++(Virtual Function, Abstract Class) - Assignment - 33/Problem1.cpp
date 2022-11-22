#include <iostream>
using namespace std;
class shape
{
protected:
    double x, y;

public:
    void setData(int x, int y)
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
int main()
{
    Triangle t;
    Rectangle r;

    t.setData(13, 10);
    r.setData(14, 18);

    t.displayArea();
    r.displayArea();
    return 0;
}
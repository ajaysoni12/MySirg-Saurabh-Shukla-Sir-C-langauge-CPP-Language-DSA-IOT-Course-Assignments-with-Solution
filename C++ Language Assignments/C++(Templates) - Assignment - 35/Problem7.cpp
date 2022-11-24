#include <iostream>
using namespace std;
class Shape
{
private:
    string shape;

public:
    Shape() {}
    Shape(string s) { shape = s; }
    void setShape(string s) { shape = s; }
    string getShape() { return shape; }
};

template <typename T>
class Circle : public Shape
{
    T x, y, radius;

public:
    Circle(T centerX, T centerY, T radius, string s) : Shape(s)
    {
        x = centerX;
        y = centerY;
        this->radius = radius;
    }
    Circle(T centerX, T centerY, T radius) : Shape()
    {
        x = centerX;
        y = centerY;
        this->radius = radius;
    }
    Circle(T r) : Shape() { radius = r; }
    Circle() {}
    T area()
    {
        return 3.14 * radius * radius;
    }
};

int main()
{
    Circle<float> c(0.0, 0.0, 10.0, "Circle");
    cout << "\nArea of circle is: " << c.area();
    cout << "\nShape is:  " << c.getShape();
    return 0;
}
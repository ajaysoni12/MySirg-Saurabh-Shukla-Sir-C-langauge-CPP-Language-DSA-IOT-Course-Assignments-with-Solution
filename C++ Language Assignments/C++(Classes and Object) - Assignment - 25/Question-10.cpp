#include <iostream>
using namespace std;
class Area
{
public:
    double areaOfCircle(float r)
    {
        return 3.14 * r * r;
    }
    int areaOfRectangle(int b, int h)
    {
        return b * h;
    }
    int areaOfSquare(int a)
    {
        return a * a;
    }
};
int main()
{
    Area a;
    cout << "Area of circle for radius 5 is: " << a.areaOfCircle(5) << endl;
    cout << "Area of rectangle having 5 breath and 5 height is: " << a.areaOfRectangle(5, 5) << endl;
    cout << "Area of square having 5 sides is: " << a.areaOfSquare(5) << endl;
    return 0;
}
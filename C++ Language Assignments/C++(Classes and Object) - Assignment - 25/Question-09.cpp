#include <iostream>
using namespace std;
class Circle
{
public:
    double findCircleArea(float r)
    {
        return 3.14 * r * r;
    }
};
int main()
{
    Circle c;
    float radius;
    cout << "Enter a radius: ";
    cin >> radius;
    cout << "Rectangle of Area is: " <<c.findCircleArea(radius);
    return 0;
}
#include <iostream>
using namespace std;
class Rectangle
{
public:
    int findRectangleArea(int b, int h)
    {
        return b * h;
    }
};
int main()
{
    Rectangle r;
    cout << "Rectangle of Area is: " << r.findRectangleArea(5, 4);
    return 0;
}
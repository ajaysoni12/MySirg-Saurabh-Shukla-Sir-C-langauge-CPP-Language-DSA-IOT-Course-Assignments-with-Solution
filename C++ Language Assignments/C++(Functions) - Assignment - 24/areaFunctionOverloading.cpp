#include <iostream>
using namespace std;
float area(int r)
{
    return 3.14 * r * r;
}
float area(int w, int h)
{
    return w * h;
}
float area(double b, double h)
{
    return ((b * h) / 2.0);
}
int main()
{
    cout << "Area of Circle: " << area(5) << ", having " << 5 << " radius" << endl;
    cout << "Area of Rectangle " << area(3, 4) << ", having " << 3 << " width and " << 4 << " height" << endl;
    cout << "Area of Trinalge " << area(3.5, 4.3)<< ", having " << 3 << " breadth and " << 4 << " height" << endl;; 
    return 0;
}
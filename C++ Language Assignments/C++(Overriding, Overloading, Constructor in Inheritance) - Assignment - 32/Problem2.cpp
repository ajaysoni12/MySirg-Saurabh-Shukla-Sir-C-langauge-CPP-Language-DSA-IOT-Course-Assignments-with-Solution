#include <iostream>
using namespace std;
class Rectangle
{
private:
    double x, y;
public:
    double area(int x, int y)
    {
        return x * y;
    }
    double area(double x, double y) // both for float and double
    {
        return x * y;
    }
    double area(int x, double y)
    {
        return x * y;
    }
    double area(double x, int y)
    {
        return x * y;
    }
};
int main()
{
    Rectangle r;
    cout<<r.area(5,4)<<endl;
    cout<<r.area(5,4.4)<<endl;
    cout<<r.area(5.3,4)<<endl;
    return 0;
}
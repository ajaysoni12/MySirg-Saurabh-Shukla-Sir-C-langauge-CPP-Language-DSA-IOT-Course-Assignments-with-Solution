#include <iostream>
using namespace std;
class Box
{
private:
    int length, breath, height;

public:
    Box(int x, int y, int z)
    {
        length = x;
        breath = y;
        height = z;
    }
    int volOfBox()
    {
        return length * breath * height;
    }
};
int main()
{
    Box b(1, 2, 3);
    cout << "Volume of Box is: " << b.volOfBox() << endl;

    return 0;
}
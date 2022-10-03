#include <iostream>
using namespace std;
class Coordinate
{
private:
    int x, y, z;

public:
    Coordinate() {}
    Coordinate(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    void display() { cout << "x = " << x << " y = " << y << " z = " << z << endl; }
    Coordinate operator,(Coordinate &c)
    {
        Coordinate temp;
        temp.x = c.x;
        temp.y = c.y;
        temp.z = c.z;
        return temp;
    }
};
int main()
{
    Coordinate c1(4, 3, 5), c2(3, 5, 3), c3, c4(5, 3, 3);
    c3 = (c1, c2);
    c3.display();
    c3 = (c1, c2, c4);
    c3.display();
    return 0;
}
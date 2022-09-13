#include <iostream>
using namespace std;
class Cube
{
private:
    int a;

public:
    Cube(int x)
    {
        a = x;
    }
    int showCubeVolume()
    {
        return a * a * a;
    }
};
int main()
{
    Cube c1(5);
    cout << "Volmue of cube is " << c1.showCubeVolume();
    return 0;
}
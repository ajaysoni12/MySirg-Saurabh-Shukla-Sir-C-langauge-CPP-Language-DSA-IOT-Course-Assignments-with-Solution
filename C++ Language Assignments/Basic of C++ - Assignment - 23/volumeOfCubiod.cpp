/*
5. Write a C++ program to calculate the volume of a cuboid.
*/
#include <iostream>
using namespace std;
int main()
{
    int length = 3, breadth = 4, height = 5;
    int volumeOfCubiod = length * breadth * height;
    cout << "Volume of Cubiod is: " << volumeOfCubiod << "m3, having length: " << length << " breath: " << breadth << " height: " << height;
    return 0;
}
#include <iostream>
using namespace std;
class Distance
{
private:
    int feet, inches;

public:
    Distance() {}
    Distance(int f, int i)
    {
        feet = f;
        inches = i;
    }
    void operator()(int a, int b, int c)
    {
        feet = a + c + 5;
        inches = a + b + 15;
    }
    void display() { cout << "Feet = " << feet << " Inches = " << inches << endl; }
};
int main()
{
    Distance d1(4,3), d2, d3; 
    d1(2,3,4); 
    d1.display(); 
    return 0;
}
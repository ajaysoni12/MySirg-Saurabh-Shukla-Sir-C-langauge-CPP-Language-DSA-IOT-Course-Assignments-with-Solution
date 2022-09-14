/*
5. Consider following class Numbers ;
class Numbers
{
    int x, y, z;

public:
    // methods
};
Overload the operator unary minus(-) to negate the numbers.
*/
#include <iostream>
using namespace std;
class Number
{
private:
    int x, y, z;

public:
    void setData(int a, int b, int c)
    {
        x = a;
        y = b;
        z = c;
    }
    void showData()
    {
        cout << "x = " << x << " y = " << y << " z = " << z << endl;
    }
    Number operator-()
    {
        Number temp;
        temp.x = -x;
        temp.y = -y;
        temp.z = -z;
        return temp;
    }
};
int main()
{
    Number n1, n2, n3;
    n1.setData(5, 4, 2);
    n2 = -n1; // n1.operator-();
    n1.showData();
    n2.showData();
    return 0;
}

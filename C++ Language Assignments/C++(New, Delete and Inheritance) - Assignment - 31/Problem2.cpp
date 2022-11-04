#include <iostream>
using namespace std;
class Base
{
private:
    float x, y;

public:
    void acceptData()
    {
        cout << "Enter First Number: ";
        cin >> x;
        cout << "Enter Second Number: ";
        cin >> y;
    }

protected:
    float getX() { return x; }
    float getY() { return y; }
};
class Derived : public Base // single inheritance
{
private:
    float sum;

public:
    void doSum()
    {
        sum = getX() + getY();
    }
    float getSum() { return sum; }
};
int main()
{
    Derived obj;
    obj.acceptData();
    obj.doSum();
    cout << obj.getSum() << endl;
}
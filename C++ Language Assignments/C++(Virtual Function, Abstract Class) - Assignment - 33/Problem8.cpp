#include <iostream>
using namespace std;
class Proof
{
protected:
    int x, y;

public:
    Proof(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};
class Compute : public Proof
{
public:
    Compute(int x, int y) : Proof(x, y) {}
    void rightAngleTriangle()
    {
    }
};
int main()
{
    Compute c(1, 2);
    c.rightAngleTriangle();
    return 0;
}
#include <iostream>
using namespace std;
class volume
{
protected:
    double x, y;

public:
    void setData(int x, int y = 0)
    {
        this->x = x;
        this->y = y;
    }
    virtual void displayVolume() = 0;
};
class cube : public volume
{
public:
    void displayVolume() { cout << "\nCube volume is: " << x * x * x; }
};
class sphere : public volume
{
public:
    void displayVolume() { cout << "\nSphere volume is: " << (4 * 3.14 * x * x) / 3; }
};
int main()
{
    cube c;
    c.setData(2);
    sphere s;
    s.setData(5);
    c.displayVolume();
    s.displayVolume();
    return 0;
}
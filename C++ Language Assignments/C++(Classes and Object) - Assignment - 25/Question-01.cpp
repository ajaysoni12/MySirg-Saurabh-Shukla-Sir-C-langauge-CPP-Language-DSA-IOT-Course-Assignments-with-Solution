#include <iostream>
using namespace std;
class Complext
{
private:
    int real, img;

public:
    void setValue(int x, int y)
    {
        real = x;
        img = y;
    }
    void showValue()
    {
        cout << "Complext number: " << real << "+" << img << "i";
    }
};
int main()
{
    Complext c;
    c.setValue(5, 4);
    c.showValue();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
class FLOAT
{
private:
    float value;

public:
    FLOAT() {}
    FLOAT(int value) { this->value = value; }
    FLOAT operator+(FLOAT x)
    {
        FLOAT temp;
        temp.value = value + x.value;
        return temp;
        
    }
    FLOAT operator-(FLOAT x)
    {
        FLOAT temp;
        temp.value = value - x.value;
        return temp;
    }
    FLOAT operator*(FLOAT x)
    {
        FLOAT temp;
        temp.value = value * x.value;
        return temp;
    }
    FLOAT operator/(FLOAT x)
    {
        FLOAT temp;
        temp.value = value / x.value;
        return temp;
    }
    void display()
    {
        cout << value << endl;
    }
};
int main()
{
    FLOAT f1(5), f2(4), f3;
    f1 = 6;
    f3 = f1 / f2;
    f3.display();
    return 0;
}
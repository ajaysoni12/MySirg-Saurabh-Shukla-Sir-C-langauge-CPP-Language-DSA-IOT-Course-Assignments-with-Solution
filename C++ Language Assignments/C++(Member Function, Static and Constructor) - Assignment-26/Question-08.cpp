#include <iostream>
using namespace std;
class Bank
{
private:
    int principal, roi, year;

public:
    Bank(int x, int y, int z)
    {
        principal = x;
        roi = y;
        year = z;
    }
    int simpleIntrest()
    {
        return (principal * roi * year) / 100;
    }
};
int main()
{
    Bank b(1000, 2, 3);
    cout << "simple intrest is: $" << b.simpleIntrest() << endl;
    return 0;
}
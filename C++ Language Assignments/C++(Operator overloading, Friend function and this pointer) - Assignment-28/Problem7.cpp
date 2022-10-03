#include <iostream>
using namespace std;
class Integer
{
private:
    int i;

public:
    Integer(int i) : i(i) {}
    int operator!()
    {
        return -i; // return !i;
    }
};
int main()
{
    Integer x(5); // x = 5(PC constructor called )
    cout << !x << endl;
    return 0;
}
#include <iostream>
using namespace std;
class StaticCount
{
private:
    static int count;

public:
    static int fun()
    {
        count++;
    }
    static int getCount()
    {
        return count;
    }
};
int StaticCount::count = 0;
int main()
{
    StaticCount::fun();
    StaticCount::fun();
    StaticCount::fun();
    StaticCount::fun();
    cout << "Calling times: " << StaticCount::getCount();
    return 0;
}
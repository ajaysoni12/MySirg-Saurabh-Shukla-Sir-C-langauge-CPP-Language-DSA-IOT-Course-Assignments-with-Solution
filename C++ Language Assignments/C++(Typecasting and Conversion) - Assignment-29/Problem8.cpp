#include <iostream>
using namespace std;
class Rupee
{
private:
    int rupee;

public:
    Rupee() { rupee = 0; }
    Rupee(int r) { rupee = r; }
    operator int()
    {
        return rupee;
    }
};
int main()
{
    Rupee r = 10;
    int x = r;
    cout << x;
    return 0;
}
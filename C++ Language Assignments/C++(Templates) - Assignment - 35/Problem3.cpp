#include <iostream>
using namespace std;
template <class X, class Y, class Z>
Y largestNo(X x, Y y, Z z)
{
    return x > y ? x > z ? x : z : y;
}
int main()
{
    cout << largestNo(53, 443.2,9);
    return 0;
}
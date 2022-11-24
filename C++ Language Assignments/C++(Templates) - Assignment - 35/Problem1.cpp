#include <iostream>
using namespace std;
template <typename X, typename Y>
Y add(X x, Y y)
{
    return x + y;
}
int main()
{
    cout << add<int, float>(5, 3.2);
    return 0;
}
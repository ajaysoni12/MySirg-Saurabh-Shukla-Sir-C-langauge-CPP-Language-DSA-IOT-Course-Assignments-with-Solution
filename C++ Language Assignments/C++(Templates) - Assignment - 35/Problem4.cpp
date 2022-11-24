#include <iostream>
using namespace std;
template <typename X, typename Y>
void swap(X &x, Y &y)
{
    Y temp = x;
    x = y;
    y = x;
}
int main()
{
    float x = 5.2, y = 3.33;
    cout << "\nBefore swapping: ";
    cout << x << " " << y;
    swap(x, y);
    cout << "\nAfter swapping: ";
    cout << x << " " << y;
    return 0;
}
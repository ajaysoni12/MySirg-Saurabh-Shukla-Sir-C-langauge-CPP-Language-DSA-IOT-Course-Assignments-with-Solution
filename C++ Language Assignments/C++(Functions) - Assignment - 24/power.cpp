#include <iostream>
using namespace std;
int power(int x, int y)
{
    int ans = 1;
    for (int i = 1; i <= y; i++)
        ans *= x;

    return ans;
}
int main()
{
    cout << power(5, 5);
    return 0;
}
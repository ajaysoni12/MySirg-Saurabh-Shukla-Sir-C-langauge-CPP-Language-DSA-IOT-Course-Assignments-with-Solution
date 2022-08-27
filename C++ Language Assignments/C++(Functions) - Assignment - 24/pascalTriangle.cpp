#include <iostream>
using namespace std;

int fact(int n)
{
    int ans = 1;
    for (int i = 2; i <= n; i++)
        ans = ans * i;
    return ans;
}

int nCr(int n, int r)
{
    return (fact(n) / fact(n - r) / fact(r));
}

void pascalTriangle(int lines)
{
    for (int i = 1; i <= lines; i++)
    {
        int k = 1, col = 0;
        for (int j = 1; j < lines * 2; j++)
        {
            if (j >= (lines + 1) - i && j <= (lines - 1) + i && k)
            {
                cout << nCr(i - 1, col) << " ";
                col++;
                k = 0;
            }
            else
            {
                cout << "  ";
                k = 1;
            }
        }
        cout << endl;
    }
}
int main()
{
    pascalTriangle(5);
    return 0;
}
#include <iostream>
using namespace std;
class Factorial
{
private:
    int n, fact;

public:
    Factorial(int x)
    {
        n = x;
        fact = 1;
    }
    Factorial(Factorial &f)
    {
        n = f.n;
        fact = 1;
    }
    void calculate()
    {
        for (int i = 1; i <= n; i++)
            fact *= i;
    }
    void show()
    {
        cout << "\nFactorial is: " << fact;
    }
};
int main()
{
    Factorial f1(6);
    f1.calculate();
    f1.show();

    Factorial f2(f1);
    f2.calculate();
    f2.show();
    return 0;
}
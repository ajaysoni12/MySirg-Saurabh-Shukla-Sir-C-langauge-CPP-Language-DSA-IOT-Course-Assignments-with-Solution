#include <iostream>
using namespace std;
class LargestNumber
{
public:
    int largeNumberAmongThree(int x, int y, int z)
    {
        return x > y && x > z ? x : y > z ? y
                                          : z;
    }
};
int main()
{
    LargestNumber l;
    int num1, num2, num3;
    cout << "Enter a three number: ";
    cin >> num1 >> num2 >> num3;
    int largestNumber = l.largeNumberAmongThree(num1, num2, num3);
    cout << "Largest Number is: " << largestNumber << endl;
    return 0;
}
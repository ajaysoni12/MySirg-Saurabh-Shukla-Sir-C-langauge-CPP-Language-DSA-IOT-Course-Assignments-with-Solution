#include <iostream>
using namespace std;
class Square
{
public:
    int findSquare(int num)
    {
        static int countFunctionCalling;
        countFunctionCalling++; // oops we no need to initialize 0 coz static variable by default ini.. 0
        cout << countFunctionCalling << " Time Calling this function--!" << endl;
        return num * num;
    }
};
int main()
{
    Square s;
    s.findSquare(6);
    s.findSquare(5);
    s.findSquare(6);
    s.findSquare(5);
    s.findSquare(6);
    s.findSquare(5);
    s.findSquare(6);
    s.findSquare(5);
    return 0;
}
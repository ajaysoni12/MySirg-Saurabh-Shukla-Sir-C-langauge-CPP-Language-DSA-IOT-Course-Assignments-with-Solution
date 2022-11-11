#include <iostream>
using namespace std;
class Addition
{
private:
    double sum;

public:
    void add(int x, int y) { sum = x + y; }
    void add(double x, double y) { sum = x + y; }
    void add(int x, int y, int z) { sum = x + y + z; }
    void add(double x, double y, double z) { sum = x + y + z; }
    void showSum() { cout << "\nSum is: " << sum; }
};
int main()
{

    return 0;
}
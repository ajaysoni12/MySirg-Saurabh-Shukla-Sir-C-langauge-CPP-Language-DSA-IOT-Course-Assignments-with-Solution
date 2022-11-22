#include <iostream>
using namespace std;
class A
{
private:
    int x;

public:
    A(int x) { this->x = x; }
    void swap(A *num)
    {
        int temp = x;
        x = num->x;
        num->x = temp;
    }
    void showData() { cout << "X = " << x << endl; }
};
int main()
{
    A obj1(5), obj2(3);
    obj1.showData();
    obj2.showData();
    obj1.swap(&obj2); // you can use also reference
    obj1.showData();
    obj2.showData();
    return 0;
}
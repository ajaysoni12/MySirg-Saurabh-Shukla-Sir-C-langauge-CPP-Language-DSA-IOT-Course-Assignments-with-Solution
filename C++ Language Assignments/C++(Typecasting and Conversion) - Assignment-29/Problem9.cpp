#include <iostream>
using namespace std;
class Dollar
{
private:
    int dollar;

public:
    Dollar() { dollar = 0; }
    Dollar(int r) { dollar = r; }
    void display() { cout << "Dollar = " << dollar << endl; }
};
int main()
{
    int x = 50;
    Dollar d;
    d = x;
    d.display();
    return 0;
}
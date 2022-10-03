#include <iostream>
using namespace std;
class Dollar;
class Rupee
{
private:
    float rupee;

public:
    Rupee() { rupee = 0; }
    Rupee(float r) { rupee = r; }
    float getRupee() { return rupee; }
    void display() { cout << "Rupee = " << rupee << endl; }
};
class Dollar
{
private:
    float dollar;

public:
    Dollar() { dollar = 0; }
    Dollar(Rupee r) { dollar = r.getRupee() / 82.0; }
    float getDollar() { return dollar; }
    operator Rupee()
    {
        return dollar * 82;
    }
    void display() { cout << "Dollar = " << dollar << endl; }
};
int main()
{
    Rupee r = 23;
    Dollar d = r; // Rupee to Dollar conversion
    d.display();
    r.display();
    r = d; // Dollar to Rupee Conversion
    d.display();
    r.display();
    return 0;
}
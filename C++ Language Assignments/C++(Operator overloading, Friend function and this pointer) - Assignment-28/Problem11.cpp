#include <iostream>
using namespace std;
class Marks
{
private:
    int marks;

public:
    Marks() {}
    Marks(int x) { marks = x; }
    void printMarks() { cout << "Marks: " << marks << endl; }
    Marks *operator->()
    {
        return this;
    }
};

int main()
{
    Marks m1(55), m2;
    m1->printMarks(); 
    return 0;
}
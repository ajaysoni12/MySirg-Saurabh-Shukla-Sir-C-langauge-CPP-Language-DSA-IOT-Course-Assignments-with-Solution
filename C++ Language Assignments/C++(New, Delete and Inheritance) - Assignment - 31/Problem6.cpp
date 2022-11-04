#include <bits/stdc++.h>
using namespace std;
class B;
class A
{
protected:
    int x;

public:
    void setX(int x) { this->x = x; }
    void showX() { cout << "X = " << x << endl; }
    friend void swap(A &, B &);
};
class B
{
protected:
    int y;

public:
    void setY(int y) { this->y = y; }
    void showY() { cout << "Y = " << y << endl; }
    friend void swap(A &, B &);
};
void swap(A &a, B &b)
{
    int temp = a.x;
    a.x = b.y;
    b.y = temp;
}
int main()
{
    A a;
    B b;
    a.setX(5);
    b.setY(4);
    cout << "\nBefore swapping: ";
    a.showX();
    b.showY();
    swap(a, b);
    cout << "\nAfter swapping: ";
    a.showX();
    b.showY();
    return 0;
}
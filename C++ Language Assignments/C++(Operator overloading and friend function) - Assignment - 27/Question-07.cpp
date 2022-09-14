/* 7. Define a C++ class fraction
class fraction
{
long numerator;
long denominator;
Public:
fraction (long n=0, long d=0);
}
Overload the following operators as member or friend:
a) Unary ++ (pre and post both)
b) Overload as friend functions: operators << and >>. */
#include <iostream>
using namespace std;
class Fraction
{
private:
    long numerator, denominator;

public:
    void setFractionValue(long x = 0, long y = 0)
    {
        numerator = x;
        denominator = y;
    }
    void showFractionValue()
    {
        cout << numerator << "/" << denominator << endl;
    }
    friend Fraction operator++(Fraction &);
    friend Fraction operator++(Fraction &, int);
};
Fraction operator++(Fraction &f)
{
    ++f.numerator;
    ++f.denominator;
    return f;
}
Fraction operator++(Fraction &f, int)
{
    Fraction temp;
    temp.numerator = f.numerator;
    temp.denominator = f.denominator;
    f.numerator++;
    f.denominator++;
    return temp;
}
int main()
{
    Fraction f1, f2, f3, f4;
    int x, y;
    f1.setFractionValue();
    f2.setFractionValue();
    f1.showFractionValue();
    f2.showFractionValue();
    cout << endl;
    cout << "Enter First Fraction Value: \n";
    cout << "Numerator: ";
    cin >> x;
    cout << "Denomirator: ";
    cin >> y;
    f1.setFractionValue(x, y);
    cout << endl;
    cout << "f1++: ";
    f1++;
    f1.showFractionValue();
    cout << "++f1: ";
    ++f1;
    f1.showFractionValue();
    cout << endl;
    cout << "Enter Second Fraction Value: \n";
    cout << "Numerator: ";
    cin >> x;
    cout << "Denomirator: ";
    cin >> y;
    f1.setFractionValue(x, y);
    cout << endl;
    cout << "f2 = ++f1";
    f2 = ++f1;
    cout << "f1 : ";
    f1.showFractionValue();
    cout << "f2  :  ";
    f2.showFractionValue();
    cout << "f2 = f1++";
    f2 = f1++;
    cout << "f1 :  ";
    f1.showFractionValue();
    cout << "f2 : ";
    f2.showFractionValue();
    cout << endl;

    return 0;
}
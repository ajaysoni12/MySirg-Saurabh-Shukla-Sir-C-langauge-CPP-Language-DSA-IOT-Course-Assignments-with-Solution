#include <iostream>
using namespace std;
class Time
{
private:
    int hrs, minute, second;

public:
    Time() {}
    Time(int d)
    {
        hrs = d / 3600;
        d = d % 3600;
        minute = d / 60;
        second = d % 60;
    }
    void display() { cout << "Hours = " << hrs << ", Minute =  " << minute << ", second = " << second << endl; }
};
int main()
{
    int duration;
    cout << "Enter duration in seconds: ";
    cin >> duration;
    Time t1 = duration;
    t1.display();
    return 0;
}
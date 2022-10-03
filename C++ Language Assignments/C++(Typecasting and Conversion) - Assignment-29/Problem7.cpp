#include <iostream>
using namespace std;
class Time
{
private:
    int hrs, minute;

public:
    Time() {}
    Time(int hrs, int minute)
    {
        this->hrs = hrs;
        this->minute = minute;
    }
    int getHours() { return hrs; }
    int getMinute() { return minute; }

    void display() { cout << "Hours - " << hrs << " Minute - " << minute << endl; }
};
class Minute
{
private:
    int minute;

public:
    Minute() { minute = 0; }
    Minute(Time t)
    {
        cout << "Constructro() called " << endl;
        minute = t.getMinute();
    }
    void display() { cout << " Minute - " << minute << endl; }
};

int main()
{
    Time t1(2, 30);
    t1.display();
    Minute m1;
    m1.display();
    m1 = t1; // Fetch minute from time
    t1.display();
    m1.display();
    return 0;
}
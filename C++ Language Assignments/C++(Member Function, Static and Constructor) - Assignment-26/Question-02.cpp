#include <iostream>
using namespace std;
class Time
{
private:
    int hour, minute, second;

public:
    void setTime(int x, int y, int z)
    {
        hour = x;
        minute = y;
        second = z;
    }
    void showTime()
    {
        cout << "Hour = " << hour << " Minute = " << minute << " Second = " << second << endl;
    }

    void normalize()
    {
    }

    Time add(Time t)
    {
        /*
        Time temp;
        temp.hour = hour + t.hour;
        temp.minute = minute + t.minute;
        temp.second = second + t.second;
        return temp;
        */
        Time temp;
        int totalTime = hour * 60 * 60 + minute * 60 + second + t.hour * 60 * 60 + t.minute * 60 + t.second;
        temp.hour = totalTime / (60 * 60);
        totalTime = totalTime % (60 * 60);
        temp.minute = totalTime / 60;
        totalTime = totalTime % 60;
        temp.second = totalTime;
        return temp;
    }
};
int main()
{
    Time t1, t2, t3;
    t1.setTime(3, 34, 23);
    t2.setTime(6, 32, 5);
    t1.showTime();
    t2.showTime();
    t3 = t1.add(t2);
    t3.showTime();
    return 0;
}

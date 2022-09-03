#include <iostream>
using namespace std;
class ReverseNumber
{
public:
    int_least8_t reverseNumber(int num)
    {
        int ans = 0, count = 0;
        while (num)
        {
            if (num % 10 == 0)
                count++;
            ans = ans * 10 + num % 10;
            num /= 10;
        }
        return ans;

        /*
        if we pass 200 then output get only 2
        here is solutions

        int ans = 0,count = 0;
        while (num)
        {
            if(num % 10 == 0)
                count++;
            ans = ans * 10 + num % 10;
            num /= 10;
        }
       // you can return it so we just print
        for(int i=1; i<=count; i++)
            cout<<"0";
        cout<<ans;
        */
    }
};
int main()
{
    ReverseNumber r;
    cout << "Reverse Number is: " << r.reverseNumber(20000);
    return 0;
}

#include <iostream>
using namespace std;
class Bill
{
private:
    int cust_id, consume_unit;
    char cust_name[20];

public:
    void get()
    {
        cout << "Enter customer id: ";
        cin >> cust_id;
        cout << "Enter Customer Name: ";
        fflush(stdin);
        gets(cust_name);
        cout << "Enter total consume unit: ";
        cin >> consume_unit;
    }
    int calculateBill()
    {
        int totalRupess = 0;
        if (consume_unit <= 100)
        {
            totalRupess = consume_unit * 1.20f;
        }
        else if (consume_unit <= 200)
        {
            totalRupess = (100 * 1.20) + (consume_unit - 100) * 2.0f;
        }
        else if (consume_unit > 200)
        {
            totalRupess = (100 * 1.20) + (100 * 2.0) + (consume_unit - 200) * 3.0f;
        }
        return totalRupess;
    }
};
int main()
{
    Bill b;
    b.get();
    cout << "Total Bill is: " << b.calculateBill();
    return 0;
}

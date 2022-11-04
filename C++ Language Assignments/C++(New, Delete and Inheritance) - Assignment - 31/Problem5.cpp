#include <bits/stdc++.h>
using namespace std;
class ItemDetails
{
protected:
    char itemName[20];
    int itemNo;
    double itemPrice;
};
class discountItem : public ItemDetails
{
public:
    float discountPercent;
    float discountPrice;
    void acceptDetails()
    {
        cout << "\nEnter item No. - ";
        cin >> itemNo;
        cout << "\nEnter Item Name: ";
        cin >> itemName;
        cout << "\nEnter Item Price: ";
        cin >> itemPrice;
        cout << "\nEnter discount Percent: ";
        cin >> discountPercent;
        cout << "\n-----------------------";
        discountPrice = itemPrice - ((itemPrice * discountPercent) / 100.0f);
    }
    float getItemPrice() { return itemPrice; }
    void displayBill()
    {
        cout << "\nItem Name: " << itemName;
        cout << "\nItem No. " << itemNo;
        cout << "\nItem Price: " << itemPrice;
        cout << "\nDiscount Percent: " << discountPercent;
        cout << "\nDiscount Price: " << discountPrice;
        cout << "\n-----------------";
    }
};
int main()
{
    int i, noOfItem;
    float totalDiscount = 0, totalPrice = 0;
    discountItem item[100];
    cout << "\nHow many item you want to purchase?";
    cin >> noOfItem;
    for (i = 0; i < noOfItem; i++)
        item[i].acceptDetails();

    for (i = 0; i < noOfItem; i++)
    {
        item[i].displayBill();
        totalDiscount += item[i].getItemPrice() - item[i].discountPrice;
        totalPrice += item[i].getItemPrice();
    }
    cout << "\n-----------------";
    cout << "\nTotal Price: " << totalPrice;
    cout << "\nTotal Discount: " << totalDiscount;
    cout << "\nFinal Price: " << totalPrice - totalDiscount;
    return 0;
}
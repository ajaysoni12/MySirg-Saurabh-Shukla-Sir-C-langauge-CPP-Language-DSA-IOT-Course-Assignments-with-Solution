#include <iostream>
using namespace std;
class Customer
{
protected:
    char custName[20];
    long mobileNo;
    void acceptData()
    {
        cout << "\n\nEnter Customer Name: ";
        cin >> custName;
        cout << "\nEnter mobile no. : ";
        cin >> mobileNo;
    }

public:
    void showCustomerDetails()
    {
        cout << "\n\nDetails of Customer: ";
        cout << "\n--------------------------------------";
        cout << "\nCustomer Name: " << custName;
        cout << "\nCustomer Mobile No. : " << mobileNo;
    }
};
class Dipositors : public Customer
{
protected:
    long accountNo, balance;

public:
    void acceptDipositorsData()
    {
        acceptData();
        cout << "\nEnter Customer Account No. : ";
        cin >> accountNo;
        cout << "\nEnter Customer balance: ";
        cin >> balance;
    }
    void showDipositorsData()
    {
        showCustomerDetails();
        cout << "\nA/c No. : " << accountNo;
        cout << "\nBalance: " << balance;
    }
};
class Borrowers : public Customer
{
protected:
    long loanNo, loanAmount;

public:
    void acceptBorrowersData()
    {
        acceptData();
        cout << "\nEnter Loan No. : ";
        cin >> loanNo;
        cout << "\nEnter Loan Amount: ";
        cin >> loanAmount;
    }
    void showBorrowersDetails()
    {
        showCustomerDetails();
        cout << "\nLoan No. : " << loanNo;
        cout << "\nLoan Amount: " << loanAmount;
    }
};
int main()
{
    Dipositors *d;
    Borrowers *b;
    int bCust, dCust; // you can use menu drivern program also for simplicity
    cout << "\nHow many depositers customer details you want to enter? ";
    cin >> bCust;
    cout << "\nHow many borrowers customer details you want to enter? ";
    cin >> dCust;

    d = new Dipositors[dCust];
    b = new Borrowers[bCust];

    // dipositors cust details
    for (int i = 0; i < dCust; i++)
        d->acceptDipositorsData();
    for (int i = 0; i < dCust; i++)
        d->showDipositorsData();

    // borrowers cust details
    for (int i = 0; i < bCust; i++)
        b->acceptBorrowersData();
    for(int i=0; i<bCust; i++)
        b->showBorrowersDetails(); 

    
    return 0;
}
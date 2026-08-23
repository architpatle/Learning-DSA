#include <iostream>
using namespace std;

class Payment
{

public:
    virtual void pay()
    {
        cout << "Processing payment." << endl;
    }
};

class CreditCard : public Payment
{
public:
    void pay()
    {
        cout << "Payment made using Credit Card." << endl;
    }
};

class UPI : public Payment
{

public:
    void pay()
    {
        cout << "Payment made using UPI." << endl;
    }
};

int main()
{
    CreditCard c;
    UPI u;

    Payment *p;

    p = &c;
    p->pay();

    p = &u;
    p->pay();

    return 0;
}
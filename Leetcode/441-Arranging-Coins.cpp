#include <iostream>
using namespace std;
int arrangeCoins(int n)
{
    int i = 1;

    while (i <= n)
    {
        n -= i;
        i++;
    }

    return --i;
}

int main()
{
    int n = 7;

    cout << "Complete Rows: " << arrangeCoins(n);

    return 0;
}
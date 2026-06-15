#include <iostream>
using namespace std;

// To calculate x^n using Binary exponentiation
double binaryExponentiation(double x, int n)
{
    int ans = 1;

    if (n < 0)
    {
        x = 1 / x;
        n = -n;
    }

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ans *= x;
        }
        x *= x;
        n /= 2;
    }

    return ans;
}

int main()
{
    cout << binaryExponentiation(2, 10);

    return 0;
}
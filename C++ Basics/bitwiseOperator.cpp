#include <iostream>
using namespace std;

bool isPowerOfTwo(int num)
{
    bool isPowerOfTwo = true;

    while (num > 1)
    {
        int rem = num % 2;
        num /= 2;

        if (rem == 1)
        {
            isPowerOfTwo = false;
            break;
        }
    }

    return isPowerOfTwo;
}

int sumOfDigits(int num)
{
    int sum = 0;

    while (num > 0)
    {
        int rem = num % 10;
        num /= 10;

        sum += rem;
    }

    return sum;
}

int reverseInteger(int num)
{
    int ans = 0;

    while (num > 0)
    {
        int rem = num % 10;
        num /= 10;

        ans = ans * 10 + rem;
    }

    return ans;
}

int main()
{
    // int val = 8 << 1;
    // cout << val;

    // cout << isPowerOfTwo(1024);

    // cout << sumOfDigits(601292);

    cout << reverseInteger(123456789);

    return 0;
}
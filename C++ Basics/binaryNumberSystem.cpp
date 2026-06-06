#include <iostream>
using namespace std;

int decimalToBinary(int n)
{
    int ans = 0, pow = 1;

    while (n > 0)
    {
        int rem = n % 2;
        n /= 2;

        ans += (rem * pow);
        pow *= 10;
    }

    return ans;
}

int binaryToDecimal(int binNum)
{
    int ans = 0, pow = 1;

    while (binNum > 0)
    {
        int rem = binNum % 10;

        ans += (rem * pow);
        binNum /= 10;
        pow *= 2;
    }

    return ans;
}

int dtb(int decNum)
{
    int ans = 0, pow = 1;

    while (decNum > 0)
    {
        int rem = decNum % 2;
        decNum /= 2;

        ans += rem * pow;

        pow *= 10;
    }
    return ans;
}

int btd(int biNum)
{
    int ans = 0, pow = 1;

    while (biNum > 0)
    {
        int rem = biNum % 10;
        biNum /= 10;

        ans += rem * pow;

        pow *= 2;
    }
    return ans;
}

int main()
{
    // cout << decimalToBinary(50);
    // cout<< binaryToDecimal(110010);

    // cout << dtb(40);
    cout<< btd(1010);

    return 0;
}
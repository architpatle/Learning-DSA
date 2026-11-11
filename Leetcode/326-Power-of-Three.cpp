#include <iostream>
using namespace std;

bool isPowerOfThree(int n)
{
    if (n == 1)
        return true;

    if (n < 3)
        return false;

    while (n >= 3)
    {
        if (n % 3 == 0)
        {
            n /= 3;
        }
        else
        {
            return false;
        }
    }

    return n == 2 ? false : true;
}

int main()
{

    int n = 27;

    cout << "Is power of 3: " << isPowerOfThree(n);

    return 0;
}
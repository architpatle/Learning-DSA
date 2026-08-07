#include <iostream>
using namespace std;

int smallestNumber(int n, int t)
{
    for (int i = n;; i++)
    {
        int product = 1;

        int j = i;
        while (j >= 1)
        {
            int dig = j % 10;

            product *= dig;

            j /= 10;
        }

        if (product % t == 0)
        {
            return i;
        }
    }

    return -1;
}
int main()
{

    int n = 15, t = 3;

    cout << "Smallest Number: " << smallestNumber(n, t);

    return 0;
}
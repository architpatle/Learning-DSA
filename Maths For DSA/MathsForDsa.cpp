#include <iostream>
#include <vector>
using namespace std;

/* ----- INDEX -----
    1. Sieve of Eratosthenes
    2. Armstrong Number
    3. Euclid's Algorithm (GCD)
    4. LCM
    5. Reverse a Number

*/

// 1. Sieve of Eratosthenes
int CountPrimes(int n)
{
    vector<bool> isPrime(n + 1, true);

    int count = 0;

    for (int i = 2; i < n; i++)
    {
        if (isPrime[i])
        {
            count++;

            for (int j = i * 2; j < n; j = j + i)
            {
                isPrime[j] = false;
            }
        }
    }

    return count;
}

// 2. Armstrong Number
bool isArmstrong(int n)
{
    int sum = 0;
    int copyN = n;

    while (n != 0)
    {
        int dig = n % 10;

        sum += (dig * dig * dig);

        n /= 10;
    }

    return copyN == sum;
}

// 3. Euclid's Algorithm
int EuclidsAlgorithm(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }

    if (a == 0)
        return b;
    return a;
}

// 4. LCM
// NOTE: a*b = gcd(a,b) * lcm(a,b) => lcm(a, b) = (a * b) / gcd(a, b)
int LCM(int a, int b)
{
    int lcm = (a*b)/EuclidsAlgorithm(a,b);

    return lcm;
}

// 5. Reverse a Number
int ReverseANumber(int n){
    int reverse = 0;

    while(n>0){
        int dig = n%10;

        reverse = reverse*10 + dig;

        n/=10;
    }

    return reverse;
}

int main()
{
    int n = 1054613;
    int a = 20, b = 28;

    cout<<ReverseANumber(n);
    return 0;
}
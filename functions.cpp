#include <iostream>
using namespace std;

// min of 2 numbers
void minNum(int a, int b)
{

    if (a > b)
    {
        cout << "Minimum number is: " << b;
    }
    else
    {
        cout << "Minimum number is: " << a;
    }
}

// calculate sum of 1 to n numbers
int sumOfNNumbers(int n)
{

    int sum = 0;

    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }

    return sum;
}

// calculate factorial
int factorialOfNNumbers(int n)
{
    int factorial = 1;

    for (int i = 1; i <= n; i++)
    {
        factorial *= i;
    }

    return factorial;
}

// calcuate sum of digits of a number
int sumOfDigits(int num)
{
    int sum = 0;
    while (num > 0)
    {
        int lastDigit = num % 10;
        num /= 10;

        sum += lastDigit;
    }

    return sum;
}

// calculate nCr binomial coefficient for n & r
double binomialCoefficient(double n, double r)
{
    return (factorialOfNNumbers(n) / (factorialOfNNumbers(r) * factorialOfNNumbers(n - r)));
}

// Check if a number is prime or not
bool isPrimeOrNot(int n)
{
    bool isPrime = true;

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            isPrime = false;
            break;
        }
    }

    // if (isPrime)
    // {
    //     cout << "Prime";
    // }
    // else
    // {
    //     cout << "Not Prime";
    // }

    return isPrime;
}

void primeNumbersTillN(int n)
{
    for (int j = 2; j <= n; j++)

    {
        bool isPrime = true;
        for (int i = 2; i < j; i++)
        {
            if (j % i == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
        {
            cout << j<<" ";
        }
    }
}

int main()
{
    // minNum(7, 4);

    // cout << "Sum of 1 to n numbers is: " << sumOfNNumbers(10);

    // cout << "Factorial:" << factorialOfNNumbers(5);

    // cout << "Sum of Digits: " << sumOfDigits(726929);

    // cout << "Binomial Coefficient: " << binomialCoefficient(7, 2);

    // isPrimeOrNot(121);
    
    primeNumbersTillN(20);
    return 0;
}
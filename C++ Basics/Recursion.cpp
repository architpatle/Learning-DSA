#include <iostream>
using namespace std;

// Print numbers from n to 1
void printNums(int n)
{

    if (n == 1)
    {
        cout << "1" << endl;
        return;
    }
    cout << n << " ";

    printNums(n - 1);
}

// n Factorial
int nFactorial(int n)
{
    // !n = n* !(n-1)

    if (n == 0)
    {
        return 1;
    }

    return n * nFactorial(n - 1);
}

// Sum of N numbers
int SumOfNNumbers(int n)
{
    // sum(n) = n + sum(n-1)

    if (n == 1)
    {
        return 1;
    }
    return n + SumOfNNumbers(n - 1);
}

// Fibonacci Series
int Fibonacci(int n)
{
    // F(n) = F(n-1) + F(n-2)

    if (n == 0 || n == 1)
    {
        return n;
    }
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

// Check if the array is sorted or not
bool isSorted(int arr[], int n)
{
    if (n == 0 || n == 1)
        return true;
    return arr[n - 1] >= arr[n - 2] && isSorted(arr, n - 1);
}

// Recursive Binary Search
int BinarySearch(int arr[], int tar, int start, int end)
{

    if (start <= end)
    {
        int mid = start + ((end - start) / 2);

        if (arr[mid] == tar)
        {
            return mid;
        }
        else if (arr[mid] > tar)
        {
           return BinarySearch(arr, tar, start, mid - 1);
        }
        else
        {
            return BinarySearch(arr, tar, mid + 1, end);
        }
    }
    return -1;
}
int main()
{

    // printNums(4);

    // cout<<nFactorial(6);

    // cout<<SumOfNNumbers(4);

    // cout<<Fibonacci(6);

    int arr[] = {1, 3, 4, 5, 6};
    int tar = 1;

    // cout << isSorted(arr, 5);

    cout<< BinarySearch(arr,tar,0,4);
    return 0;
}
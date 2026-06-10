#include <iostream>
using namespace std;

// To find maximum subarray's sum
void maxSubarraySum(int arr[], int size)
{
    int maxSum = INT16_MIN;

    for (int start = 0; start < size; start++)
    {
        int currentSum = 0;
        for (int end = start; end < size; end++)
        {
            currentSum += arr[end];
            maxSum = max(maxSum, currentSum);
        }
    }

    cout << "Maximum sum: " << maxSum;
}

// Kadane's algorithm
void kadanes(int arr[], int size)
{
    int maxSum = INT16_MIN;
    int currentSum = 0;

    for (int i = 0; i < size; i++)
    {
        currentSum += arr[i];

        maxSum = max(currentSum, maxSum);

        if (currentSum < 0)
        {
            currentSum = 0;
        }
    }

    cout << "Maximum sum: " << maxSum;
}

int main()
{
    int arr[] = {1, -2, 3, 4, -5};

    // maxSubarraySum(arr, 5);
    kadanes(arr, 5);

    return 0;
}
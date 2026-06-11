#include <iostream>
#include <vector>
using namespace std;

/* ---------- INDEX ----------
1. To find maximum subarray's sum
2. Kadane's algorithm
3. Maximum Product Subarray using Brute Force
4. Maximum Product Subarray for O(n)
*/

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

// 2. Kadane's algorithm
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

// 3. Maximum Product Subarray using Brute Force
void maximumProductSubarrayBF(int arr[], int size)
{
    int maxProduct = INT16_MIN;

    for (int start = 0; start < size; start++)
    {
        int currentProduct = 1;

        for (int end = start; end < size; end++)
        {
            currentProduct *= arr[end];

            maxProduct = max(maxProduct, currentProduct);
        }
    }

    cout << "Max Product: " << maxProduct;
}

// 4. Maximum Product Subarray for O(n)
int maximumProductSubArray(int arr[], int size)
{

    int maxEndingHere = arr[0];
    int minEndingHere = arr[0];
    int maxProduct = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] < 0)
        {
            swap(minEndingHere, maxEndingHere);
        }

        maxEndingHere = max(arr[i], maxEndingHere * arr[i]);
        minEndingHere = min(arr[i], minEndingHere * arr[i]);

        maxProduct = max(maxProduct, maxEndingHere);
    }

    cout << "Max Product: " << maxProduct;
}

int main()
{
    int arr[] = {1, 2, -3, -4, -5};
    vector<int> nums = {1, 3, -3, -4, 4};

    // maxSubarraySum(arr, 5);

    // kadanes(arr, 5);

    maximumProductSubarrayBF(arr, 5);
    maximumProductSubArray(arr, 5);

    return 0;
}
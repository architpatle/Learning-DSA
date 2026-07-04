#include <iostream>
#include <vector>
using namespace std;

// ----- Painter's Partition Problem -----
/*  1. In this An array is given, each value tells the number of minutes it will take to paint the particular boat
    2. Given n = number of boats, m = Number of painters
    3. Boats can be painted in contiguous Manner only
    4. Objective is to find minimum duration to paint all the boats
    5. TC : O(log sum * n)
*/

bool isPossible(vector<int> arr, int n, int m, int maxAllowedTime)
{
    int painter = 1, time = 0;

    for (int i = 0; i < n; i++) // O(n)
    {
        if (time + arr[i] <= maxAllowedTime)
        {
            time += arr[i];
        }
        else
        {
            painter++;
            time = arr[i];
        }
    }

    return painter <= m;
}

int minTimeToPaint(vector<int> arr, int n, int m)
{
    int maxVal = INT16_MIN, sum = 0; // maxVal of the acutal array is the minimum amount of time for creating the range of time

    // Range = (maxOfActualArray -to- sumOfActualArrayValues)

    for (int val : arr) // O(n)
    {
        maxVal = max(maxVal, val);
        sum += val;
    }

    // Applying Binary Search on Range of values Array

    int start = maxVal, end = sum, ans = -1;
    while (start <= end) // O(log sum * n)
    {
        int mid = start + ((end - start) / 2);

        // If the mid value isPossible for time taken to paint by a painter then we try to find any other smaller possible value,
        // by moving in left subarray, else we move to right subarray
        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return ans;
}

// ----- Practice ----

bool isPossiblePractice(vector<int> arr, int n, int m, int maxAllowedTime)
{

    int painters = 1, time = 0;

    for (int i = 0; i < n; i++)
    {
        if (time + arr[i] <= maxAllowedTime)
        {
            time += arr[i];
        }
        else
        {
            painters++;
            time = arr[i];
        }
    }

    return painters <= m;
}

int minTimeToPaintPractice(vector<int> arr, int n, int m)
{

    int maxVal = INT32_MIN, sum = 0;

    for (int val : arr)
    {
        maxVal = max(maxVal, val);
        sum += val;
    }

    int start = maxVal, end = sum, ans = -1;

    while (start <= end)
    {
        int mid = start + ((end - start) / 2);

        if (isPossiblePractice(arr, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> boats = {40, 80, 20, 10};
    int n = 4, m = 2;

    cout << minTimeToPaint(boats, n, m) << endl;

    cout << minTimeToPaintPractice(boats, n, m);
    return 0;
}
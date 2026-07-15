#include <iostream>
#include <vector>
using namespace std;

// ----- Searching Peak Index in Mountain Array -----
/*  1. The Array has a peak value, which is greater than all other elements in the array.
    2. Also from arr[0] to peak value, all numbers are increasing. And, from peak value to arr[size-1] value, all numbers are decreasing.
    3. Binary Search Algorithm Logic is applied here. (TC: O(log n))
*/

int SearchingPeakIndexInMountainArray(vector<int> arr)
{

    // 0th index and nth index are discared in this because they cannot be the peak value ever.
    int start = 1, end = arr.size() - 2;

    while (start <= end)
    {
        int mid = start + ((end - start) / 2);

        // checking if the mid value is the peak value ( eventually it will be)
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
        {
            return mid;
        }

        // if mid is not the peak as per above check, then we check where is the peak value i.e on the left or right of th e current mid
        if (arr[mid - 1] < arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return -1;
}

int main()
{

    vector<int> arr = {0,3,8,9,5,2};

    cout << SearchingPeakIndexInMountainArray(arr);

    return 0;
}
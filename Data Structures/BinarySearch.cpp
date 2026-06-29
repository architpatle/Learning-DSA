#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> nums, int target)
{
    int start = 0, end = nums.size() - 1;

    while (start <= end)
    {
        int mid = start + ((end - start) / 2);

        if (nums[mid] > target)
        {
            end = mid - 1;
        }
        else if (nums[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            return mid;
        }
    }

    return -1;
}

int main()
{

    vector<int> nums = {-1, 0, 3, 6, 7, 12};
    int target = 12;

    cout << binarySearch(nums, target);

    return 0;
}
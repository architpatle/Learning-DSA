#include <iostream>
#include <vector>
using namespace std;

// ----- Search in Rotated Sorted Array -----
// 1. It is done using modified version of Binary Search Algorithm
// 2. Time Complexity: O(log n)

int SearchInRotatedSortedArray(vector<int> nums, int target)
{
    int start = 0, end = nums.size() - 1;

    while (start <= end)
    {
        int mid = start + ((end - start) / 2);

        // checking if the mid value is equal to the target value
        if (nums[mid] == target)
        {
            return mid;
        }

        // checking if the left search space is sorted, else right search space is sorted
        if (nums[start] <= nums[mid])
        {

            // checking if the target is between the start and the mid

            if (nums[start] <= target && target <= nums[mid])
            {
                // if yes then reduce the search space by bringing end to mid-1
                end = mid - 1;
            }
            else
            {
                // if no then reduce the search space by bringing start to mid+1
                start = mid + 1;
            }
        }
        else
        {
            // checking if the target is between the mid and the end

            if (nums[mid] <= target && target <= nums[end])
            {
                // if yes then reduce the search space by bringing start to mid+1
                start = mid + 1;
            }
            else
            {
                // if no then reduce the search space by bringing end to mid-1
                end = mid - 1;
            }
        }
    }

    return -1;
}

int SearchInRotatedSortedArrayPractice(vector<int> nums, int target){
    int start = 0, end = nums.size() -1;

    while(start<=end){
        int mid = start + ((end - start)/2);

        if(nums[mid] == target){
            return mid;
        }

        if(nums[start]<= nums[mid]){

            if(nums[start] <= target && target <= nums[mid]){
                end = mid -1;
            } else {
                start = mid + 1;
            }
        } else {

            if(nums[mid] <= target && target <= nums[end]){
                start = mid +1;
            } else {
                end = mid -1;
            }
        }
    }

    return -1;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 2;

    cout << SearchInRotatedSortedArray(nums, target) <<endl;
    cout << SearchInRotatedSortedArrayPractice(nums, target) <<endl;


    return 0;
}
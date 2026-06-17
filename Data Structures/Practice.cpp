#include <iostream>
#include <vector>
using namespace std;

/* ---------- INDEX ----------
 1. To Find Maximum and Minimum Number in an Array
 2. Linear Search in an Array
 3. Reverse an Array
 4. Sum and Products of all the Array Numbers
 5. Swap Max Num and Min Num in an Array
 6. Find unique values in an array
 7. Intersection of Arrays
 8. Maximum Sub-array's Sum
*/

// 1. To Find Maximum and Minimum Number in an Array
vector<int> maxAndMin(vector<int> &nums)
{
    vector<int> ans;
    int maxNum = INT16_MIN, minNum = INT16_MAX;

    for (int val : nums)
    {
        maxNum = max(maxNum, val);
        minNum = min(minNum, val);
    }

    ans.push_back(maxNum);
    ans.push_back(minNum);

    return ans;
}

// 2. Linear Search in an Array
int linearSearch(vector<int> nums, int target)
{
    int i = 0;

    for (int val : nums)
    {
        if (val == target)
        {
            return i;
        }
        i++;
    }
    return -1;
}

// 3. Reverse an Array
void reverseAnArray(vector<int> &nums)
{
    int start = 0, end = nums.size() - 1;

    while (start < end)
    {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }

    for (int val : nums)
    {
        cout << val << " ";
    }
}

// 4. Sum and Products of all the Array Numbers
vector<int> sumAndProducts(vector<int> nums)
{
    int sum = 0, product = 1;
    vector<int> ans;

    for (int val : nums)
    {
        sum += val;
        product *= val;
    }

    ans.push_back(sum);
    ans.push_back(product);

    return ans;
}

// 5.  Swap Max Num and Min Num in an Array
vector<int> swapMaxAndMin(vector<int> &nums)
{
    int minNum = INT16_MAX, maxNum = INT16_MIN;
    int maxIndex, minIndex;

    for (int val : nums)
    {
        maxNum = max(maxNum, val);
        minNum = min(minNum, val);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (maxNum == nums[i])
        {
            maxIndex = i;
        }
        if (minNum == nums[i])
        {
            minIndex = i;
        }
    }

    swap(nums[maxIndex], nums[minIndex]);

    return nums;
}

// 6. Find unique values in an array
vector<int> uniqueValues(vector<int> &nums)
{
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {

        bool isUnique = true;

        for (int j = 0; j < nums.size(); j++)
        {
            if ((nums[i] == nums[j]) && i != j)
            {
                isUnique = false;
                break;
            }
        }
        if (isUnique)
        {
            ans.push_back(nums[i]);
        }
    }

    return ans;
}

// 7. Intersection of Arrays
vector<int> intersectionOfArrays(vector<int> arr1, vector<int> arr2)
{
    vector<int> ans;

    for (int val1 : arr1)
    {
        for (int val2 : arr2)
        {
            if (val1 == val2)
            {
                ans.push_back(val1);
                break;
            }
        }
    }

    return ans;
}

// 8. Maximum Sub-array's Sum
int maxSubarraySum(vector<int> nums){
    int maxSum = INT16_MIN;
    
    for(int i =0; i<nums.size(); i++){
        int currentSum = 0;
        for( int j =i; j<nums.size(); j++ ){
            currentSum += nums[j]; 
        maxSum = max(maxSum, currentSum);

        }
        
        
    }
    return maxSum;
}

int main()
{
    vector<int> nums = {3, -1, 3, 6, 4, 2};
    vector<int> arr1 = {3, 1, 3, 6, 4, 2};
    vector<int> arr2 = {3, 4, 6, 2, 2};

    // 1.
    //  vector<int> ans = maxAndMin(nums);

    // cout << "Max Num: " << ans[0] << endl
    //      << "Min Num: " << ans[1];

    // 2.
    // int target = 2333;

    // cout << linearSearch(nums, target);

    // 3.
    // reverseAnArray(nums);

    // 4.
    // vector<int> ans = sumAndProducts(nums);
    // cout << "Sum: " << ans[0] << endl
    //      << "Product: " << ans[1];

    // 5.
    // vector<int> ans = swapMaxAndMin(nums);
    // for (int val : ans)
    // {
    //     cout << val << " ";
    // }

    // 6.
    // vector<int> ans = uniqueValues(nums);
    // for (int val : ans)
    // {
    //     cout << val << " ";
    // }

    // 7.
    // vector<int> ans = intersectionOfArrays(arr1, arr2);
    // for (int val : ans)
    // {
    //     cout << val << " ";
    // }

    // 8.
   cout<< maxSubarraySum(nums);

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

/* ---------- INDEX ----------
 1. To Find Maximum and Minimum Number in an Array
 2. Linear Search in an Array
 3. Reverse an Array
 4. Sum and Products of all the Array Numbers
 5.  Swap Max Num and Min Num in an Array
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

int main()
{
    vector<int> nums = {2, 6, 12, -8, -1};

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
    vector<int> ans = swapMaxAndMin(nums);
    for (int val : ans)
    {
        cout << val << " ";
    }

    return 0;
}
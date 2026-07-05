#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* ---------- INDEX ----------
 01. To Find Maximum and Minimum Number in an Array
 02. Linear Search in an Array
 03. Reverse an Array
 04. Sum and Products of all the Array Numbers
 05. Swap Max Num and Min Num in an Array
 06. Find unique values in an array
 07. Intersection of Arrays
 08. Maximum Sub-array's Sum (Kadane's Algorithm)
 09. Maximum Product of Subarray
 10. Majority Element in an Array (Moore's Voting Algorithm)
 11. Pair Sum in an Array
 12. To Find Maximum Profit by Buying and Selling the Stock
 13. Container with Most Water
 14. Product of Array Number except Self
 15. Binary Exponentiation
 16. Binary Search Algorithm
 17. Search in Rotated Sorted Array

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

// 8. Maximum Sub-array's Sum (Kadane's Algorithm)
int maxSubarraySum(vector<int> nums)
{
    int maxSum = INT16_MIN;
    int currentSum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        currentSum += nums[i];
        maxSum = max(maxSum, currentSum);

        if (currentSum < 0)
        {
            currentSum = 0;
        }
    }
    return maxSum;
}

// 9. Maximum Product of Subarray
int maxSubarrayProduct(vector<int> nums)
{

    int maxProduct = nums[0], maxEndingHere = nums[0], minEndingHere = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {

        if (nums[i] < 0)
        {
            swap(minEndingHere, maxEndingHere);
        }

        minEndingHere = min(nums[i], minEndingHere * nums[i]);
        maxEndingHere = max(nums[i], maxEndingHere * nums[i]);

        maxProduct = max(maxProduct, maxEndingHere);
    }

    return maxProduct;
}

// 10. Majority Element in an Array (Moore's Voting Algorithm)
int majorityElementInAnArray(vector<int> nums)
{
    int ans = 0;
    int frequency = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (frequency == 0)
        {
            ans = nums[i];
        }

        if (ans == nums[i])
        {
            frequency++;
        }
        else
        {
            frequency--;
        }
    }
    return ans;
}

// 11. Pair Sum in an Array
vector<int> pairSum(vector<int> nums, int target)
{
    vector<int> ans;
    int size = nums.size();
    int start = 0, end = size - 1;

    while (start < end)
    {
        int pairSum = nums[start] + nums[end];

        if (pairSum < target)
        {
            start++;
        }
        else if (pairSum > target)
        {
            end--;
        }
        else
        {
            ans.push_back(nums[start]);
            ans.push_back(nums[end]);
            return ans;
        }
    }
}

// 12. To Find Maximum Profit by Buying and Selling the Stock
int maxProfitBuyAndSellStock(vector<int> prices)
{
    int maxProfit = 0;
    int bestBuy = prices[0];

    for (int i = 1; i < prices.size(); i++)
    {
        int bestSell = prices[i];

        if (bestBuy < bestSell)
        {
            maxProfit = max(maxProfit, bestSell - bestBuy);
        }
        bestBuy = min(bestBuy, bestSell);
    }

    return maxProfit;
}

// 13. Container with Most Water
int containerWithMostWater(vector<int> heights)
{
    int maxArea = 0;
    int leftHeight = 0, rightHeight = heights.size() - 1;

    while (leftHeight < rightHeight)
    {
        int height = min(heights[leftHeight], heights[rightHeight]);
        int base = rightHeight - leftHeight;

        int area = height * base;

        maxArea = max(maxArea, area);

        if (heights[leftHeight] < heights[rightHeight])
        {

            leftHeight++;
        }
        else
        {
            rightHeight--;
        }
    }
    return maxArea;
}

// 14. Product of Array Number except Self
vector<int> productOfArrayExceptSelf(vector<int> nums)
{
    vector<int> ans(nums.size(), 1);

    for (int i = 1; i < nums.size(); i++)
    {
        ans[i] = ans[i - 1] * nums[i - 1];
    }

    int suffix = 1;
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        suffix *= nums[i + 1];
        ans[i] *= suffix;
    }

    return ans;
}

// 15. Binary Exponentiation
double binaryExponentiation(double x, int n)
{

    int ans = 1;

    if (n < 0)
    {
        x = 1 / x;
        n = -n;
    }

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ans *= x;
        }
        x *= x;
        n /= 2;
    }

    return ans;
}

// 16. Binary Search Algorithm
int BinarySearchAlgorithm(vector<int> arr, int target)
{
    int start = 0, end = arr.size() - 1;

    while (start <= end)
    {
        int mid = start + ((end - start / 2));

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return -1;
}

// 17. Search in Rotated Sorted Array
int SearchInRotatedSortedArray(vector<int> arr, int target)
{
    int start = 0, end = arr.size() - 1;

    while (start <= end)
    {
        int mid = start + ((end - start)) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] >= arr[start])
        {
            if (arr[start] <= target && target <= arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else
        {
            if (arr[mid] <= target && target <= arr[end])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    vector<int> nums = {3, 6, 7, 9, 0, 1, 2};
    vector<int> heights = {5, 2, 8, 1, 8};

    cout << SearchInRotatedSortedArray(nums, 1);

    return 0;
}
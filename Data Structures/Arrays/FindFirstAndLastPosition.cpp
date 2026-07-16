#include <iostream>
#include <vector>
using namespace std;

vector<int> searchIndec(vector<int> nums, int target)
{
    int start = 0, end = nums.size() - 1;
    vector<int> ans = {-1, -1};

    while (start <= end)
    {
        if (nums[start] == target && ans[0] == -1)
        {
            ans[0] = start;
        }
        if (nums[end] == target && ans[1] == -1)
        {
            ans[1] = end;
        }

        if (ans[0] == -1)
            start++;

        if (ans[1] == -1)
            end--;

        if (ans[0] != -1 && ans[1] != -1)
            break;
    }

    return ans;
}
int main()
{

    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 10;

    vector<int> ans = searchIndec(nums, target);

    for (int val : ans)
    {
        cout << val << " ";
    }
    return 0;
}
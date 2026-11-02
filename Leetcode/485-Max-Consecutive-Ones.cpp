#include <iostream>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int count = 0, maxCount = 0;

    for(int i =0; i<nums.size(); i++){
        if(nums[i] == 1){
            count++;
            maxCount = max(maxCount, count);
        } else {
            count = 0;
        }
    }

    return maxCount;
}

int main()
{

    vector<int> nums = {1, 1, 0, 0, 0, 1, 1, 1};

    cout << "Max Consecutive Ones: " << findMaxConsecutiveOnes(nums);

    return 0;
}
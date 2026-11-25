#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int maxLength(vector<int> &nums)
{
    int maxLen = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        long long currProd = nums[i];
        long long currGCD = nums[i];
        long long currLCM = nums[i];

        for (int j = i + 1; j < nums.size(); j++)
        {
            currProd *= nums[j];
            // currGCD = gcd(currGCD, nums[j]); // gcd() subjected to compiler version
            // currLCM = lcm(currLCM, nums[j]); // lcm() subjected to compiler version

            if(currGCD > __LONG_LONG_MAX__ / currLCM)
                break;
            
            if(currProd == currGCD * currLCM){
                int currLen = j - i +1;
                maxLen = max(maxLen, currLen);
            }

            if(currProd > currGCD * currLCM)
                break;
        }
    }

    return maxLen;
}

int main()
{

    vector<int> nums = {1, 2, 1, 2, 1, 1, 1};

    cout << "Max Length: " << maxLength(nums);

    return 0;
}
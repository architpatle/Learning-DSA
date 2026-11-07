#include <iostream>
#include <vector>
#include <map>
using namespace std;

int firstUniqueEven(vector<int> &nums)
{
    map<int, int> m;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % 2 == 0)
        {
            m[nums[i]]++;
        }
    }

    if(m.size() == 0){
        return -1;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (m.find(nums[i]) != m.end() && m[nums[i]] == 1)
        {
            return nums[i];
        }
    }

    return -1;
}

int main()
{

    vector<int> nums = {3, 4, 2, 5, 4, 6};

    cout<<"First Unique Even Number: "<<firstUniqueEven(nums);

    return 0;
}
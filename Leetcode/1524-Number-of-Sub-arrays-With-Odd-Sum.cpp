#include <iostream>
#include <vector>
using namespace std;

int numOfSubarrays(vector<int> &arr)
{
    long long even = 1, odd = 0;
    long long prefixSum = 0, ans = 0;

    const long long MOD = 1000000007LL;

    for (int i = 0; i < arr.size(); i++)
    {
        prefixSum += arr[i];

        if (prefixSum % 2 == 0)
        {
            even++;
            ans += odd;
        }
        else
        {
            odd++;
            ans += even;
        }
    }

    return ans % MOD;
}

int main()
{
    vector<int> arr = {1, 3, 5};

    cout << "Number of Sub-Arrays with odd sum: " << numOfSubarrays(arr);

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> FourSum(vector<int> arr, int target)
{
    vector<vector<int>> ans;
    int n = arr.size();

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        for (int j = i + 1; j < n;)
        {

            int p = j + 1, q = n - 1;

            while (p < q)
            {
                long long sum = (long long)arr[i] + (long long)arr[j] + (long long)arr[p] + (long long)arr[q];

                if (sum < target)
                {
                    p++;
                }
                else if (sum > target)
                {
                    q--;
                }
                else
                {
                    ans.push_back({arr[i], arr[j], arr[p], arr[q]});
                    p++;
                    q--;
                    while (p < q && arr[p] == arr[p - 1])
                        p++;
                }
            }

            j++;
            while (j < n && arr[j] == arr[j - 1])
            {
                j++;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {-1, -1, 0, 1, 1, 2};
    int target = 0;

    vector<vector<int>> ans = FourSum(arr, target);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {

            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
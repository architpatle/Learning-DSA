#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int SubarraySum(vector<int> arr, int k)
{
    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];

            if (sum == k)
                count++;
        }
    }

    return count++;
}

int SubArraySumOA(vector<int> arr, int key)
{

    int n = arr.size();
    int count = 0;
    unordered_map<int, int> m;

    vector<int> preArr(n,0);
    preArr[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        preArr[i] = preArr[i - 1] + arr[i];
    }

    for (int j = 0; j < n; j++)
    {

        if (preArr[j] == key)
            count++;

        int val = preArr[j] -key;
        if(m.find(val) != m.end() ){
            count += m[val];
        }

        if(m.find(val) == m.end()){
            m[preArr[j]] =0;
        }
        m[preArr[j]]++;
    }

    return count;
}

int main()
{

    vector<int> arr = {9, 4, 20, 3, 10, 5};
    int k = 33;

    cout << SubArraySumOA(arr, k);

    return 0;
}
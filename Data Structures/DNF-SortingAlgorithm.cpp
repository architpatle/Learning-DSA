#include <iostream>
#include <vector>
using namespace std;

// 1. Using Brute Force Method i.e sort(arr.begin(), arr.end()) TC = O(n logn)

// 2. Optimal solution at TC = O(n)
void sortArr(vector<int> &arr)
{
    int count0 = 0, count1 = 0, count2 = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            count0++;
        }
        else if (arr[i] == 1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
    }

    int idx = 0;
    for (int i = 0; i < count0; i++)
    {
        arr[idx++] = 0;
    }
    for (int i = 0; i < count1; i++)
    {
        arr[idx++] = 1;
    }
    for (int i = 0; i < count2; i++)
    {
        arr[idx++] = 2;
    }
}

// 3. Most Optimal Solution using Dutch National Flag Algorithm (TC = O(n)). With single run/loop
void DNSAlgorithm(vector<int> &arr)
{

    int mid = 0, low = 0, high = arr.size() - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

void DNSAlgorithmPractice(vector<int> &arr)
{
    int low = 0, mid = 0, high = arr.size() - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 1, 2, 2, 0, 0, 1, 0, 1, 2};

    DNSAlgorithmPractice(arr);

    for (int val : arr)
    {
        cout << val << " ";
    }

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

void ReverseArray(vector<int> &arr, int start, int end)
{
    while (start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    return;
}

void NextPermutation(vector<int> &arr)
{

    // 1. Find Pivot
    int pivot = -1;

    for (int i = arr.size() - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            pivot = i;
            break;
        }
    }

    // edge case if the entire array is in decreasing order {5,4,3,2,1}
    if (pivot == -1)
    {
        int start = 0, end = arr.size() - 1;
        while (start <= end)
        {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }

        return;
    }

    // 2. Find Right Most Element > pivot and swap them
    for (int i = arr.size() - 1; i > pivot; i--)
    {
        if (arr[i] > arr[pivot])
        {
            swap(arr[pivot], arr[i]);
            break;
        }
    }

    // 3. Reverse the pivot+1 to size -1

    int i = pivot + 1, j = arr.size() - 1;
    while (i <= j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

void NextPermutationPractice(vector<int> &arr)
{

    // Find Pivot
    int pivot = -1;
    int n = arr.size();

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            pivot = i;
            break;
        }
    }

    // if pivot remains -1;
    if (pivot == -1)
    {

        int start = 0, end = n - 1;
        while (start <= end)
        {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
        return;
    }

    // Swap Right most element with pivot element
    for (int i = n - 1; i >= pivot; i--)
    {
        if (arr[pivot] < arr[i])
        {
            swap(arr[pivot], arr[i]);
            break;
        }
    }

    // Reverse the pivot+1 to n-1
    int i = pivot + 1, j = n - 1;
    while (i <= j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    return;
}

int main()
{

    vector<int> arr = {1, 2, 5, 4, 3};

    NextPermutationPractice(arr);

    for (int val : arr)
    {
        cout << val << " ";
    }

    return 0;
}
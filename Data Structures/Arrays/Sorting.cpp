#include <iostream>
#include <vector>
using namespace std;

// ----- SORTING -----
// 1. Bubble Sort
// 2. Selection Sort
// 3. Insertion Sort
// 4. Merge Sort
// 5. Quick Sort

// 1. Bubble Sort
void BubbleSort(vector<int> &arr)
{
    //     int sortedArr;

    for (int i = 0; i < arr.size(); i++)
    {
        bool isSwap = false;

        for (int j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }

        if (!isSwap)
        {
            return;
        }
    }
}

// 2. Selection Sort
void SelectionSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int smallestIndex = i;

        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[smallestIndex] > arr[j])
            {
                smallestIndex = j;
            }
        }
        swap(arr[smallestIndex], arr[i]);
    }
}

// 3. Insertion Sort
void InsertionSort(vector<int> &arr)
{

    for (int i = 1; i < arr.size(); i++)
    {
        int current = arr[i];

        int j = i - 1;

        while (j >= 0 && arr[j] > current)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = current;
    }
}

// 4. Merge Sort
void Merge(vector<int> &arr, int start, int mid, int end)
{
    vector<int> temp;
    int i = start, j = mid + 1;

    while (i <= mid && j <= end)
    {

        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= mid)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int idx = 0; idx < temp.size(); idx++)
    {
        arr[start + idx] = temp[idx];
    }
}
void MergeSort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;

        // dividing left half
        MergeSort(arr, start, mid);

        // dividing left half
        MergeSort(arr, mid + 1, end);

        Merge(arr, start, mid, end);
    }
}

// 5. Quick Sort
int Partition(vector<int> &arr, int start, int end)
{
    int idx = start - 1;
    int pivotElement = arr[end];

    for (int j = start; j < end; j++)
    {
        if (arr[j] <= pivotElement)
        {
            idx++;
            swap(arr[j], arr[idx]);
        }
    }

    idx++;
    swap(arr[end], arr[idx]);

    return idx;
}
void QuickSort(vector<int> &arr, int start, int end)
{

    if (start < end)
    {

        int pivotIdx = Partition(arr, start, end);

        // left half partition
        QuickSort(arr, start, pivotIdx - 1);

        // right half partition
        QuickSort(arr, pivotIdx + 1, end);
    }
}
int main()
{
    vector<int> nums = {
        3,
        2,
        5,
        8,
        1,
        -8,
        9,
        6,
    };

    QuickSort(nums, 0, nums.size() - 1);

    cout << "sortedArr: ";

    for (int val : nums)
    {
        cout << val << " ";
    }

    return 0;
}
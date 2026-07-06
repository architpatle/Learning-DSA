#include <iostream>
#include <vector>
using namespace std;

// ----- SORTING -----
// 1. Bubble Sort
// 2. Selection Sort
// 3. Insertion Sort

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

// ----- PRACTICE -----

// 1. Bubble Sort
void BubbleSortPractice(vector<int> &arr)
{

    for (int i = 0; i < arr.size(); i++)
    {

        for (int j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// 2. Selection Sort
void SelectionSortPractice(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int smallestIdx = i;

        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[smallestIdx] > arr[j])
            {
                smallestIdx = j;
            }
        }

        swap(arr[smallestIdx], arr[i]);
    }
}

// 3. Insertion Sort
void InsertionSortPractice(vector<int> &arr)
{

    for (int i = 1; i < arr.size(); i++)
    {
        int curr = arr[i];
        int j = i - 1;

        while (j >= 0 && curr < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = curr;
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

    InsertionSortPractice(nums);

    cout << "sortedArr: ";

    for (int val : nums)
    {
        cout << val << " ";
    }

    return 0;
}
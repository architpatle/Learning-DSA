#include <iostream>
using namespace std;

void smallestAndLargestNumInArray()
{
    int size = 5;
    int arr[size] = {3, 4, 1, 7, 5};
    int smallest = INT16_MAX;
    int largest = INT16_MIN;

    for (int i = 0; i < size; i++)
    {
        smallest = min(arr[i], smallest);
        largest = max(arr[i], largest);
    }

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == smallest)
        {
            cout << "Smallest number " << smallest << " is at index " << i << endl;
            break;
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == largest)
        {
            cout << "Largest number " << largest << " is at index " << i;
            break;
        }
    }
}

void linearSearch(int arr[], int size, int target)
{
    bool targetFound = false;
    int index;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            index = i;
            targetFound = true;
        }
    }

    if (targetFound)
    {
        cout << target << " found at index " << index;
    }
    else
    {
        cout << target << " is not in the array";
    }
}

void reverseAnArray(int arr[], int size)
{
    // for (int i = size - 1; i >= 0; i--)
    // {
    //     cout << arr[i] << " ";
    // }

    int start = 0, end = size - 1;

    while (start < end)
    {
        swap(arr[start], arr[end]);

        start++;
        end--;
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void sumAndProductOfArrayNumbers(int arr[], int size)
{
    int sum = 0, product = 1;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
        product *= arr[i];
    }

    cout << "Sum of Array Numbers: " << sum << endl;
    cout << "Product of Array Numbers: " << product << endl;
}

void swapMaxAndMinInArray(int arr[], int size)
{
    int maxNum = INT16_MIN;
    int minNum = INT16_MAX;
    int maxIndex, minIndex;

    for (int i = 0; i < size; i++)
    {
        maxNum = max(maxNum, arr[i]);
        minNum = min(minNum, arr[i]);
    }

    // cout<<maxNum<<" "<<minNum;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == maxNum)
        {
            maxIndex = i;
            break;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == minNum)
        {
            minIndex = i;
            break;
        }
    }

    swap(arr[maxIndex], arr[minIndex]);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void uniqueValueInArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        bool isUnique = true;

        for (int j = 0; j < size; j++)
        {
            if (arr[i] == arr[j] && i != j)
            {
                isUnique = false;
            }
        }

        if (isUnique)
        {
            cout << arr[i] << " ";
        }
    }
}

void intersectionOfArray(int arr1[], int arr2[], int size)
{

    for (int i = 0; i < size; i++)
    {

        bool isMatch = false;

        for (int j = 0; j < size; j++)
        {

            if (arr1[i] == arr2[j])
            {
                isMatch = true;
                break;
            }
        }

        if (isMatch)
        {
            cout << arr1[i] << " ";
        }
    }
}

int main()
{
    // int size = 5;
    // int marks[size];

    // // int size = sizeof(marks) / sizeof(int);

    // cout << "Enter the elements of array: ";
    // for (int i = 0; i < size; i++)
    // {
    //     cin >> marks[i];
    // }

    // cout << "The array is: ";

    // for (int i = 0; i < size; i++)
    // {
    //     cout << marks[i] << " ";
    // }

    // smallestAndLargestNumInArray();

    int arr[] = {2, 4, 4, 5, 6};
    int arr1[] = {1, 4, 3, 7, 2};
    int arr2[] = {2, 8, 3, 7, 7};

    // linearSearch(arr, 8, 212);

    // cout << "In Reverse Array Function: ";
    // reverseAnArray(arr, 8);

    // cout << endl;
    // cout << "In main function: ";

    // for (int i = 0; i < 8; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    // sumAndProductOfArrayNumbers(arr, 4);

    // swapMaxAndMinInArray(arr, 4);

    // uniqueValueInArray(arr, 5);

    intersectionOfArray(arr1, arr2, 5);

    return 0;
}

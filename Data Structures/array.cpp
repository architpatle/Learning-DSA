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

    int arr[] = {3, 6, 4, 7, 8, 1, 9, 21};

    linearSearch(arr, 8, 212);

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

// ----- Searching Single Element in Sorted Array -----
/*  1. The array is of the type [2,2,4,4,6,7,7,9,9]
    2. Need to apply BSA (TC: O(log n))
    3. Understanding: The array will always contain odd number of elements
*/

int SearchingSingleElementInSortedArray(vector<int> arr)
{

    int start = 0, end = arr.size() - 1;

    if(arr.size() == 1 ){
        return arr[0];
    }

    while (start <= end)
    {
        int mid = start + ((end - start) / 2);

        //checking corner cases where single element is 1st or last element
        if(mid == 0 && arr[0] != arr[1]) {
            return arr[mid];
        }
        if(mid == arr.size() -1  && arr[arr.size()-1] != arr[arr.size()-2]){
            return arr[mid];
        }

        // Checking is the mid value is the single Element
        if (arr[mid - 1] != arr[mid] && arr[mid] != arr[mid + 1])
        {
            return arr[mid];
        }

        // Checking if the elements on either side of the mid value is even or odd
        if (mid % 2 == 0)
        {
            // even elements on both side of mid value

            // checking if the single element is on left side or on right side of the mid value
            if (arr[mid - 1] == arr[mid])
            {
                // left side
                end = mid - 1;
            }
            else
            {
                // right side
                start = mid + 1;
            }
        }
        else
        {
            // odd elements on both side of mid value

            // checking if the single element is on left side or on right side of the mid value
            if (arr[mid - 1] == arr[mid])
            {

                // right side
                start = mid + 1;
            }
            else
            {
                // left side
                end = mid - 1;
            }
        }
    }
}

int main()
{

    vector<int> arr = {1,1,3,3,4,4,6,6,7};

    cout << SearchingSingleElementInSortedArray(arr);
    return 0;
}

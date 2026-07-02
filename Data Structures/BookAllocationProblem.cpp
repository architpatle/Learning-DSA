#include <iostream>
#include <vector>
using namespace std;

// ----- Book Allocation Problem -----
/*  1. The given array contains the Number of pages per book
    2. Number of students is given among which the books are to be divided
    3. Books must be divided in a contiguous manner
    4. Each student should get at least one book
    5. All books should be divded
    6. Goal is to allocate the books in such a way that maximum number of pages a student gets, should be minimum. (Max Possible Pages Value: 34,22, 15 => ANS = 15)
*/

// Function to check if the mid value is a posible max values
bool isValid(vector<int> arr, int n, int m, int maxAllowedPages)
{
    int students = 1, pages = 0;

    for (int i = 0; i < n; i++) // O( n)
    {
        if (arr[i] > maxAllowedPages)
        {
            return false;
        }

        if (pages + arr[i] <= maxAllowedPages)
        {
            pages += arr[i];
        }
        else
        {
            students++;
            pages = arr[i];
        }
    }

    return students > m ? false : true;
}

int BookAllocation(vector<int> arr, int n, int m)
{
    // return -1 if students is less than books
    if (m > n)
    {
        return -1;
    }

    // First find the range of pages that a single student can get from Min(0) to Max(Sum of all pages)
    int sumArr = 0;

    for (int val : arr) // O( n )
    {
        sumArr += val;
    }

    int start = 0, end = sumArr, ans = -1;

    while (start <= end) // O(n*log N)
    {
        int mid = start + ((end - start) / 2);

        // if mid value is valid maximum value of pages, then we move in left half to check if some smallear maximum possible value of pages is there
        if (isValid(arr, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> pages = {15,17,20}; // No. of pages in each book
    int n = 3, m = 2;                 // n -> No. of Book which is equal to size of array, m -> No. of students among which books are to be alloted

    cout<<BookAllocation(pages, n, m);
    return 0;
}
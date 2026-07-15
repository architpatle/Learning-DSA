#include <iostream>
#include <vector>
using namespace std;

// Linear Search using vector
void linearSearch(vector<int> vec, int target)
{
    bool targetFound = false;
    int index;

    for (int val : vec)
    {
        if (val == target)
        {
            targetFound = true;
            // index = vec.at();
            break;
        }
    }

    if (targetFound)
    {
        cout << "Target found";
    }
    else
    {
        cout << "Target Not Present";
    }
}

// Changing array
void reverseAnArray(vector<int>& vec)
{
    int start = 0, end = vec.size() - 1;

    while(start<end){
        swap(vec[start], vec[end]);
        start++;
        end--;
    }

    for( int val: vec){
        cout<<val<<" ";
    }
}

int main()
{
    // vector<int> vec(4, 30);

    // for (int val : vec)
    // {
    //     cout << val << " ";
    // }

    vector<int> vec = {4, 2, 3, 2, 3};

    int ans = 0;

    for (int val : vec)
    {
        ans = ans ^ val;
    }

    // int val = 6 ^ 6;

    // cout<<val;
    // cout << ans;

    // linearSearch(vec, 3);

    cout << "original Array: ";

    for (int val : vec)
    {
        cout << val << " ";
    }
    cout << endl;
    cout << "Change Array: ";

    reverseAnArray(vec);

    cout << endl;
    cout << "Main array after change: ";

    for (int val : vec)
    {
        cout << val << " ";
    }
    return 0;
}
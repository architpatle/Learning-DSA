#include <iostream>
#include <vector>
using namespace std;

// Merge two sorted Arrays
vector<int> MergeTwoSortedArrays(vector<int> arr1, vector<int> arr2)
{
    vector<int> ans;

    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size()) // i =3, j=0, ans = 11, 12, 13,
    {
        if (arr1[i] < arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
        }
        else
        {
            ans.push_back(arr2[j]);
            j++;
        }
    }

    while (i < arr1.size())
    {
        ans.push_back(arr1[i]);
        i++;
    }

    while (j < arr2.size())
    {
        ans.push_back(arr2[j]);
        j++;
    }

    return ans;
}

// Merge two sorted arrays (Optimal Approach)
void MergeTwoSortedArraysOA(vector<int> &arr1, vector<int> &arr2)
{
    int idx = arr1.size() + arr2.size() - 1, i = arr1.size() - 1, j = arr2.size() - 1;

    while (i >= 0 && j >= 0)
    {
        if (arr1[i] >= arr2[j])
        {
            arr1[idx] = arr1[i];
            idx--;
            i--;
        }
        else
        {
            arr1[idx] = arr2[j];
            idx--;
            j--;
        }
    }

    while (j >= 0)
    {
        arr1[idx] = arr2[j];
        idx--;
        j--;
    }

}

int main()
{
    vector<int> arr1 = {11, 12, 16};
    vector<int> arr2 = {12, 14, 15};

    MergeTwoSortedArraysOA(arr1, arr2);

    cout<<endl;
    for(int i =0; i<arr1.size() +arr2.size() -1; i++){
        cout<<arr1[i]<<" ";
    }
    return 0;
}
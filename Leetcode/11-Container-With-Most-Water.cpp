#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int> &arr)
{
    int i = 0;
    int j = arr.size() - 1;
    int maxAmount = 0;

    while (i < j)
    {
       int height = min(arr[i],arr[j]);
       int base = j-i;

       int currentAmount = height*base;

       maxAmount = max(maxAmount, currentAmount);

       (arr[i]<arr[j]) ? i++ : j-- ;
    }

    return maxAmount;
}

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << "Max Amount of Water: " << maxArea(height);

    return 0;
}
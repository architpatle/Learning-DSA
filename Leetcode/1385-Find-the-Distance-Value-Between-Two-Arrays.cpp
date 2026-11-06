#include <iostream>
#include <vector>
using namespace std;

int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
{
    int distance = 0;
    int count = 0;

    for (int i = 0; i < arr1.size(); i++)
    {

        for (int j = 0; j < arr2.size(); j++)
        {
            int diff = arr1[i] - arr2[j];

            if (diff < 0)
            {
                diff = -diff;
            }

            if (diff > d)
            {
                count++;
            }
        }
        if (count == arr2.size())
        {
            distance++;
        }
        count = 0;
    }

    return distance;
}

int main()
{
    vector<int> arr1 = {4, 5, 8};
    vector<int> arr2 = {10, 9, 1, 8};
    int d = 2;

    cout << "Distance: " << findTheDistanceValue(arr1, arr2, d);

    return 0;
}
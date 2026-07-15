#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ----- Agrressive Cows Problem -----
/*  1. The given array specifies the stall number to which the cows can be assigned
    2. Given: N = number of stalls available, C = Number of Cows
    3. Objective is to find minimum of the max Possible distance between the cows such that they are at max distance from each other
*/

bool isPossible(vector<int> arr, int N, int C, int minDistanceAllowed)
{
    int cows = 1, lastStallPosition = arr[0];

    for(int i =0; i<N; i++){ // O(N)
        if(arr[i] - lastStallPosition >= minDistanceAllowed){
            cows ++;
            lastStallPosition = arr[i];
        } 

        if(cows ==C) return true;
    }

    return false;
}

int getDistance(vector<int> arr, int N, int C)
{
    // Sort the given array to obtain min and max value in it and also usable for isPossible()
    sort(arr.begin(), arr.end()); // O(N log N)

    int start = 1, end = arr[N - 1] - arr[0], ans = -1;

    while (start <= end) // O(log Range * N)
    {
        int mid = start + ((end - start) / 2);

        if (isPossible(arr, N, C, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return ans;
}

int main()
{
    int N = 5, C = 3;
    vector<int> arr = {1, 2, 8, 4, 9};

    cout << getDistance(arr, N, C);
    return 0;
}
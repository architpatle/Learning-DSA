#include <iostream>
#include <vector>
using namespace std;

// 1. Container With Most Water (Brute Force)
int containerWithMostWaterBF(vector<int> heights)
{
    int maxVolume = INT16_MIN;

    for (int i = 0; i < heights.size(); i++)
    {
        int height, base;
        for (int j = i + 1; j < heights.size(); j++)
        {
            height = min(heights[i], heights[j]);

            base = j - i;

            int currentVolume = height * base;

            maxVolume = max(maxVolume, currentVolume);
        }
    }

    return maxVolume;
}

// 2. Container With Most Water (2 Pointer Approach)
int containerWithMostWaterTP(vector<int> heights)
{
    int maxWater = 0;
    int heightLeft = 0, heightRight = heights.size() - 1;

    while (heightLeft < heightRight)
    {
        int height = min(heights[heightLeft], heights[heightRight]);
        int base = heightRight - heightLeft;

        int currentWater = height * base;

        maxWater = max(maxWater, currentWater);

        (heights[heightLeft] < heights[heightRight]) ? heightLeft++ : heightRight--;
    }

    return maxWater;
}

int main()
{
    vector<int> heights = {8,7,2,1};

    // 1.
    // cout << "Max Volume: " << containerWithMostWaterBF(heights);

    // 2.
    cout << "Max Volume: " << containerWithMostWaterTP(heights);

    return 0;
}
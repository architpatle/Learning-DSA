#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
{
    unordered_set<int> s;

    for (int i = 0; i < fruits.size(); i++)
    {
        for (int j = 0; j < baskets.size(); j++)
        {
            if (fruits[i] <= baskets[j] && s.find(j) == s.end())
            {
                s.insert(j);
                break;
            }
        }
    }

    return baskets.size() - s.size();
}

int main()
{
    vector<int> fruits = {4, 2, 5};
    vector<int> baskets = {3, 5, 4};

    cout << "Number of unplaced Fruits: " << numOfUnplacedFruits(fruits, baskets) << endl;

    return 0;
}
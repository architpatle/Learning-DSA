#include <iostream>
#include <vector>
using namespace std;

// To Find Maximum Profit by Buying and Selling the Stock
int maxProfit(vector<int> &prices)
{
    int maxProfit = 0;
    int bestBuy = prices[0];

    for (int i = 1; i < prices.size(); i++)
    {
        int bestSell = prices[i];

        if (bestSell > bestBuy)
        {
           maxProfit = max(maxProfit, bestSell - bestBuy);
        }
        bestBuy = min(bestSell, bestBuy);
    }
    return maxProfit;
}

int main()
{
    vector<int> prices = {7, 6,5,4,3};

    cout << maxProfit(prices);

    return 0;
}
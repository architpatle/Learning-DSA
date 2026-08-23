#include <iostream>
#include <vector>
using namespace std;

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
        bestBuy = min(bestBuy, bestSell);
    }
    return maxProfit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << "Max Profit: " << maxProfit(prices);
    return 0;
}
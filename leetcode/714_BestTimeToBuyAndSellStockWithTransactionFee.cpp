#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        // table[0][i] := the max profit holding a stock at position i
        // table[1][i] := the max profit not holding a stock at position i
        vector<vector<int>> table(2, vector<int>(prices.size()));
        table[0][0] = 0;
        table[1][0] = -prices[0];

        for (int i = 1; i < prices.size(); i++)
        {
            table[0][i] = max(table[0][i - 1], table[1][i - 1] + prices[i] - fee);
            table[1][i] = max(table[1][i - 1], table[0][i - 1] - prices[i]);
        }

        return max(table[0][prices.size() - 1], table[1][prices.size() - 1]);
    }
};
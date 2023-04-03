#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        const int MAX = INT_MAX - 1;
        vector<int> dp(amount + 1, MAX);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if (i - coins[j] >= 0)
                {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        return (dp[amount] == MAX) ? -1 : dp[amount];
    }
};
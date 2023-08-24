#include <vector>
using namespace std;

class Solution
{
public:
    int maximizeTheProfit(int n, vector<vector<int>> &offers)
    {
        vector<int> dp(n + 1);
        vector<vector<vector<int>>> helper(n);

        for (auto &offer : offers)
        {
            helper[offer[1]].push_back(offer);
        }

        for (int i = 1; i <= n; i++)
        {
            dp[i] = dp[i - 1];
            for (auto &h : helper[i - 1])
            {
                dp[i] = max(dp[i], dp[h[0]] + h[2]);
            }
        }

        return dp[n];
    }
};
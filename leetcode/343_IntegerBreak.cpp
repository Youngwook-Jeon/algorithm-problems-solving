#include <algorithm>
using namespace std;

class Solution
{
public:
    int dp[59];

    int integerBreak(int n)
    {
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                // We should include the case where j is not decomposed.
                dp[i] = max(dp[i], max(dp[j] * (i - j), j * (i - j)));
            }
        }

        return dp[n];
    }
};
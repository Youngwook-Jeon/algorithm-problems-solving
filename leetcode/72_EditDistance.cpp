#include <string>
using namespace std;

class Solution
{
public:
    // dp[i][j] := the number of min ways for converting word1[i..] to word2[j..]
    int dp[501][501];

    int minDistance(string word1, string word2)
    {
        int n = word1.size(), m = word2.size();
        for (int i = 0; i <= m; i++)
        {
            dp[n][m - i] = i;
        }
        for (int i = 0; i <= n; i++)
        {
            dp[n - i][m] = i;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (word1[i] == word2[j])
                {
                    dp[i][j] = dp[i + 1][j + 1];
                }
                else
                {
                    dp[i][j] = min(min(1 + dp[i + 1][j + 1], 1 + dp[i][j + 1]), 1 + dp[i + 1][j]);
                }
            }
        }

        return dp[0][0];
    }
};
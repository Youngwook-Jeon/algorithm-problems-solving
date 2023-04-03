#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int dp[501][501];

    int minDistance(string word1, string word2)
    {
        int n = word1.size(), m = word2.size();

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (word1[i] == word2[j])
                {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return (n - dp[0][0]) + (m - dp[0][0]);
    }
};
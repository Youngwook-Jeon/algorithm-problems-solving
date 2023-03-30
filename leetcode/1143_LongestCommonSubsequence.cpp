#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int dp[1001][1001];

    int longestCommonSubsequence(string text1, string text2)
    {
        for (int j = text2.size() - 1; j >= 0; j--)
        {
            for (int i = text1.size() - 1; i >= 0; i--)
            {
                if (text1[i] == text2[j])
                {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[0][0];
    }
};
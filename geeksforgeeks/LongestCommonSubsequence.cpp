#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    // Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string str1, string str2)
    {
        // your code here
        vector<vector<int>> dp(n, vector<int>(m, -1));
        helper(dp, n - 1, m - 1, str1, str2);
        return dp[n - 1][m - 1];
    }

    int helper(vector<vector<int>> &dp, int n, int m, string &str1, string &str2)
    {
        if (n < 0 || m < 0)
            return 0;

        if (str1[n] == str2[m])
        {
            return dp[n][m] = 1 + helper(dp, n - 1, m - 1, str1, str2);
        }

        if (dp[n][m] != -1)
        {
            return dp[n][m];
        }

        return dp[n][m] = max(helper(dp, n - 1, m, str1, str2), helper(dp, n, m - 1, str1, str2));
    }
};
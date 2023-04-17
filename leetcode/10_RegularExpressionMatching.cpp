#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    // Solution1: Using recursion
    bool isMatch1(string s, string p)
    {
        int m = s.size(), n = p.size();
        vector<vector<int>> table(m + 1, vector<int>(n, -1));
        return dp(0, 0, s, p, table);
    }

    bool dp(int i, int j, string s, string p, vector<vector<int>> &table)
    {
        if (table[i][j] != -1)
            return table[i][j] == 1;

        bool ans = false;
        if (j == p.size())
        {
            return (i == s.size());
        }
        else
        {
            bool isFirstMatch = i < s.size() && (s[i] == p[j] || p[j] == '.');
            if (j + 1 < p.size() && p[j + 1] == '*')
            {
                ans = dp(i, j + 2, s, p, table) || (isFirstMatch && dp(i + 1, j, s, p, table));
            }
            else
            {
                ans = isFirstMatch && (dp(i + 1, j + 1, s, p, table));
            }
        }
        table[i][j] = (ans) ? 1 : 0;

        return ans;
    }

    // Solution2: Using tabulation
    bool isMatch2(string s, string p)
    {
        int m = s.size(), n = p.size();
        vector<vector<bool>> table(m + 1, vector<bool>(n + 1, false));
        table[m][n] = true;

        for (int i = m; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                bool isFirstMatch = i < m && (s[i] == p[j] || p[j] == '.');

                if (j + 1 < n && p[j + 1] == '*')
                {
                    table[i][j] = (table[i][j + 2]) || (isFirstMatch && table[i + 1][j]);
                }
                else
                {
                    table[i][j] = isFirstMatch && table[i + 1][j + 1];
                }
            }
        }

        return table[0][0];
    }
};
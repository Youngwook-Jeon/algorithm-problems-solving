#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool table[1000][1000];

    string longestPalindrome(string s)
    {
        int n = s.size();
        int maxLen = 1;
        pair<int, int> ij = make_pair(0, 0);

        for (int i = 0; i < n; i++)
        {
            table[i][i] = true;
            if (i < n - 1)
                table[i][i + 1] = (s[i] == s[i + 1]);
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i + 2; j < n; j++)
            {
                table[i][j] = (table[i + 1][j - 1] && s[i] == s[j]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (table[i][j])
                {
                    if (maxLen < (j - i + 1))
                    {
                        maxLen = j - i + 1;
                        ij = make_pair(i, j);
                    }
                }
            }
        }

        return s.substr(ij.first, maxLen);
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        unordered_set<string> us(wordDict.begin(), wordDict.end());
        vector<vector<string>> dp(n + 1);
        dp[n].push_back("");

        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i; j < n; j++)
            {
                string word = s.substr(i, j - i + 1);
                vector<string> validStrings = dp[j + 1];

                if (us.find(word) != us.end())
                {
                    if (j == n - 1)
                    {
                        dp[i].push_back(word);
                    }
                    else
                    {
                        for (auto vs : validStrings)
                        {
                            dp[i].push_back(word + " " + vs);
                        }
                    }
                }
            }
        }

        return dp[0];
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> us(words.begin(), words.end());
        vector<string> ans;
        for (string& word : words) {
            int sz = word.size();
            vector<bool> dp(sz + 1);
            dp[0] = true;

            for (int i = 1; i <= sz; ++i) {
                for (int j = (i == sz) ? 1 : 0; j < i; ++j) {
                    if (dp[i]) break;

                    dp[i] = dp[j] && us.count(word.substr(j, i - j));
                }
            }

            if (dp[sz]) ans.push_back(word);
        }

        return ans;
    }
};
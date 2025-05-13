#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n);
        int ans = 0;

        for (int i = 1; i < n; ++i) {
            if (s[i] == ')' && s[i - 1] == '(') {
                dp[i] = ((i >= 2) ?  dp[i - 2] + 2 : 2);
            } else if (s[i] == ')' && s[i - 1] == ')') {
                int left = i - dp[i - 1] - 1;
                if (left >= 0 && s[left] == '(') {
                    int alpha = ((left > 0) ? dp[left - 1] : 0);
                    dp[i] = dp[i - 1] + 2 + alpha;
                }
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
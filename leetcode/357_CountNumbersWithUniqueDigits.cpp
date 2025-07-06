#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            int x = 1, factor = 9;
            for (int j = 0; j < i; ++j) {
                if (j >= 2) factor--;
                x *= factor;
            }
            dp[i] = x + dp[i - 1];
        }

        return dp[n];
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        vector<int> ptrs(primes.size(), 1);
        for (int i = 2; i <= n; ++i) {
            long long local = LLONG_MAX;
            for (int j = 0; j < ptrs.size(); ++j) {
                local = min(local, (long long)dp[ptrs[j]] * primes[j]);
            }
            dp[i] = local;
            for (int j = 0; j < ptrs.size(); ++j) {
                if ((long long)dp[i] == (long long)dp[ptrs[j]] * primes[j]) ptrs[j]++;
            }
        }

        return dp[n];
    }
};
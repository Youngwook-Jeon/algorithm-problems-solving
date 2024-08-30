#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int len = s.size();
        string r = s;
        reverse(r.begin(), r.end());

        vector<vector<int>> dp(len + 1, vector<int>(len + 1));

        for (int i = 1; i <= len; i++) {
            for (int j = 1; j <= len; j++) {
                if (s[i - 1] == r[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        cout << dp[len][len] << '\n';
    }
    return 0;
}
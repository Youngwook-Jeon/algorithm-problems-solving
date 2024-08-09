#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const string T = "RPS";
const int MIN = -1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string s;
    cin >> n >> s;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = find(T.begin(), T.end(), s[i]) - T.begin();
    }

    vector<vector<int>> dp(n + 1, vector<int>(3, MIN));
    dp[0][0] = dp[0][1] = dp[0][2] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (j != k && k != (arr[i] + 2) % 3)
                {
                    if (k == (arr[i] + 1) % 3)
                    {
                        dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + 1);
                    }
                    else
                    {
                        dp[i + 1][k] = max(dp[i + 1][k], dp[i][j]);
                    }
                }
            }
        }
    }

    cout << max(dp[n][0], max(dp[n][1], dp[n][2]));

    return 0;
}
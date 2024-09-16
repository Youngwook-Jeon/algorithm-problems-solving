#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> H(n);
        for (int i = 0; i < n; i++)
        {
            cin >> H[i];
        }

        vector<vector<int>> lookup(n, vector<int>(50));

        // Preprocessing
        for (int i = 0; i < n; i++)
        {
            lookup[i][0] = H[i];
        }

        for (int j = 1; (1 << j) <= n; j++)
        {
            for (int i = 0; (i + (1 << j) - 1) < n; i++)
            {
                if (lookup[i][j - 1] > lookup[i + (1 << (j - 1))][j - 1])
                {
                    lookup[i][j] = lookup[i][j - 1];
                }
                else
                {
                    lookup[i][j] = lookup[i + (1 << (j - 1))][j - 1];
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--; // 0-based ind

            l++;
            r--;
            if (l > r)
            {
                ans++;
                continue;
            }

            // Querying
            int j = (int)log2(r - l + 1);
            int mx = max(lookup[l][j], lookup[r - (1 << j) + 1][j]);
            if (mx <= H[--l])
                ans++;
        }

        cout << ans << '\n';
    }
    return 0;
}
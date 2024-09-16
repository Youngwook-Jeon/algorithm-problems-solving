#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int queryMax(int l, int r, vector<vector<pii>> &lookup)
{
    int j = (int)log2(r - l + 1);
    return max(lookup[l][j].first, lookup[r - (1 << j) + 1][j].first);
}

int queryMin(int l, int r, vector<vector<pii>> &lookup)
{
    int j = (int)log2(r - l + 1);
    return min(lookup[l][j].second, lookup[r - (1 << j) + 1][j].second);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> A(n);
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }

        // pair => store (max, min) of an interval
        vector<vector<pii>> lookup(n, vector<pii>(50));

        // Preprocessing the look up table
        for (int i = 0; i < n; i++)
        {
            lookup[i][0] = make_pair(A[i], A[i]);
        }

        for (int j = 1; (1 << j) <= n; j++)
        {
            for (int i = 0; (i + (1 << j) - 1) < n; i++)
            {
                lookup[i][j].first = max(lookup[i][j - 1].first, lookup[i + (1 << (j - 1))][j - 1].first);
                lookup[i][j].second = min(lookup[i][j - 1].second, lookup[i + (1 << (j - 1))][j - 1].second);
            }
        }

        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            // Find the right most index satisfies the condition
            int low = i, high = n - 1;
            while (low < high)
            {
                int mid = (low + high + 1) / 2;
                if (queryMax(i, mid, lookup) - queryMin(i, mid, lookup) <= k)
                {
                    low = mid;
                }
                else
                {
                    high = mid - 1;
                }
            }

            ans += (high - i + 1);
        }

        cout << ans << '\n';
    }
}
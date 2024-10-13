#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, d, k;
        cin >> n >> d >> k;
        vector<int> vs(n + 1), ve(n + 1);
        for (int i = 0; i < k; i++)
        {
            int l, r;
            cin >> l >> r;
            vs[l]++;
            ve[r]++;
        }

        for (int i = 0; i < n; i++)
        {
            vs[i + 1] += vs[i];
            ve[i + 1] += ve[i];
        }

        int mx = -1;
        int mn = INT_MAX;
        int robert = 1, mrs = 1;
        for (int i = d; i <= n; i++)
        {
            int cnt = vs[i] - ve[i - d];
            if (cnt > mx)
            {
                mx = cnt;
                robert = i - d + 1;
            }
            if (cnt < mn)
            {
                mn = cnt;
                mrs = i - d + 1;
            }
        }

        cout << robert << ' ' << mrs << '\n';
    }

    return 0;
}
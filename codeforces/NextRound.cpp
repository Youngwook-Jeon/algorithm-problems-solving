#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    int ans = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int t = a[k - 1];

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0 || a[i] < t)
            continue;
        ans++;
    }

    cout << ans << '\n';
    return 0;
}
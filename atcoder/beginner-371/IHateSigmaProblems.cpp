#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int x, int n, unordered_map<int, vector<int>> &um)
{
    ll ans = 0;
    um[x].push_back(n + 1);
    for (int i = 1; i < um[x].size(); i++)
    {
        ll part = um[x][i] - um[x][i - 1] - 1;
        ans += part * (part + 1) / 2;
    }
    ans = ((ll)n) * (n + 1) / 2 - ans;

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> A(n + 2);
    unordered_map<int, vector<int>> um;
    for (int i = 1; i <= n; i++)
    {
        um[i].push_back(0);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
        um[A[i]].push_back(i);
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += solve(i, n, um);
    }

    cout << ans << '\n';

    return 0;
}
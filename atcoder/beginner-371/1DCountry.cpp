#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> x(n), p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    vector<ll> prefixSum(n + 1);
    for (int i = 1; i <= n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + p[i - 1];
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << prefixSum[upper_bound(x.begin(), x.end(), r) - x.begin()] - prefixSum[lower_bound(x.begin(), x.end(), l) - x.begin()] << '\n';
    }
    return 0;
}
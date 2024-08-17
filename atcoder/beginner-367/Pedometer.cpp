#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> v = {0};
    for (int i = 0; i < 2 * n; i++)
    {
        v.push_back((v.back() + arr[i % n]) % m);
    }

    vector<int> freq(m, 0);
    for (int i = 0; i < n; i++)
    {
        freq[v[i]]++;
    }
    ll ans = 0;
    for (int i = n; i < 2 * n; i++)
    {
        freq[v[i - n]]--;
        ans += freq[v[i]];
        freq[v[i]]++;
    }

    cout << ans << '\n';
    return 0;
}
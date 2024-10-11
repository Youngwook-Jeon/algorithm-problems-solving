#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k, w;
    ll n;
    cin >> k >> n >> w;

    ll needed = k * w * (w + 1) / 2;
    if (n >= needed)
    {
        cout << 0 << '\n';
    }
    else
    {
        cout << needed - n << '\n';
    }

    return 0;
}
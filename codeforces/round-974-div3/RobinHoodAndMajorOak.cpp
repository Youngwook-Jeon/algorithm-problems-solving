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
        ll n, k;
        cin >> n >> k;
        int ans = 0;
        if (n % 4 == 1 || n % 4 == 2)
            ans += 1;
        if ((n - k) % 4 == 1 || (n - k) % 4 == 2)
            ans += 1;

        if (ans % 2 == 0)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

    return 0;
}
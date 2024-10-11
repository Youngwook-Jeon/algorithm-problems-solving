#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll P, k;
        cin >> P >> k;
        string ans = "Geek";
        if (k % 3 == 0)
        {
            ll val = P % (k + 1);
            if (val % 3 == 0 && val != k)
                ans = "Geekina";
        }
        else
        {
            if (P % 3 == 0)
                ans = "Geekina";
        }
        cout << ans << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int p, q;
        cin >> p >> q;
        if (q - p >= 2)
            ans++;
    }

    cout << ans << '\n';

    return 0;
}
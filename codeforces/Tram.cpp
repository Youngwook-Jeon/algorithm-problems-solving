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
    int a, b;
    int cur = 0, ans = 0;
    while (n--)
    {
        cin >> a >> b;
        cur += (b - a);
        ans = max(ans, cur);
    }

    cout << ans << '\n';

    return 0;
}
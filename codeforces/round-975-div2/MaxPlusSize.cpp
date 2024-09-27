#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        int mx = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mx = max(mx, a[i]);
        }

        int ans = 0;
        if (n % 2 == 0)
        {
            ans = mx + (n + 1) / 2;
        }
        else
        {
            bool isEvenPos = false;
            for (int i = 0; i < n; i += 2)
            {
                if (a[i] == mx)
                {
                    isEvenPos = true;
                    break;
                }
            }

            if (isEvenPos)
                ans = mx + (n + 1) / 2;
            else
                ans = mx + n / 2;
        }

        cout << ans << '\n';
    }
    return 0;
}
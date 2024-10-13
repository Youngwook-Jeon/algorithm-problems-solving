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
        int n, k;
        cin >> n >> k;
        int take = 0;
        int give = 0;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            if (a >= k)
                take += a;
            if (a == 0 && take > 0)
            {
                give++;
                take--;
            }
        }

        cout << give << '\n';
    }

    return 0;
}
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
        int n, k;
        cin >> n >> k;
        vector<ll> freq(k);
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            ll val;
            cin >> val;
            freq[(int)(val % k)]++;
            sum += val;
        }

        if (freq[(int)(sum % k)] == 0)
        {
            cout << "Bob" << '\n';
            continue;
        }

        if (sum % k == 0)
        {
            if (freq[0] % 2 == 0)
            {
                cout << "Bob" << '\n';
            }
            else
            {
                cout << "Alice" << '\n';
            }
        }
        else
        {
            if (freq[0] % 2 == 0)
            {
                cout << "Alice" << '\n';
            }
            else
            {
                cout << "Bob" << '\n';
            }
        }
    }

    return 0;
}
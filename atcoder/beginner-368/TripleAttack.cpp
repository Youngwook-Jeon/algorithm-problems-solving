#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll t = 0;
    for (int i = 0; i < n; i++)
    {
        t += (v[i] / 5) * 3;
        v[i] %= 5;

        while (v[i] > 0)
        {
            t++;
            if (t % 3 == 0)
            {
                v[i] -= 3;
            }
            else
            {
                v[i]--;
            }
        }
    }

    cout << t << '\n';
    return 0;
}
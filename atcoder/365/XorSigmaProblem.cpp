#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);

    ll ans = 0, mult = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        ans -= arr[i];
    }

    for (int i = 0; i < 30; i++)
    {
        int cOdd = 0;
        bool odd = 0;

        for (int j = 0; j < n; j++)
        {
            if (arr[j] & (1 << i))
            {
                odd = !odd;
            }
            if (odd)
            {
                cOdd++;
            }
        }

        for (int j = 0; j < n; j++)
        {
            ans += (mult * cOdd);
            if (arr[j] & (1 << i))
                cOdd = (n - j - cOdd);
        }

        mult *= 2;
    }

    cout << ans << '\n';

    return 0;
}
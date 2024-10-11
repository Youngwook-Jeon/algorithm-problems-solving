#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    int k;
    cin >> n >> k;
    while (k--)
    {
        if (n % 10 == 0)
            n /= 10;
        else
            n -= 1;
    }

    cout << n << '\n';

    return 0;
}
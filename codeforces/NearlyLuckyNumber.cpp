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
    cin >> n;
    int digits = 0;
    while (n != 0)
    {
        if (n % 10 == 4 || n % 10 == 7)
            digits++;
        n /= 10;
    }

    if (digits == 4 || digits == 7)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';

    return 0;
}
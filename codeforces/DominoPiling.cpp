#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    if (m < n)
        swap(m, n);

    int res = m * (n / 2) + (n % 2) * (m / 2);
    cout << res << '\n';
    return 0;
}
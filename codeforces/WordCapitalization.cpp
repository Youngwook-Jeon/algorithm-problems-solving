#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    if (s[0] >= 'a')
        s = (char)(s[0] - 32) + s.substr(1);
    cout << s << '\n';

    return 0;
}
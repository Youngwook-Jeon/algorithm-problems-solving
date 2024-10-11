#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    int lowers = 0;
    for (char c : s)
    {
        if (c >= 'a' && c <= 'z')
            lowers++;
    }

    if (lowers >= s.size() - lowers)
        transform(s.begin(), s.end(), s.begin(), ::tolower);
    else
        transform(s.begin(), s.end(), s.begin(), ::toupper);

    cout << s << '\n';

    return 0;
}
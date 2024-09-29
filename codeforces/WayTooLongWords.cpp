#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;

        if (s.size() > 10) {
            s.replace(s.begin() + 1, s.end() - 1, to_string(s.size() - 2));
        }
        cout << s << '\n';
    }

    return 0;
}
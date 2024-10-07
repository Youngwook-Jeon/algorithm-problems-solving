#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    vector<int> vi;
    for (int i = 0; i < s.size(); i += 2)
    {
        vi.push_back(s[i] - '0');
    }
    string ans = "";
    sort(vi.begin(), vi.end());
    for (int i = 0; i < vi.size(); i++)
    {
        string last = "";
        if (i != vi.size() - 1)
        {
            last = "+";
        }
        ans = ans + to_string(vi[i]) + last;
    }

    cout << ans << '\n';
    return 0;
}
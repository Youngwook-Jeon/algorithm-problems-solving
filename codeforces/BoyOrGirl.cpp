#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    unordered_set<char> us;
    for (char c : s)
    {
        us.insert(c);
    }

    if (us.size() % 2 == 0)
    {
        cout << "CHAT WITH HER!" << '\n';
    }
    else
    {
        cout << "IGNORE HIM!" << '\n';
    }

    return 0;
}
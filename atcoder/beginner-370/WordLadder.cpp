#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s, t;
    cin >> s >> t;

    vector<int> arr;
    vector<string> ans;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] > t[i])
            arr.push_back(i);
    }

    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] < t[i])
            arr.push_back(i);
    }

    int cnt = arr.size();
    for (int i = 0; i < cnt; i++)
    {
        s[arr[i]] = t[arr[i]];
        ans.push_back(s);
    }

    cout << cnt << '\n';
    for (auto &word : ans)
    {
        cout << word << '\n';
    }

    return 0;
}
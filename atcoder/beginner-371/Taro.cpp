#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<bool> v(n + 1);
    vector<string> ans;

    for (int i = 1; i <= m; i++)
    {
        int ai;
        char bi;
        cin >> ai >> bi;
        if (bi == 'F')
        {
            ans.push_back("No");
            continue;
        }

        if (!v[ai])
        {
            ans.push_back("Yes");
            v[ai] = true;
        }
        else
        {
            ans.push_back("No");
        }
    }

    for (auto &s : ans)
    {
        cout << s << '\n';
    }
    return 0;
}
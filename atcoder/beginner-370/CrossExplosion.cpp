#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int h, w, q;
    cin >> h >> w >> q;
    // vs1[i] := the column indices remaining walls in ith row
    vector<set<int>> vs1(h + 1), vs2(w + 1);
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            vs1[i].insert(j);
            vs2[j].insert(i);
        }
    }

    auto erase = [&](int i, int j)
    {
        vs1[i].erase(j);
        vs2[j].erase(i);
    };

    while (q--)
    {
        int r, c;
        cin >> r >> c;

        if (vs1[r].find(c) != vs1[r].end())
        {
            erase(r, c);
            continue;
        }

        {
            auto it = vs2[c].lower_bound(r);
            if (it != vs2[c].begin())
                erase(*prev(it), c);
        }

        {
            auto it = vs2[c].lower_bound(r);
            if (it != vs2[c].end())
                erase(*it, c);
        }

        {
            auto it = vs1[r].lower_bound(c);
            if (it != vs1[r].begin())
                erase(r, *prev(it));
        }

        {
            auto it = vs1[r].lower_bound(c);
            if (it != vs1[r].end())
                erase(r, *it);
        }
    }

    int ans = 0;
    for (int i = 1; i <= h; i++)
    {
        ans += vs1[i].size();
    }

    cout << ans << '\n';

    return 0;
}
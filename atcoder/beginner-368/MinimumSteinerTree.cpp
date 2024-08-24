#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

bool solve(vector<vector<int>> &v, vector<bool> &visited, unordered_set<int> &us, int now)
{
    bool local = false;
    visited[now] = true;
    for (int next : v[now])
    {
        if (!visited[next])
        {
            local = local | solve(v, visited, us, next);
        }
    }

    if (us.find(now) != us.end())
        local = true;

    if (local)
        cnt++;
    return local;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n + 1);
    vector<bool> visited(n + 1);
    unordered_set<int> us;
    for (int i = 0; i < n - 1; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }

    for (int i = 0; i < k; i++)
    {
        int val;
        cin >> val;
        us.insert(val);
    }

    solve(v, visited, us, *us.begin());

    cout << cnt << '\n';
    return 0;
}
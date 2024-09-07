#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n + 1);
        vector<int> in(n + 1);
        vector<bool> visited(n + 1);
        vector<vector<int>> ans(n + 1);
        int semesters = 1;

        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            in[b]++;
        }

        queue<pii> q;
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (in[i] == 0)
            {
                cnt++;
                q.push({i, semesters});
            }
        }
        if (cnt == 0)
        {
            cout << "IMPOSSIBLE" << '\n';
            continue;
        }

        while (!q.empty())
        {
            pii p = q.front();
            int node = p.first;
            int sem = p.second;

            q.pop();

            visited[node] = true;
            semesters = max(semesters, sem);
            ans[sem].push_back(node);
            for (auto next : adj[node])
            {
                if (!visited[next])
                {
                    in[next]--;
                    if (in[next] == 0)
                        q.push({next, sem + 1});
                }
            }
        }

        bool flag = false;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                flag = true;
                break;
            }
        }

        if (flag)
        {
            cout << "IMPOSSIBLE" << '\n';
        }
        else
        {
            cout << semesters << '\n';
            for (int i = 1; i <= semesters; i++)
            {
                sort(ans[i].begin(), ans[i].end());
                for (int node : ans[i])
                {
                    cout << node << ' ';
                }
                cout << '\n';
            }
        }
    }
    return 0;
}
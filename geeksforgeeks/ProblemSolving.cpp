#include <bits/stdc++.h>
using namespace std;

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

        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            in[b]++;
        }

        queue<int> q;
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (in[i] == 0)
            {
                cnt++;
                q.push(i);
            }
        }
        if (cnt == 0)
        {
            cout << "NO" << '\n';
            continue;
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            visited[node] = true;
            for (auto next : adj[node])
            {
                if (!visited[next])
                {
                    in[next]--;
                    if (in[next] == 0)
                        q.push(next);
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

        cout << (flag ? "NO" : "YES") << '\n';
    }
    return 0;
}
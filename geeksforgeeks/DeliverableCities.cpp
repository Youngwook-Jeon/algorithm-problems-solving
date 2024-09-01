#include <bits/stdc++.h>
using namespace std;

void dfs(int v, vector<vector<int>> &adj, vector<bool> &visited)
{
    if (visited[v])
        return;

    visited[v] = true;
    for (auto next : adj[v])
    {
        dfs(next, adj, visited);
    }
}

void checkDeliverable(int v, vector<vector<int>> &adj, vector<bool> &visited, bool &deliverable)
{
    if (deliverable)
        return;

    if (v == 1)
    {
        deliverable = true;
        return;
    }

    if (visited[v])
        return;
    visited[v] = true;

    for (auto next : adj[v])
    {
        checkDeliverable(next, adj, visited, deliverable);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n + 1);
        vector<int> ans;
        vector<bool> visited(n + 1);

        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
        }

        dfs(1, adj, visited);

        for (int i = 1; i <= n; i++)
        {
            if (visited[i])
            {
                vector<bool> vis2(n + 1);
                bool deliverable = false;
                checkDeliverable(i, adj, vis2, deliverable);
                if (deliverable)
                    ans.push_back(i);
            }
        }

        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
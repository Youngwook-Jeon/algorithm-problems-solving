#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int node)
{
    visited[node] = true;
    for (int next : adj[node])
    {
        if (!visited[next])
            dfs(adj, visited, next);
    }
}

int main()
{
    // code
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
        vector<bool> visited(n + 1);

        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                dfs(adj, visited, i);
                ans++;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
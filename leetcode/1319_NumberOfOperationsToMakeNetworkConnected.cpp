#include <vector>
using namespace std;

class Solution
{
public:
    bool visited[100000];

    int makeConnected(int n, vector<vector<int>> &connections)
    {
        int m = connections.size();
        int ans = -1;
        int nComponents = 0;
        if (n - 1 > m)
            return ans;
        vector<vector<int>> adj(n);

        for (auto &edge : connections)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj);
                nComponents++;
            }
        }

        return nComponents - 1;
    }

    void dfs(int node, vector<vector<int>> &adj)
    {
        visited[node] = true;
        for (auto next : adj[node])
        {
            if (!visited[next])
            {
                dfs(next, adj);
            }
        }
    }
};
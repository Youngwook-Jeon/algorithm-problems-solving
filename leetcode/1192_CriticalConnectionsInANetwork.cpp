#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;

    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> graph(n);
        for (auto &edge : connections)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> discovery(n, -1);
        vector<int> parent(n, -1);
        vector<int> low(n, -1);

        for (int i = 0; i < n; i++)
        {
            if (discovery[i] == -1)
            {
                dfs(i, 0, discovery, parent, low, graph);
            }
        }

        return ans;
    }

    void dfs(int node, int time, vector<int> &discovery, vector<int> &parent, vector<int> &low, vector<vector<int>> &graph)
    {
        discovery[node] = time;
        low[node] = time;

        for (auto next : graph[node])
        {
            if (discovery[next] == -1)
            {
                parent[next] = node;
                dfs(next, time + 1, discovery, parent, low, graph);
                low[node] = min(low[node], low[next]);
                if (low[next] > discovery[node])
                {
                    ans.push_back({node, next});
                }
            }
            else
            {
                if (parent[node] != next)
                {
                    low[node] = min(low[node], discovery[next]);
                }
            }
        }
    }
};
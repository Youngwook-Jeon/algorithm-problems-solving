#include <vector>
using namespace std;

class Solution
{
public:
    bool leadsToDestination(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<vector<int>> graph(n);
        vector<int> visited(n, -1);

        for (auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
        }
        return dfs(source, graph, visited, destination);
    }

    bool dfs(int v, vector<vector<int>> &graph, vector<int> &visited, int destination)
    {
        if (graph[v].size() == 0)
            return v == destination;
        if (visited[v] != -1)
            return visited[v];
        visited[v] = 0;

        for (auto next : graph[v])
        {
            if (!dfs(next, graph, visited, destination))
                return false;
        }

        return visited[v] = 1;
    }
};
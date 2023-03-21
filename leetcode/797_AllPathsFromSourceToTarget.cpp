#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;
    int n;

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        n = graph.size() - 1;
        vector<int> v;

        dfs(graph, 0, v);
        return ans;
    }

    void dfs(vector<vector<int>> &graph, int node, vector<int> &v)
    {
        if (node == n)
        {
            v.push_back(node);
            ans.push_back(v);
            v.pop_back();
            return;
        }
        v.push_back(node);
        for (int next : graph[node])
        {
            dfs(graph, next, v);
        }
        v.pop_back();
    }
};
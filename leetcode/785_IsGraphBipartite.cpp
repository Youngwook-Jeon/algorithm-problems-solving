#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> table(n, -1);

        for (int i = 0; i < n; i++)
        {
            if (table[i] == -1)
            {
                if (!solve(i, graph, table))
                    return false;
            }
        }

        return true;
    }

    bool solve(int node, vector<vector<int>> &graph, vector<int> &table)
    {
        table[node] = 0;
        queue<int> q;
        q.push(node);

        while (!q.empty())
        {
            int cur = q.front();
            int curGroup = table[cur];
            q.pop();

            for (auto &next : graph[cur])
            {
                if (table[next] == -1)
                {
                    table[next] = (curGroup + 1) % 2;
                    q.push(next);
                }
                else if (table[next] == curGroup)
                    return false;
            }
        }

        return true;
    }
};
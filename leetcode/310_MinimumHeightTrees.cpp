#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 0)
            return {};
        else if (n == 1)
            return {0};

        vector<int> ans;
        vector<int> indegrees(n);
        vector<vector<int>> graph(n);

        for (auto &edge : edges)
        {
            int from = edge[0], to = edge[1];
            graph[from].push_back(to);
            graph[to].push_back(from);
            indegrees[from]++;
            indegrees[to]++;
        }

        queue<int> q;
        for (int i = 0; i < indegrees.size(); i++)
        {
            if (indegrees[i] == 1)
                q.push(i);
        }

        while (!q.empty())
        {
            ans.clear();
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                int node = q.front();
                q.pop();
                ans.push_back(node);

                for (auto &next : graph[node])
                {
                    indegrees[next]--;
                    if (indegrees[next] == 1)
                    {
                        q.push(next);
                    }
                }
            }
        }

        return ans;
    }
};
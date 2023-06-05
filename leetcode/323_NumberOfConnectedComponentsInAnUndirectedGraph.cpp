#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    int countComponents(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> um;
        vector<bool> visited(n, false);
        int ans = 0;

        for (auto &edge : edges)
        {
            um[edge[0]].push_back(edge[1]);
            um[edge[1]].push_back(edge[0]);
        }

        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                ans++;
                q.push(i);

                while (!q.empty())
                {
                    int v = q.front();
                    q.pop();
                    if (visited[v])
                        continue;
                    visited[v] = true;

                    for (auto next : um[v])
                    {
                        if (!visited[next])
                            q.push(next);
                    }
                }
            }
        }

        return ans;
    }
};
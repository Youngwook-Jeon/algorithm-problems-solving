#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int ans = -1;

    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        vector<vector<int>> graph(n);

        for (int i = 0; i < n; i++)
        {
            if (manager[i] != -1)
                graph[manager[i]].push_back(i);
        }

        queue<pair<int, int>> q;
        q.push({headID, informTime[headID]});

        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            int id = p.first;
            int time = p.second;
            ans = max(ans, time);

            for (auto next : graph[id])
            {
                q.push({next, informTime[next] + time});
            }
        }

        return ans;
    }
};
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

class Solution
{
public:
    unordered_map<int, vector<int>> graph;
    int n = 0;

    int maximumDetonation(vector<vector<int>> &bombs)
    {
        n = bombs.size();
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int ri = bombs[i][0], ci = bombs[i][1], di = bombs[i][2];
                int rj = bombs[j][0], cj = bombs[j][1];
                if ((ll)di * di >= (ll)(ri - rj) * (ri - rj) + (ll)(ci - cj) * (ci - cj))
                {
                    graph[i].push_back(j);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            ans = max(ans, bfs(i));
        }

        return ans;
    }

    int bfs(int node)
    {
        int ans = 0;
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(node);

        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            if (visited[v])
                continue;

            visited[v] = true;
            ans++;

            for (auto &next : graph[v])
            {
                if (!visited[next])
                    q.push(next);
            }
        }

        return ans;
    }
};
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    // Function to find the level of node X.
    int nodeLevel(int V, vector<int> adj[], int X)
    {
        // code here
        vector<bool> visited(V);
        queue<pair<int, int>> q;

        q.push({0, 0});
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            int node = p.first;
            int level = p.second;
            if (visited[node])
                continue;
            visited[node] = true;
            if (node == X)
                return level;

            for (int next : adj[node])
            {
                if (!visited[next])
                {
                    q.push({next, level + 1});
                }
            }
        }

        return -1;
    }
};
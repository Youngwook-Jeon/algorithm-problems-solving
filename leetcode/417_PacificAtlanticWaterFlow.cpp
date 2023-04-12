#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, 1, 0, -1};

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> ans;

        queue<pair<int, int>> pq;
        queue<pair<int, int>> aq;

        for (int i = 0; i < n; i++)
        {
            pq.push({0, i});
            aq.push({m - 1, i});
        }

        for (int i = 0; i < m; i++)
        {
            pq.push({i, 0});
            aq.push({i, n - 1});
        }

        auto pv = bfs(pq, heights);
        auto av = bfs(aq, heights);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pv[i][j] && av[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }

    vector<vector<bool>> bfs(queue<pair<int, int>> &q, vector<vector<int>> &heights)
    {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> ans(m, vector<bool>(n, false));

        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            int r = p.first;
            int c = p.second;
            ans[r][c] = true;

            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                if (ans[nr][nc])
                    continue;

                if (heights[r][c] > heights[nr][nc])
                    continue;

                q.push({nr, nc});
            }
        }

        return ans;
    }
};
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int shortestPathAllKeys(vector<string> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int dist = 0, keys = 0;

        int dr[4] = {1, 0, -1, 0};
        int dc[4] = {0, 1, 0, -1};

        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(64)));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '@')
                {
                    q.push({i * n + j, 0});
                    visited[i][j][0] = true;
                }

                if (grid[i][j] >= 'a' && grid[i][j] <= 'z')
                    keys++;
            }
        }

        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                auto p = q.front();
                q.pop();
                int r = p.first / n, c = p.first % n;
                int state = p.second;

                if (state == (1 << keys) - 1)
                    return dist;

                for (int j = 0; j < 4; j++)
                {
                    int nr = r + dr[j];
                    int nc = c + dc[j];
                    int nextState = state;

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] == '#')
                        continue;

                    if (grid[nr][nc] >= 'a' && grid[nr][nc] <= 'z')
                    {
                        nextState = state | (1 << (grid[nr][nc] - 'a'));
                    }
                    else if (grid[nr][nc] >= 'A' && grid[nr][nc] <= 'Z')
                    {
                        if (!(nextState & (1 << (grid[nr][nc] - 'A'))))
                            continue;
                    }

                    if (!visited[nr][nc][nextState])
                    {
                        visited[nr][nc][nextState] = true;
                        q.push({nr * n + nc, nextState});
                    }
                }
            }

            dist++;
        }

        return -1;
    }
};
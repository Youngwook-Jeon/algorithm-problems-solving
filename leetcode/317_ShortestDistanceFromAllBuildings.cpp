#include <vector>
#include <climits>
#include <queue>
using namespace std;

class Solution
{
public:
    int m = 0, n = 0, totalBuildings = 0;
    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, 1, 0, -1};

    int shortestDistance(vector<vector<int>> &grid)
    {
        int minDist = INT_MAX;
        m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    totalBuildings++;
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    minDist = min(minDist, bfs(i, j, grid));
                }
            }
        }

        if (minDist == INT_MAX)
            return -1;

        return minDist;
    }

    int bfs(int r, int c, vector<vector<int>> &grid)
    {
        int distSum = 0;
        int reached = 0;
        int level = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({r, c});
        visited[r][c] = true;

        while (!q.empty() && reached != totalBuildings)
        {
            for (int i = q.size(); i > 0; i--)
            {
                auto p = q.front();
                q.pop();

                int nowR = p.first;
                int nowC = p.second;
                if (grid[nowR][nowC] == 1)
                {
                    distSum += level;
                    reached++;
                    continue;
                }

                for (int i = 0; i < 4; i++)
                {
                    int nextR = nowR + dr[i];
                    int nextC = nowC + dc[i];

                    if (nextR >= 0 && nextR < m && nextC >= 0 && nextC < n)
                    {
                        if (!visited[nextR][nextC] && grid[nextR][nextC] != 2)
                        {
                            visited[nextR][nextC] = true;
                            q.push({nextR, nextC});
                        }
                    }
                }
            }
            level++;
        }

        if (reached != totalBuildings)
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] == 0 && visited[i][j])
                        grid[i][j] = 2;
                }
            }

            return INT_MAX;
        }

        return distSum;
    }
};
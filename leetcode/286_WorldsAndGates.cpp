#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void wallsAndGates(vector<vector<int>> &rooms)
    {
        const int GATE = 0;
        const int EMPTY = INT_MAX;

        int dr[4] = {1, 0, -1, 0};
        int dc[4] = {0, 1, 0, -1};
        int m = rooms.size(), n = rooms[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (rooms[i][j] == GATE)
                {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            int r = p.first;
            int c = p.second;

            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && rooms[nr][nc] == EMPTY)
                {
                    rooms[nr][nc] = rooms[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
};
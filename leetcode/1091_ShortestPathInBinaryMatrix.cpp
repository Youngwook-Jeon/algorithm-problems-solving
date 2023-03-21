#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    bool visited[100][100];

    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int ans = -1;
        if (grid[0][0] == 1)
            return -1;

        int dr[8] = {1, 1, 0, -1, -1, -1, 0, 1};
        int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

        queue<tuple<int, int, int>> q;
        q.push(make_tuple(0, 0, 1));

        while (!q.empty())
        {
            tuple t = q.front();
            q.pop();

            int r = get<0>(t);
            int c = get<1>(t);
            int d = get<2>(t);
            if (visited[r][c])
                continue;
            visited[r][c] = true;
            if (r == grid.size() - 1 && c == grid[0].size() - 1)
            {
                ans = d;
                break;
            }

            for (int i = 0; i < 8; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && !visited[nr][nc] && grid[nr][nc] == 0)
                {
                    q.push(make_tuple(nr, nc, d + 1));
                }
            }
        }

        return (visited[grid.size() - 1][grid[0].size() - 1]) ? ans : -1;
    }
};
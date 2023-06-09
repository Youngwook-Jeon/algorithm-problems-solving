#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int m, n;
    vector<vector<bool>> visited;
    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, 1, 0, -1};

    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
    {
        m = maze.size(), n = maze[0].size();
        visited.resize(m, vector<bool>(n, false));
        pair<int, int> s{start[0], start[1]};
        pair<int, int> d{destination[0], destination[1]};
        queue<pair<int, int>> q;
        q.push(s);

        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            int r = p.first;
            int c = p.second;
            visited[r][c] = true;

            for (int i = 0; i < 4; i++)
            {
                auto next = move(r, c, i, maze);
                if (next.first == d.first && next.second == d.second)
                    return true;
                if (!visited[next.first][next.second])
                    q.push(next);
            }
        }

        return false;
    }

    pair<int, int> move(int r, int c, int i, vector<vector<int>> &maze)
    {
        int m = maze.size(), n = maze[0].size();
        int nr = r, nc = c;
        if (i == 0)
        {
            for (int i = r + 1; i < m; i++)
            {
                if (maze[i][nc] == 1)
                    break;
                nr = i;
            }
        }
        else if (i == 1)
        {
            for (int i = c + 1; i < n; i++)
            {
                if (maze[nr][i] == 1)
                    break;
                nc = i;
            }
        }
        else if (i == 2)
        {
            for (int i = r - 1; i >= 0; i--)
            {
                if (maze[i][nc] == 1)
                    break;
                nr = i;
            }
        }
        else
        {
            for (int i = c - 1; i >= 0; i--)
            {
                if (maze[nr][i] == 1)
                    break;
                nc = i;
            }
        }

        return {nr, nc};
    }
};
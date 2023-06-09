#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    vector<vector<bool>> visited;
    set<pair<int, int>> curIsland;
    int curRowRoot, curColRoot;
    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, 1, 0, -1};

    int numDistinctIslands(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        visited.resize(m, vector<bool>(n, false));
        set<set<pair<int, int>>> islands;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != 0 && !visited[i][j])
                {
                    curIsland.clear();
                    curRowRoot = i;
                    curColRoot = j;
                    dfs(i, j, grid);
                    islands.insert(curIsland);
                }
            }
        }

        return islands.size();
    }

    void dfs(int r, int c, vector<vector<int>> &grid)
    {
        visited[r][c] = true;
        curIsland.insert({r - curRowRoot, c - curColRoot});
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == 1 && !visited[nr][nc])
            {
                dfs(nr, nc, grid);
            }
        }
    }
};
#include <vector>
using namespace std;

class Solution {
public:
    bool visited[300][300];
    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, 1, 0, -1};

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }

    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (visited[r][c]) return;
        visited[r][c] = true;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && 
            grid[nr][nc] == '1' && !visited[nr][nc]) {
                dfs(grid, nr, nc);
            }
        }
    }
};
#include <vector>
using namespace std;

class Solution
{
public:
    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, 1, 0, -1};
    int m, n;
    bool visited[200][200];

    void solve(vector<vector<char>> &board)
    {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isOnBorder(i, j) && board[i][j] == 'O')
                    dfs(board, i, j);
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }

    void dfs(vector<vector<char>> &board, int r, int c)
    {
        if (visited[r][c])
            return;
        visited[r][c] = true;

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] && board[nr][nc] == 'O')
                dfs(board, nr, nc);
        }
    }

    bool isOnBorder(int r, int c)
    {
        if (r == m - 1 || r == 0 || c == 0 || c == n - 1)
            return true;
        return false;
    }
};
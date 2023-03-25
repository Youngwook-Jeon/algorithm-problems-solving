#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool visited[6][6];
    bool result;
    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, 1, 0, -1};

    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0])
                {
                    visited[i][j] = true;
                    backtrack(1, i, j, board, word);
                    visited[i][j] = false;
                }

                if (result)
                    return true;
            }
        }

        return false;
    }

    void backtrack(int cur, int r, int c, vector<vector<char>> &board, string word)
    {
        if (cur == word.size())
        {
            result = true;
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size() && !visited[nr][nc] && word[cur] == board[nr][nc])
            {
                visited[nr][nc] = true;
                backtrack(cur + 1, nr, nc, board, word);
                visited[nr][nc] = false;
            }
        }
    }
};
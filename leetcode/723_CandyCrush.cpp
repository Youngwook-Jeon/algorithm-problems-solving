#include <vector>
#include <cstdlib>
using namespace std;

class Solution
{
public:
    vector<vector<int>> candyCrush(vector<vector<int>> &board)
    {
        int m = board.size(), n = board[0].size();
        bool hasNextProcess = false;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n - 2; j++)
            {
                int curCandy = abs(board[i][j]);
                if (curCandy != 0 && abs(board[i][j + 1]) == curCandy && abs(board[i][j + 2]) == curCandy)
                {
                    board[i][j] = -curCandy;
                    board[i][j + 1] = -curCandy;
                    board[i][j + 2] = -curCandy;
                    hasNextProcess = true;
                }
            }
        }

        for (int i = 0; i < m - 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int curCandy = abs(board[i][j]);
                if (curCandy != 0 && abs(board[i + 1][j]) == curCandy && abs(board[i + 2][j]) == curCandy)
                {
                    board[i][j] = -curCandy;
                    board[i + 1][j] = -curCandy;
                    board[i + 2][j] = -curCandy;
                    hasNextProcess = true;
                }
            }
        }

        if (!hasNextProcess)
            return board;

        for (int j = 0; j < n; j++)
        {
            int fillRow = m - 1;
            for (int i = m - 1; i >= 0; i--)
            {
                if (board[i][j] > 0)
                    board[fillRow--][j] = board[i][j];
            }

            while (fillRow >= 0)
            {
                board[fillRow--][j] = 0;
            }
        }

        return candyCrush(board);
    }
};
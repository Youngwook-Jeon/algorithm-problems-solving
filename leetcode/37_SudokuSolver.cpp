#include <vector>
using namespace std;

class Solution
{
public:
    const static int n = 3;
    const static int N = n * n;

    int rowsFreq[N][N + 1]; // rowsFreq[i][d] := if d is in row i => 1, else => 0
    int colsFreq[N][N + 1];
    int boxes[N][N + 1];
    bool isSolved = false;

    void solveSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                char num = board[i][j];
                if (num != '.')
                {
                    writeANumToBoard(num - '0', i, j, board);
                }
            }
        }

        backtrack(0, 0, board);
    }

    void writeANumToBoard(int num, int r, int c, vector<vector<char>> &board)
    {
        int ind = (r / n) * n + c / n;

        rowsFreq[r][num]++;
        colsFreq[c][num]++;
        boxes[ind][num]++;
        board[r][c] = (char)(num + '0');
    }

    void writeOnNextSpace(int r, int c, vector<vector<char>> &board)
    {
        if (r == N - 1 && c == N - 1)
        {
            isSolved = true;
            return;
        }

        if (c == N - 1)
            backtrack(r + 1, 0, board);
        else
            backtrack(r, c + 1, board);
    }

    void removeANum(int num, int r, int c, vector<vector<char>> &board)
    {
        int ind = (r / n) * n + c / n;

        rowsFreq[r][num]--;
        colsFreq[c][num]--;
        boxes[ind][num]--;
        board[r][c] = '.';
    }

    bool canWriteANum(int num, int r, int c)
    {
        int ind = (r / n) * n + c / n;

        return rowsFreq[r][num] + colsFreq[c][num] + boxes[ind][num] == 0;
    }

    void backtrack(int r, int c, vector<vector<char>> &board)
    {
        if (board[r][c] == '.')
        {
            for (int i = 1; i <= 9; i++)
            {
                if (canWriteANum(i, r, c))
                {
                    writeANumToBoard(i, r, c, board);
                    writeOnNextSpace(r, c, board);
                    if (!isSolved)
                        removeANum(i, r, c, board);
                }
            }
        }
        else
        {
            writeOnNextSpace(r, c, board);
        }
    }
};
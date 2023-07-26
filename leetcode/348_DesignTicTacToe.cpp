#include <vector>
#include <algorithm>
using namespace std;

class TicTacToe
{
public:
    int n;
    vector<pair<int, int>> rows, cols, diags;
    TicTacToe(int n) : n(n)
    {
        rows.resize(n);
        cols.resize(n);
        diags.resize(2);
    }

    int move(int row, int col, int player)
    {
        auto &rMarked = rows[row];
        auto &cMarked = cols[col];
        if (player == 1)
        {
            rMarked.first += 1;
            cMarked.first += 1;
            if (row == col)
            {
                diags[0].first += 1;
            }

            if (row + col == n - 1)
            {
                diags[1].first += 1;
            }
            if (rMarked.first == n || cMarked.first == n || diags[0].first == n || diags[1].first == n)
                return 1;
        }
        else
        {
            rMarked.second += 1;
            cMarked.second += 1;
            if (row == col)
            {
                diags[0].second += 1;
            }

            if (row + col == n - 1)
            {
                diags[1].second += 1;
            }
            if (rMarked.second == n || cMarked.second == n || diags[0].second == n || diags[1].second == n)
                return 2;
        }

        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
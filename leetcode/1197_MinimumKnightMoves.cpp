#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    unordered_map<string, int> table;

    int minKnightMoves(int x, int y)
    {
        return dp(abs(x), abs(y));
    }

    int dp(int x, int y)
    {
        string s = to_string(x) + "," + to_string(y);
        if (table.find(s) != table.end())
            return table[s];

        if (x + y == 0)
            return 0;
        else if (x + y == 2)
            return 2;
        else
        {
            int curDist = min(dp(abs(x - 2), abs(y - 1)), dp(abs(x - 1), abs(y - 2))) + 1;
            table[s] = curDist;
            return table[s];
        }
    }
};
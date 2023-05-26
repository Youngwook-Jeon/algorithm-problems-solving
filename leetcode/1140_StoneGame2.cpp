#include <vector>
#include <climits>
#include <algorithm>
#include <functional>
using namespace std;

class Solution
{
public:
    int stoneGameII(vector<int> &piles)
    {
        int n = piles.size();
        vector<vector<vector<int>>> table(2, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));

        function<int(int, int, int)> fn = [&](int t, int i, int m) -> int
        {
            if (i == n)
                return 0;

            if (table[t][i][m] != -1)
                return table[t][i][m];

            int res = (t == 1) ? INT_MAX : -1;
            int s = 0;
            for (int x = 1; x <= min(2 * m, n - i); x++)
            {
                s += piles[i + x - 1];
                if (t == 0)
                    res = max(res, s + fn(1, i + x, max(x, m)));
                else
                    res = min(res, fn(0, i + x, max(x, m)));
            }

            return table[t][i][m] = res;
        };

        return fn(0, 0, 1);
    }
};
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int minCost(vector<vector<int>> &costs)
    {
        int n = costs.size();
        vector<vector<int>> table(n + 1, vector<int>(3));
        table[1] = costs[0];
        for (int i = 2; i <= n; i++)
        {
            for (int k = 0; k < 3; k++)
            {
                int k1 = (k + 1) % 3;
                int k2 = (k + 2) % 3;
                table[i][k] = min(table[i - 1][k1], table[i - 1][k2]) + costs[i - 1][k];
            }
        }

        return min(table[n][0], min(table[n][1], table[n][2]));
    }
};
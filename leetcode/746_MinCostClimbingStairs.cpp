#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int table[1001];

    int minCostClimbingStairs(vector<int> &cost)
    {
        for (int i = 2; i <= cost.size(); i++)
        {
            table[i] = min(table[i - 1] + cost[i - 1], table[i - 2] + cost[i - 2]);
        }

        return table[cost.size()];
    }
};
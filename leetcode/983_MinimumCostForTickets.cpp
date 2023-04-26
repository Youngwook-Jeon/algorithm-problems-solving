#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    vector<int> table;
    int timeunit[3] = {1, 7, 30};

    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int n = days.size();
        table.resize(n + 1);

        for (int i = 1; i <= n; i++)
        {
            int cur = days[i - 1];
            int localRes = INT_MAX;
            for (int j = 0; j < 3; j++)
            {
                int prev = i - 1;
                if (cur - timeunit[j] <= 0)
                {
                    prev = 0;
                    localRes = min(localRes, costs[j]);
                }
                else
                {
                    while (prev >= 0 && cur - days[prev] < timeunit[j])
                        prev--;
                    localRes = min(localRes, table[prev + 1] + costs[j]);
                }
            }

            table[i] = localRes;
        }

        return table[n];
    }
};
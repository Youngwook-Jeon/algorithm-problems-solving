#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
    int maxA(int n)
    {
        vector<int> table(n + 1);
        iota(table.begin() + 1, table.end(), 1);

        for (int i = 6; i <= n; i++)
        {
            for (int j = 3; j <= 6; j++)
            {
                table[i] = max(table[i], table[i - j] * (j - 1));
            }
        }

        return table[n];
    }
};
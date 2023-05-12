#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long mostPoints(vector<vector<int>> &questions)
    {
        int m = questions.size();
        vector<long long> table(m + 1, 0LL);
        table[m - 1] = questions[m - 1][0];

        for (int i = m - 2; i >= 0; i--)
        {
            auto &question = questions[i];
            int point = question[0], bp = question[1];
            int prev = (i + bp + 1 >= m) ? m : i + bp + 1;
            table[i] = max(point + table[prev], table[i + 1]);
        }

        return table[0];
    }
};
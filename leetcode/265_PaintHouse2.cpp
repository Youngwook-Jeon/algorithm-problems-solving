#include <vector>
using namespace std;

class Solution
{
public:
    int minCostII(vector<vector<int>> &costs)
    {
        int n = costs.size();
        int k = costs[0].size();
        int prevMin = -1, prevSecondMin = -1, prevMinColor = -1;

        for (int i = 0; i < k; i++)
        {
            int cost = costs[0][i];
            if (prevMin == -1 || cost < prevMin)
            {
                prevSecondMin = prevMin;
                prevMin = cost;
                prevMinColor = i;
            }
            else if (prevSecondMin == -1 || cost < prevSecondMin)
            {
                prevSecondMin = cost;
            }
        }

        for (int i = 1; i < n; i++)
        {
            int min = -1, secondMin = -1, minColor = -1;
            for (int color = 0; color < k; color++)
            {
                int cost = costs[i][color];

                if (color == prevMinColor)
                {
                    cost += prevSecondMin;
                }
                else
                {
                    cost += prevMin;
                }

                if (min == -1 || cost < min)
                {
                    secondMin = min;
                    minColor = color;
                    min = cost;
                }
                else if (secondMin == -1 || cost < secondMin)
                {
                    secondMin = cost;
                }
            }

            prevMin = min, prevSecondMin = secondMin, prevMinColor = minColor;
        }

        return prevMin;
    }
};
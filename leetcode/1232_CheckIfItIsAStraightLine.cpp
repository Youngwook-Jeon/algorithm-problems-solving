#include <vector>
using namespace std;

class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        auto v1 = coordinates[0];
        auto v2 = coordinates.back();

        int xDiff = v2[0] - v1[0];
        int yDiff = v2[1] - v1[1];

        for (auto &coord : coordinates)
        {
            int diff1 = coord[0] - v1[0];
            int diff2 = coord[1] - v1[1];
            if (xDiff * diff2 - yDiff * diff1 != 0)
                return false;
        }

        return true;
    }
};
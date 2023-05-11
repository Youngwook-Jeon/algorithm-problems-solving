#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> table;

    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        table.resize(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, nums1, nums2);
    }

    int solve(int i, int j, vector<int> &nums1, vector<int> &nums2)
    {
        if (i < 0 || j < 0)
            return 0;
        if (table[i][j] != -1)
            return table[i][j];

        if (nums1[i] == nums2[j])
        {
            table[i][j] = 1 + solve(i - 1, j - 1, nums1, nums2);
        }
        else
        {
            table[i][j] = max(solve(i - 1, j, nums1, nums2), solve(i, j - 1, nums1, nums2));
        }

        return table[i][j];
    }
};
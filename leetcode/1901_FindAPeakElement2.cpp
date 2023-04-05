#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        int l = 0, h = n - 1;
        int maxRowInd = 0;
        vector<int> ans(2);

        while (l < h)
        {
            int mid = (h - l) / 2 + l;
            maxRowInd = findMaxInd(mat, mid);
            if (mid > 0 && mat[maxRowInd][mid] < mat[maxRowInd][mid - 1])
            {
                h = mid - 1;
            }
            else if (mid < n - 1 && mat[maxRowInd][mid] < mat[maxRowInd][mid + 1])
            {
                l = mid + 1;
            }
            else
            {
                ans[0] = maxRowInd;
                ans[1] = mid;
                return ans;
            }
        }

        maxRowInd = findMaxInd(mat, l);
        ans[0] = maxRowInd;
        ans[1] = l;
        return ans;
    }

    int findMaxInd(vector<vector<int>> &mat, int col)
    {
        int ans = 0;
        int cur = mat[0][col];
        for (int i = 1; i < mat.size(); i++)
        {
            if (cur < mat[i][col])
            {
                ans = i;
                cur = mat[i][col];
            }
        }

        return ans;
    }
};
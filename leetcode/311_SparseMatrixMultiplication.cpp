#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> multiply(vector<vector<int>> &mat1, vector<vector<int>> &mat2)
    {
        int m = mat1.size(), k = mat1[0].size(), n = mat2[0].size();

        auto ca = compressMat(mat1);
        auto cb = compressMat(mat2);

        vector<vector<int>> ans(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (auto &[val1, mat1Col] : ca[i])
            {
                for (auto &[val2, j] : cb[mat1Col])
                {
                    ans[i][j] += val1 * val2;
                }
            }
        }

        return ans;
    }

    vector<vector<pair<int, int>>> compressMat(vector<vector<int>> &mat)
    {
        int r = mat.size(), c = mat[0].size();
        vector<vector<pair<int, int>>> ans(r);

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (mat[i][j] != 0)
                {
                    ans[i].push_back({mat[i][j], j});
                }
            }
        }

        return ans;
    }
};
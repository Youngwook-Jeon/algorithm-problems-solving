#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> getFactors(int n)
    {
        vector<int> factors{n};
        vector<vector<int>> ans;
        dfs(factors, ans);

        return ans;
    }

    void dfs(vector<int> &factors, vector<vector<int>> &ans)
    {
        if (factors.size() > 1)
        {
            ans.push_back(factors);
        }

        int last = factors.back();
        factors.pop_back();
        for (int i = factors.empty() ? 2 : factors.back(); i * i <= last; i++)
        {
            if (last % i == 0)
            {
                factors.push_back(i);
                factors.push_back(last / i);

                dfs(factors, ans);

                factors.pop_back();
                factors.pop_back();
            }
        }
        factors.push_back(last);
    }
};
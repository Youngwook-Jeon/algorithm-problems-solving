#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
    {
        vector<bool> incoming(n, false);
        vector<int> ans;

        for (auto &edge : edges)
        {
            incoming[edge[1]] = true;
        }

        for (int i = 0; i < n; i++)
        {
            if (!incoming[i])
                ans.push_back(i);
        }

        return ans;
    }
};
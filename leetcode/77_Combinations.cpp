#include <vector>
using namespace std;

class Solution
{
public:
  vector<vector<int>> ans;
  vector<int> cur;

  vector<vector<int>> combine(int n, int k)
  {
    dfs(n, k, 0);
    return ans;
  }

  void dfs(int n, int k, int pos)
  {
    if (cur.size() == k)
    {
      ans.push_back(cur);
      return;
    }

    for (int i = pos + 1; i <= n; i++)
    {
      cur.push_back(i);
      dfs(n, k, i);
      cur.pop_back();
    }
  }
};
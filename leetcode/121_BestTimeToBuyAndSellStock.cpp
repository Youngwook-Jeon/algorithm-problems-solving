#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int ans = 0;
    int minVal = prices[0];
    for (int i = 1; i < prices.size(); i++)
    {
      int temp = (prices[i] - minVal > 0) ? prices[i] - minVal : 0;
      ans = max(ans, temp);
      minVal = min(minVal, prices[i]);
    }

    return ans;
  }
};
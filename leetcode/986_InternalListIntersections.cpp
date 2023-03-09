#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
  {
    int i = 0, j = 0;
    vector<vector<int>> ans;
    while (i < firstList.size() && j < secondList.size())
    {
      int first = max(firstList[i][0], secondList[j][0]);
      int last = min(firstList[i][1], secondList[j][1]);
      if (first <= last)
      {
        ans.push_back({first, last});
      }

      if (firstList[i][1] >= secondList[j][1])
        j++;
      else
        i++;
    }

    return ans;
  }
};
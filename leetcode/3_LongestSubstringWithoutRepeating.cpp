#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    int ans = 0;
    int i, j;
    unordered_map<char, int> mp;

    for (i = 0, j = 0; j < s.size(); j++)
    {
      if (mp[s[j]] > 0)
      {
        i = max(i, mp[s[j]]);
      }
      ans = max(ans, j - i + 1);
      mp[s[j]] = j + 1;
    }

    return ans;
  }
};
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
  int sArr[26];
  int pArr[26];

  vector<int> findAnagrams(string s, string p)
  {
    vector<int> ans;
    if (s.size() < p.size())
      return ans;
    makeFrequencyArr(s, 0, p.size() - 1, sArr);
    makeFrequencyArr(p, 0, p.size() - 1, pArr);
    if (isAnagram())
      ans.push_back(0);

    for (int i = 1; i < s.size() - p.size() + 1; i++)
    {
      sArr[s[i - 1] - 'a']--;
      sArr[s[i + p.size() - 1] - 'a']++;
      if (isAnagram())
        ans.push_back(i);
    }

    return ans;
  }

  void makeFrequencyArr(string s, int start, int end, int arr[])
  {
    for (int i = start; i <= end; i++)
    {
      arr[s[i] - 'a']++;
    }
  }

  bool isAnagram()
  {
    for (int i = 0; i < 26; i++)
    {
      if (sArr[i] != pArr[i])
        return false;
    }

    return true;
  }
};
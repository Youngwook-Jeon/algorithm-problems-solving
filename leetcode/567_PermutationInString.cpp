#include <iostream>
using namespace std;

class Solution
{
public:
  bool checkInclusion(string s1, string s2)
  {
    if (s1.size() > s2.size())
      return false;

    int s1Map[26]{0};
    int s2Map[26]{0};
    for (int i = 0; i < s1.size(); i++)
    {
      s1Map[s1[i] - 'a'] += 1;
      s2Map[s2[i] - 'a'] += 1;
    }

    for (int i = 0; i < s2.size() - s1.size(); i++)
    {
      if (isMatching(s1Map, s2Map))
        return true;

      // cout << "s1: " << '\n';
      // printState(s1Map);
      // cout << "s2: " << '\n';
      // printState(s2Map);
      s2Map[s2[i + s1.size()] - 'a'] += 1;
      s2Map[s2[i] - 'a'] -= 1;
    }

    return isMatching(s1Map, s2Map);
  }

  bool isMatching(int arr1[], int arr2[])
  {
    for (int i = 0; i < 26; i++)
    {
      if (arr1[i] != arr2[i])
        return false;
    }
    return true;
  }

  void printState(int arr[])
  {
    string s = "{";
    for (int i = 0; i < 26; i++)
    {
      s = s + to_string(arr[i]) + ", ";
    }
    s += "}";
    cout << s << '\n';
  }
};

int main()
{
  Solution s;
  string s1 = "ab";
  string s2 = "eidbaooo";
  cout << s.checkInclusion(s1, s2) << '\n';

  return 0;
}
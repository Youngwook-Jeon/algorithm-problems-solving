#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
  vector<string> ans;

  vector<string> letterCasePermutation(string s)
  {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    backtrack(s, "");
    return ans;
  }

  void backtrack(const string &s, string state)
  {
    int n = state.length();
    if (n == s.length())
    {
      ans.push_back(state);
      return;
    }

    if (s[n] - 'a' >= 0)
    {
      state = state + s[n];
      backtrack(s, state);
      state = state.substr(0, n);

      state = state + (char)(s[n] - 32);
      backtrack(s, state);
      state = state.substr(0, n);
    }
    else
    {
      state = state + s[n];
      backtrack(s, state);
      state = state.substr(0, n);
    }
  }
};
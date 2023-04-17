#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<string> removeInvalidParentheses(string s)
    {
        unordered_set<string> ans;
        int leftRemoved = 0;
        int rightRemoved = 0;

        for (auto c : s)
        {
            if (c == '(')
            {
                leftRemoved++;
            }
            else if (c == ')')
            {
                if (leftRemoved > 0)
                    leftRemoved--;
                else
                    rightRemoved++;
            }
        }

        solve(s, "", 0, leftRemoved, rightRemoved, 0, ans);

        return vector<string>(ans.begin(), ans.end());
    }

    void solve(string &s, string cur, int ind, int leftRemoved, int rightRemoved, int invalidPairs, unordered_set<string> &ans)
    {
        if (leftRemoved + rightRemoved > s.size() - ind)
            return;

        if (ind == s.size())
        {
            if (leftRemoved == 0 && rightRemoved == 0 && invalidPairs == 0)
                ans.insert(cur);
            return;
        }

        if (s[ind] != '(' && s[ind] != ')')
        {
            solve(s, cur + s[ind], ind + 1, leftRemoved, rightRemoved, invalidPairs, ans);
        }
        else
        {
            if (s[ind] == '(')
            {
                if (leftRemoved > 0)
                {
                    solve(s, cur, ind + 1, leftRemoved - 1, rightRemoved, invalidPairs, ans);
                }
                solve(s, cur + s[ind], ind + 1, leftRemoved, rightRemoved, invalidPairs + 1, ans);
            }
            else if (s[ind] == ')')
            {
                if (rightRemoved > 0)
                {
                    solve(s, cur, ind + 1, leftRemoved, rightRemoved - 1, invalidPairs, ans);
                }

                if (invalidPairs > 0)
                {
                    solve(s, cur + s[ind], ind + 1, leftRemoved, rightRemoved, invalidPairs - 1, ans);
                }
            }
        }
    }
};
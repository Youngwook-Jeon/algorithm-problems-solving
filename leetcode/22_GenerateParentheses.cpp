#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    unordered_map<char, int> mp;
    vector<string> ans;

    vector<string> generateParenthesis(int n)
    {
        mp['('] = n;
        mp[')'] = n;
        string s = "";
        backtrack(s, 2 * n);
        return ans;
    }

    void backtrack(string s, int total)
    {
        if (s.size() == total)
        {
            ans.push_back(s);
            return;
        }

        for (char c : "()")
        {
            if (c == ')' && mp['('] >= mp[')'])
                continue;

            if (mp[c] > 0)
            {
                mp[c]--;
                s.push_back(c);
                backtrack(s, total);
                s.pop_back();
                mp[c]++;
            }
        }
    }
};
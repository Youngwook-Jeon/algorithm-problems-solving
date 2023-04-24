#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> curVec;
        vector<vector<bool>> table(n, vector<bool>(n));
        backtrack(s, 0, ans, curVec, table);

        return ans;
    }

    void backtrack(string s, int l, vector<vector<string>> &ans, vector<string> &curVec, vector<vector<bool>> &table)
    {
        if (l >= s.size())
        {
            ans.push_back(curVec);
            return;
        }

        for (int e = l; e < s.size(); e++)
        {
            if (s[e] == s[l] && (l + 1 >= e - 1 || table[l + 1][e - 1]))
            {
                table[l][e] = true;

                curVec.push_back(s.substr(l, e - l + 1));
                backtrack(s, e + 1, ans, curVec, table);
                curVec.pop_back();
            }
        }
    }
};
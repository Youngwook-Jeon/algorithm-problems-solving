#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> ans;
    string mp[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return ans;

        string cur = "";
        backtrack(digits, cur);
        return ans;
    }

    void backtrack(string digits, string cur)
    {
        if (cur.size() == digits.size())
        {
            ans.push_back(cur);
            return;
        }

        int n = (int)digits[cur.size()] - '0';
        for (char c : mp[n])
        {
            cur.push_back(c);
            backtrack(digits, cur);
            cur.pop_back();
        }
    }
};
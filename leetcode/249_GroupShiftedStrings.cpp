#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    const char SEP = ',';

    vector<vector<string>> groupStrings(vector<string> &strings)
    {
        unordered_map<string, vector<string>> um;
        vector<vector<string>> ans;

        for (auto &str : strings)
        {
            um[convertToSeqForm(str)].push_back(str);
        }

        for (auto &[key, val] : um)
        {
            ans.push_back(val);
        }

        return ans;
    }

    string convertToSeqForm(string &s)
    {
        if (s.size() == 1)
            return "a";
        string res = "";
        for (int i = 1; i < s.size(); i++)
        {
            int diff = (s[i] - s[i - 1] >= 0) ? (s[i] - s[i - 1]) : (26 + s[i] - s[i - 1]);
            res.push_back(diff + 'a');
            res.push_back(SEP);
        }

        return res;
    }
};
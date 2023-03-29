#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    unordered_map<int, int> mp;

    int numDecodings(string s)
    {
        return solve(0, s);
    }

    int solve(int ind, string &s)
    {
        if (mp.find(ind) != mp.end())
            return mp[ind];

        if (ind == s.size())
            return 1;

        if (s[ind] == '0')
            return 0;

        if (ind == s.size() - 1)
            return 1;

        int cases = solve(ind + 1, s);
        if (stoi(s.substr(ind, 2)) <= 26)
        {
            cases += solve(ind + 2, s);
        }

        mp[ind] = cases;
        return cases;
    }
};
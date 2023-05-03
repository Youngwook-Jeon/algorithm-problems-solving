#include <string>
using namespace std;

class Solution
{
public:
    bool isOneEditDistance(string s, string t)
    {
        int m = s.size(), n = t.size();

        if (m >= n + 2 || n >= m + 2)
            return false;

        if (m > n)
            return solve(t, s);
        return solve(s, t);
    }

    bool solve(string &s, string &t)
    {
        int m = s.size(), n = t.size();

        for (int i = 0; i < m; i++)
        {
            if (s[i] != t[i])
            {
                if (m == n)
                    return s.substr(i + 1) == t.substr(i + 1);
                return s.substr(i) == t.substr(i + 1);
            }
        }

        return (m == n) ? false : true;
    }
};
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.size(), m = t.size();
        unordered_map<char, int> target;

        for (int i = 0; i < m; i++)
        {
            target[t[i]] += 1;
        }

        int required = target.size();
        unordered_map<char, int> window;
        int l = 0, h = 0;
        int match = 0;
        int ans[3] = {0, 0, 0}; // (window length, left index, right index)

        while (h < n)
        {
            char c = s[h];
            window[c] += 1;

            if (target.find(c) != target.end() && window[c] == target[c])
            {
                match++;
            }

            while (l <= h && match == required)
            {
                char d = s[l];
                if (ans[0] == 0 || h - l + 1 < ans[0])
                {
                    ans[0] = h - l + 1;
                    ans[1] = l;
                    ans[2] = h;
                }

                window[d] -= 1;
                if (target.find(d) != target.end() && window[d] < target[d])
                {
                    match--;
                }
                l++;
            }
            h++;
        }

        return s.substr(ans[1], ans[0]);
    }
};
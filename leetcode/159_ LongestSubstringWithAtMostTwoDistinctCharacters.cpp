#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstringTwoDistinct(string s)
    {
        int i = 0, j = 0;
        int n = s.size();
        int ans = 0;
        unordered_map<char, int> mp;

        while (j < n)
        {
            char c = s[j];
            if (i == j || mp.size() <= 1 || (mp.size() == 2 && mp.find(c) != mp.end()))
            {
                mp[c] += 1;
                j++;
            }
            else
            {
                ans = max(ans, j - i);
                mp[s[i]] -= 1;
                if (mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }
        }

        ans = max(ans, j - i);
        return ans;
    }
};
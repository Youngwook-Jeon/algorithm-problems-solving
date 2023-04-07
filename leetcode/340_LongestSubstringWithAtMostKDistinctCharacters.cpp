#include <string>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
        int ans = 0, n = s.size();
        int i = 0, j = 0;
        unordered_map<char, int> mp;

        while (j < n)
        {
            char c = s[j];
            mp[c] = j;
            j++;

            if (mp.size() > k)
            {
                int leftMost = INT_MAX;
                for (auto &[prev, ind] : mp)
                {
                    leftMost = min(ind, leftMost);
                }
                mp.erase(s[leftMost]);
                i = leftMost + 1;
            }
            ans = max(ans, j - i);
        }

        return ans;
    }
};
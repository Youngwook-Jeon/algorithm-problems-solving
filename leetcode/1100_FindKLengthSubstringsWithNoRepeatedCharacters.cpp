#include <string>
#include <unordered_map>
#include <list>
using namespace std;

class Solution
{
public:
    int numKLenSubstrNoRepeatsV1(string s, int k)
    {
        if (s.size() < k)
            return 0;
        unordered_map<char, list<int>> um;
        int ans = 0;
        for (int i = 0; i < k; i++)
        {
            um[s[i]].push_back(i);
        }
        if (um.size() == k)
            ans = 1;

        for (int i = 1; i <= s.size() - k; i++)
        {
            um[s[i - 1]].pop_front();
            if (um[s[i - 1]].size() == 0)
                um.erase(s[i - 1]);
            um[s[i + k - 1]].push_back(i + k - 1);
            if (um.size() == k)
                ans += 1;
        }

        return ans;
    }

    int numKLenSubstrNoRepeatsV2(string s, int k)
    {
        int l = 0, h = 0, ans = 0;
        int freq[26]{0};

        while (h < s.size())
        {
            freq[s[h] - 'a']++;

            while (freq[s[h] - 'a'] > 1)
            {
                freq[s[l] - 'a']--;
                l++;
            }

            if (h - l + 1 == k)
            {
                ans++;
                freq[s[l] - 'a']--;
                l++;
            }
            h++;
        }

        return ans;
    }
};
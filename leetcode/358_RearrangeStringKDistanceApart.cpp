#include <string>
#include <queue>
using namespace std;

class Solution
{
public:
    string rearrangeString(string s, int k)
    {
        int freq[26]{0};
        string ans;
        priority_queue<pair<int, int>> available;
        queue<pair<int, int>> unavailable;

        for (int i = 0; i < s.size(); i++)
        {
            freq[s[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > 0)
            {
                available.push({freq[i], i});
            }
        }

        int ind = 0;
        while (ans.size() != s.size())
        {
            ind = ans.size();
            if (!unavailable.empty() && (ind - unavailable.front().first) >= k)
            {
                auto p = unavailable.front();
                unavailable.pop();
                available.push({freq[p.second], p.second});
            }

            if (available.empty())
                return "";

            int c = available.top().second;
            available.pop();
            ans += c + 'a';

            freq[c]--;
            if (freq[c] > 0)
                unavailable.push({ind, c});
        }

        return ans;
    }
};
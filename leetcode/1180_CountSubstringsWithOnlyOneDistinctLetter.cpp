#include <string>
using namespace std;

class Solution
{
public:
    int countLetters(string s)
    {
        int ans = 0;
        int i = 0, cnt = 0;
        char cur = s[0];
        while (i < s.size())
        {
            if (s[i] == cur)
                cnt++;
            else
            {
                ans += cnt * (cnt + 1) / 2;
                cur = s[i];
                cnt = 1;
            }
            i++;
        }
        ans += cnt * (cnt + 1) / 2;

        return ans;
    }
};
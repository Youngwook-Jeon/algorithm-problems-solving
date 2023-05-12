#include <string>
using namespace std;

class Solution
{
public:
    bool canPermutePalindrome(string s)
    {
        int freq[26]{0};
        for (int i = 0; i < s.size(); i++)
        {
            freq[s[i] - 'a']++;
        }

        bool flag = false;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] % 2 == 1)
            {
                if (flag)
                    return false;
                flag = true;
            }
        }

        return true;
    }
};
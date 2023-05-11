#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void reverseWords(vector<char> &s)
    {
        reverse(s.begin(), s.end());
        int prev = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                reverse(s.begin() + prev, s.begin() + i);
                prev = i + 1;
            }
        }
        reverse(s.begin() + prev, s.end());
    }
};
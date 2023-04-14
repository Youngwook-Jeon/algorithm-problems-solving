#include <string>
using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        int pos = 0;
        return solve(s, pos);
    }

    string solve(string &s, int &pos)
    {
        int n = s.size();
        string ans;

        while (pos < n && s[pos] != ']')
        {
            if (!isdigit(s[pos]))
            {
                ans += s[pos];
                pos++;
            }
            else
            {
                int repeated = 0;
                while (pos < n && isdigit(s[pos]))
                {
                    repeated = repeated * 10 + (s[pos] - '0');
                    pos++;
                }
                pos++; // Ignore '['

                string partial = solve(s, pos);

                pos++; // Ignore ']'
                for (int i = 0; i < repeated; i++)
                {
                    ans += partial;
                }
            }
        }

        return ans;
    }
};
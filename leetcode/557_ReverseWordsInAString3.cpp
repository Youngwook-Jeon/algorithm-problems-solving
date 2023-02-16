#include <sstream>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        istringstream iss(s);
        string buffer;
        string ret;

        while (getline(iss, buffer, ' '))
        {
            ret += (reverseAWord(buffer) + ' ');
        }
        ret.pop_back();

        return ret;
    }

    string reverseAWord(string s)
    {
        for (int i = 0; i < s.size() / 2; i++)
        {
            swap(s[i], s[s.size() - i - 1]);
        }
        return s;
    }
};
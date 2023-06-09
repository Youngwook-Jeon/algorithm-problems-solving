#include <vector>
using namespace std;

class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        bool freq[26] = {false};
        for (auto c : letters)
        {
            freq[c - 'a'] = true;
        }

        int startInd = target - 'a';
        for (int i = startInd + 1; i < 26; i++)
        {
            if (freq[i])
                return (i + 'a');
        }

        return letters[0];
    }
};
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int calculateTime(string keyboard, string word)
    {
        unordered_map<char, int> um;
        for (int i = 0; i < keyboard.size(); i++)
        {
            um[keyboard[i]] = i;
        }

        int prev = 0;
        int ans = 0;
        for (int i = 0; i < word.size(); i++)
        {
            ans += abs(um[word[i]] - prev);
            prev = um[word[i]];
        }

        return ans;
    }
};
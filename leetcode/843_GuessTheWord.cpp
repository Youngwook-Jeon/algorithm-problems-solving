#include <string>
#include <vector>
using namespace std;

class Master
{
public:
    int guess(string word);
};

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution
{
public:
    int nMatches(string &s1, string &s2)
    {
        int res = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] == s2[i])
                res++;
        }

        return res;
    }

    void findSecretWord(vector<string> &words, Master &master)
    {
        for (int i = 0, matches = 0; i < 30 && matches != 6; i++)
        {
            string target = words[words.size() / 2];
            matches = master.guess(target);
            vector<string> next;
            for (auto &word : words)
            {
                if (nMatches(word, target) == matches)
                    next.push_back(word);
            }

            words = next;
        }
    }
};
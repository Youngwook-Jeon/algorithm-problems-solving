#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool areSentencesSimilar(vector<string> &sentence1, vector<string> &sentence2, vector<vector<string>> &similarPairs)
    {
        int m = sentence1.size(), n = sentence2.size();
        if (m != n)
            return false;

        unordered_map<string, unordered_set<string>> dicts;
        for (auto &pair : similarPairs)
        {
            dicts[pair[0]].insert(pair[1]);
            dicts[pair[1]].insert(pair[0]);
        }

        for (int i = 0; i < sentence1.size(); i++)
        {
            if (sentence1[i] == sentence2[i])
                continue;

            if (dicts[sentence1[i]].find(sentence2[i]) != dicts[sentence1[i]].end())
                continue;

            return false;
        }

        return true;
    }
};
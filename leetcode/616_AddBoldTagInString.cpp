#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBoldTag(string s, vector<string>& words) {
        vector<pair<int, int>> matchedRanges = findPairs(s, words);
        matchedRanges = merge(matchedRanges);

        for (auto it = matchedRanges.rbegin(); it != matchedRanges.rend(); it++) {
            s.insert(it->second, "</b>");
            s.insert(it->first, "<b>");
        }

        return s;
    }

    vector<pair<int, int>> findPairs(string s, vector<string>& words) {
        vector<pair<int, int>> ans;
        for (auto& word : words) {
            int sz = word.size();
            for (int i = 0; (i = s.find(word, i)) != string::npos; i++) {
                ans.push_back({i, i + sz});
            }
        }

        return ans;
    }

    vector<pair<int, int>> merge(vector<pair<int, int>>& matchedRanges) {
        sort(matchedRanges.begin(), matchedRanges.end(), cmp);
        vector<pair<int, int>> ans;

        for (int i = 0, j = -1; i < matchedRanges.size(); i++) {
            if (j < 0 || matchedRanges[i].first > ans[j].second) {
                ans.push_back(matchedRanges[i]);
                j++;
            } else {
                ans[j].second = max(ans[j].second, matchedRanges[i].second);
            }
        }

        return ans;
    }

    static bool cmp(pair<int, int>& x, pair<int, int>& y) {
        return x.first < y.first || (x.first == y.first && x.second < y.second);
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string s) {
        unordered_map<char, int> um;
        int maxLength = 1;
        for (int i = 0; i < s.size(); ++i) {
            if (um.find(s[i]) == um.end()) {
                um[s[i]] = maxLength;
            } else {
                um[s[i]] = max(um[s[i]], maxLength);
            }

            if (i < s.size() - 1 && isNext(s[i], s[i + 1])) {
                maxLength++;
            } else {
                maxLength = 1;
            }
        }

        int ans = 0;
        for (const pair<char, int>& entry : um) {
            ans += entry.second;
        }

        return ans;
    }

    bool isNext(char a, char b) {
        if (a == 'z') return b == 'a';
        return a + 1 == b;
    }
};
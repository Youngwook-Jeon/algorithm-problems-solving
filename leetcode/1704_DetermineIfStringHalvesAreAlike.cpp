#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    unordered_set<char> us;

    bool halvesAreAlike(string s) {
        us = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        if (countVowels(s, 0, s.size()/2 - 1) == countVowels(s, s.size()/2, s.size() - 1)) return true;
        return false;
    }

    int countVowels(const string& s, int start, int end) {
        int ans = 0;
        for (int i = start; i <= end; i++) {
            if (us.find(s[i]) != us.end()) ans++;
        }

        return ans;
    }
};
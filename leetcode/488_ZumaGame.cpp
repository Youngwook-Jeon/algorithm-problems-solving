#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinStep(string board, string hand) {
        vector<int> freq(26, 0);
        for (int i = 0; i < hand.size(); ++i) {
            freq[hand[i] - 'A']++;
        }
        unordered_map<string, int> cache;
        return solve(board, freq, cache);
    }

    int solve(string b, vector<int>& freq, unordered_map<string, int>& cache) {
        string key = b + "#" + serialize(freq);
        if (cache.count(key)) return cache[key];
        int ans = INT_MAX;
        if (b.size() == 0) {
            ans = 0;
        } else {
            for (int i = 0; i < b.size(); ++i) {
                for (int j = 0; j < freq.size(); ++j) {
                    bool worthTrying = false;
                    if (b[i] - 'A' == j) worthTrying = true;
                    else if (i > 0 && b[i] == b[i - 1] && b[i] - 'A' != j) worthTrying = true;

                    if (worthTrying && freq[j]) {
                        b.insert(b.begin() + i, j + 'A');
                        freq[j]--;
                        string updated = removeConsecutives(b);
                        int steps = solve(updated, freq, cache);
                        if (steps != -1) {
                            ans = min(ans, steps + 1);
                        }
                        freq[j]++;
                        b.erase(b.begin() + i);
                    }
                }
            }
        }

        if (ans == INT_MAX) ans = -1;
        cache[key] = ans;
        return ans;
    }

    string removeConsecutives(string b) {
        int start = 0;
        int end = 0;
        while (start < b.size()) {
            while (end < b.size() && b[start] == b[end]) end++;
            if (end - start >= 3) {
                return removeConsecutives(b.substr(0, start) + b.substr(end));
            }
            start = end;
        }

        return b;
    }

    string serialize(vector<int> freq) {
        string ans = "";
        for (int i = 0; i < freq.size(); ++i) {
            if (freq[i]) ans += to_string((char)i + 'A') + to_string(freq[i]);
        }

        return ans;
    }
};
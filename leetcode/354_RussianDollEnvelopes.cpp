#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool comp(vector<int>& v1, vector<int>& v2) {
        if (v1[0] == v2[0]) return v1[1] > v2[1];
        return v1[0] < v2[0];
    }


    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> lis;
        for (int i = 0; i < envelopes.size(); ++i) {
            auto it = lower_bound(lis.begin(), lis.end(), envelopes[i][1]);
            if (it == lis.end()) {
                lis.push_back(envelopes[i][1]);
            } else {
                *it = envelopes[i][1];
            }
        }

        return lis.size();
    }
};
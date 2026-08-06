#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0;
        for (int i = 0; i < timeSeries.size(); ++i) {
            int start = timeSeries[i];
            int end = start + duration - 1;
            if (i == timeSeries.size() - 1) {
                ans += (end - start + 1);
            } else {
                int nextS = timeSeries[i + 1];
                int minus = 0;
                if (end >= nextS) {
                    minus = end - nextS + 1;
                }
                ans += (end - start + 1 - minus); 
            }
        }

        return ans;
    }
};
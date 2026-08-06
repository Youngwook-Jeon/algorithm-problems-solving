#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestNumber(int n, int t) {
        int ans = 0;
        for (int i = n; i <= 100; ++i) {
            int x = i;
            int prod = 1;
            while (x) {
                prod *= (x % 10);
                x /= 10;
            }
            if (prod % t == 0) {
                return ans = i;
            }
        }
        return ans;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countArrangement(int n) {
        vector<bool> visited(n + 1);
        int res = 0;
        backtrack(n, 1, visited, res);

        return res;
    }

    void backtrack(int n, int pos, vector<bool>& visited, int &res) {
        if (pos > n) {
            res++;
            return;
        }

        for (int i = 1; i <= n; ++i) {
            if (!visited[i] && ((pos % i == 0) || (i % pos == 0))) {
                visited[i] = true;
                backtrack(n, pos + 1, visited, res);
                visited[i] = false;
            }
        }
    }
};
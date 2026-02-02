#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> memo(m, vector<int>(n));
        int dc[4] = {0, 1, 0, -1};
        int dr[4] = {-1, 0, 1, 0};
        
        for (int k = 1; k <= maxMove; ++k) {
            vector<vector<int>> temp(m, vector<int>(n));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {  
                    int paths = 0;
                    for (int t = 0; t < 4; ++t) {
                        int nextR = i + dr[t];
                        int nextC = j + dc[t];
                        if (nextR < 0 || nextC < 0 || nextR >= m || nextC >= n) {
                            paths++;
                            continue;
                        }
                        paths = (paths + memo[nextR][nextC]) % MOD;
                    }
                    temp[i][j] = paths;
                }
            }
            memo = temp;
        }

        return memo[startRow][startColumn];
    }
};
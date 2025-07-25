#include <iostream>
#include <string>
#include <vector>
#include <map>
typedef long long ll;

using namespace std;

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        // {s2_idx: (s1_count, s2_count)}
        map<int, pair<int, int>> recall;
        int s2_idx = 0;
        int s2_count = 0;
        for (int s1_count = 1; s1_count <= n1; ++s1_count) {
            // s1 한 덩어리 스캔
            for (char c : s1) {
                if (c == s2[s2_idx]) s2_idx++;
                if (s2_idx == s2.size()) {
                    s2_count++;
                    s2_idx = 0;
                }
            }

            // 주기 발견
            if (recall.count(s2_idx)) {
                auto [prev_s1_count, prev_s2_count] = recall[s2_idx];
                int cycle_s1_blocks = s1_count - prev_s1_count;
                int cycle_s2_count = s2_count - prev_s2_count;

                int remaining_s1_blocks = n1 - s1_count;
                int num_cycles = remaining_s1_blocks / cycle_s1_blocks;

                // 접두사 + 현재 + 주기들에서의 s2의 반복도 계산
                ll total_s2_count = s2_count + (ll)num_cycles * cycle_s2_count; 

                // 접미사는 별도로 다시 계산
                int suffix_s1_blocks = remaining_s1_blocks % cycle_s1_blocks;
                for (int i = 0; i < suffix_s1_blocks; ++i) {
                    for (char c : s1) {
                        if (c == s2[s2_idx]) s2_idx++;
                        if (s2_idx == s2.size()) {
                            total_s2_count++;
                            s2_idx = 0;
                        }
                    }
                }

                return total_s2_count / n2;
            } else {
                recall[s2_idx] = {s1_count, s2_count};
            }
        }

        return s2_count / n2;
    }
};
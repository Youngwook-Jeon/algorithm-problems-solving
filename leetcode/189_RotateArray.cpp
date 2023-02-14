#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        k = k % n;

        for (int start = 0; cnt < n; start++) {
            int current = start;
            do {
                int next = (current + k) % n;
                swap(nums[next], nums[start]);
                current = next;
                cnt++;
            } while (start != current);
        }
    }
};
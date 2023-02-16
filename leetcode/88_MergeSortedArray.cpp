#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int tail1 = m - 1, tail2 = n - 1, current = m + n - 1;
        while (tail1 >= 0 && tail2 >= 0) {
            nums1[current--] = (nums1[tail1] >= nums2[tail2]) ? nums1[tail1--] : nums2[tail2--];
        }

        while (tail2 >= 0) {
            nums1[current--] = nums2[tail2--];
        }
    }
};
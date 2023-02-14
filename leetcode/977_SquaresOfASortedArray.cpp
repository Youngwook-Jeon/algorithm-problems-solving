#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> ret(n);
        int left = 0;
        int right = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (abs(nums[left]) < abs(nums[right])) {
                ret[i] = nums[right];
                right--;
            } else {
                ret[i] = nums[left];
                left++;
            }
            ret[i] *= ret[i];
        }
        
        return ret;
    }
};
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {

public:
    int arr[100000];
    int ret;

    // Dynamic Programming
    int maxSubArray(vector<int>& nums) {
        ret = nums[0];
        arr[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int val1 = nums[i];
            int val2 = arr[i - 1];

            arr[i] = max(val1, val2 + nums[i]);
            ret = max(ret, arr[i]);
        }

        return ret;
    }

    // Divide and Conquer
    int maxSubArray2(vector<int>& nums) {
        return solve(0, nums.size() - 1, nums);
    }

    int solve(int start, int end, vector<int>& nums) {
        if (start > end) return INT_MIN;

        int mid = start + (end - start) / 2;
        int curr = 0;
        int bestLeftSum = 0;

        for (int i = mid - 1; i >= start; i--) {
            curr += nums[i];
            bestLeftSum = max(bestLeftSum, curr);
        }

        curr = 0;
        int bestRightSum = 0;
        for (int i = mid + 1; i <= end; i++) {
            curr += nums[i];
            bestRightSum = max(bestRightSum, curr);
        }

        int bestSideSum = bestLeftSum + bestRightSum + nums[mid];

        return max(bestSideSum, max(solve(start, mid - 1, nums), solve(mid + 1, end, nums)));
    }
};

int main() {
    // [-2,1,-3,4,-1,2,1,-5,4]
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution s;
    cout << s.maxSubArray(nums) << '\n'; // 6
    cout << s.maxSubArray2(nums) << '\n'; // 6
    return 0;
}
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret(2);
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(target - nums[i]) != mp.end()) {
                ret[0] = i;
                ret[1] = mp[target - nums[i]];
                break;
            }
            mp[nums[i]] = i;
        }

        return ret;
    }
};
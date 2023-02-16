class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ret;
        unordered_map<int, int> mp;
        for (int num : nums2)
        {
            mp[num] += 1;
        }

        for (int num : nums1)
        {
            if (mp[num] > 0)
            {
                ret.push_back(num);
                mp[num] -= 1;
            }
        }

        return ret;
    }
};
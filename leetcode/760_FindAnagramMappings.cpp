#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> anagramMappings(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, vector<int>> mp;
        vector<int> ans;
        for (int i = 0; i < nums2.size(); i++)
        {
            mp[nums2[i]].push_back(i);
        }

        for (int num : nums1)
        {
            int i = mp[num].back();
            mp[num].pop_back();
            ans.push_back(i);
        }

        return ans;
    }
};
#include <map>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution
{
public:
    map<int, int> freq;
    vector<int> unique;

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        for (int num : nums)
        {
            freq[num] += 1;
        }

        for (auto &[num, val] : freq)
        {
            unique.push_back(num);
        }

        int n = unique.size();

        quickselect(0, n - 1, n - k);

        vector<int> ans(k);
        copy(unique.begin() + n - k, unique.end(), ans.begin());

        return ans;
    }

    void quickselect(int left, int right, int kSmallest)
    {
        if (left == right)
            return;

        int pivot = left + rand() % (right - left + 1);
        pivot = partition(left, right, pivot);

        if (kSmallest == pivot)
            return;
        else if (kSmallest < pivot)
        {
            quickselect(left, pivot - 1, kSmallest);
        }
        else
        {
            quickselect(pivot + 1, right, kSmallest);
        }
    }

    int partition(int left, int right, int target)
    {
        int targetFreq = freq[unique[target]];
        swap(unique[target], unique[right]);

        int ind = left;
        for (int i = left; i <= right; i++)
        {
            if (freq[unique[i]] < targetFreq)
            {
                swap(unique[i], unique[ind]);
                ind++;
            }
        }

        swap(unique[right], unique[ind]);
        return ind;
    }
};
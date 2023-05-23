#include <queue>
#include <functional>
#include <vector>
using namespace std;

class KthLargest
{
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;

    KthLargest(int k, vector<int> &nums) : k(k)
    {
        for (auto num : nums)
        {
            pq.push(num);
        }

        while (pq.size() > k)
            pq.pop();
    }

    int add(int val)
    {
        pq.push(val);
        if (pq.size() > k)
            pq.pop();

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
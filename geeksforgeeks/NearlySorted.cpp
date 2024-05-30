#include <vector>
#include <queue>
using namespace std;

class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int K){
        // Your code here
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0;
        int cK = K;
        while (cK-- && i < num) {
            pq.push(arr[i]);
            i++;
        }
        
        for (int i = 0; i < num; i++) {
            if (i + K < num) {
                pq.push(arr[i + K]);
            }
            int mn = pq.top();
            pq.pop();
            ans.push_back(mn);
        }
        
        return ans;
    }
};
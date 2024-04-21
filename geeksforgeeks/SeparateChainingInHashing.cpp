#include <vector>
using namespace std;

class Solution
{
public:
    // Complete this function
    // Function to insert elements of array in the hashTable avoiding collisions.
    vector<vector<int>> separateChaining(int hashSize, int arr[], int sizeOfArray)
    {
        // Your code here
        vector<vector<int>> ans(hashSize);
        for (int i = 0; i < sizeOfArray; i++)
        {
            int key = (arr[i] % hashSize);
            ans[key].push_back(arr[i]);
        }

        return ans;
    }
};
#include <vector>
using namespace std;

class Solution
{
public:
    // Function to fill the array elements into a hash table
    // using Linear Probing to handle collisions.
    vector<int> linearProbing(int hashSize, int arr[], int sizeOfArray)
    {
        // Your code here
        vector<int> ans(hashSize, -1);
        for (int i = 0; i < sizeOfArray; i++)
        {
            int key = arr[i] % hashSize;
            int count = 0;
            if (ans[key] == -1)
            {
                ans[key] = arr[i];
            }
            else
            {
                while (ans[key] != -1 && count != hashSize)
                {
                    if (ans[key] == arr[i])
                        break;
                    key = (key + 1) % hashSize;
                    count++;
                }
                if (ans[key] == -1)
                    ans[key] = arr[i];
            }
        }

        return ans;
    }
};
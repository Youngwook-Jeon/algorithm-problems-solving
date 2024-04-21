#include <vector>
using namespace std;

class Solution
{
public:
    // Function to return list of integers visited in snake pattern in matrix.
    vector<int> snakePattern(vector<vector<int>> matrix)
    {
        // code here
        vector<int> ans;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (i % 2 == 0)
                {
                    ans.push_back(matrix[i][j]);
                }
                else
                {
                    ans.push_back(matrix[i][matrix[0].size() - j - 1]);
                }
            }
        }

        return ans;
    }
};
#include <vector>
#include <stack>
#include <climits>
using namespace std;

class Solution
{
public:
    bool verifyPreorder(vector<int> &preorder)
    {
        stack<int> st;
        int lower_bound = INT_MIN;

        for (int i = 0; i < preorder.size(); i++)
        {
            if (st.empty() || preorder[i] < preorder[i - 1])
            {
                if (preorder[i] <= lower_bound)
                    return false;
                st.push(preorder[i]);
            }
            else
            {
                while (!st.empty() && preorder[i] > st.top())
                {
                    lower_bound = st.top();
                    st.pop();
                }
                st.push(preorder[i]);
            }
        }

        return true;
    }
};
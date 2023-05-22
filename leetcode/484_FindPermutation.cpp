#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> findPermutation(string s)
    {
        int n = s.size();
        stack<int> st;
        vector<int> ans;
        for (int i = 1; i <= n; i++)
        {
            st.push(i);
            if (s[i - 1] == 'I')
            {
                while (!st.empty())
                {
                    int num = st.top();
                    st.pop();
                    ans.push_back(num);
                }
            }
        }

        st.push(n + 1);
        while (!st.empty())
        {
            int num = st.top();
            st.pop();
            ans.push_back(num);
        }

        return ans;
    }
};